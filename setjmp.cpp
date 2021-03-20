#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf env;

void fun()
{
    printf("fun() enter \n");
    longjmp(env, 1);
    printf("fun() exit \n");
}

int main()
{
    int ret = setjmp(env);
    printf("ret %d\n",ret);
    if (ret == 0)
    {
        printf("from setjmp \n");
        fun();
    }
    else
    {
        printf("from longjmp \n");
    }

    return 0;
}


///
ret 0
from setjmp
fun() enter
ret 1
from longjmp
///////////////////
RETURN VALUE
       setjmp() and sigsetjmp() return 0 if returning directly, and nonzero when returning from  longjmp(3)  or  sig‐
       longjmp(3) using the saved context.
    
    
    
    ///////////////////////////////////////
    .section .text

.globl csetjmp, clongjmp

csetjmp:
    movq %rbp, 0(%rdi)
    movq %rsp, 8(%rdi)
    movq 0(%rsp), %rdx
    movq %rdx, 16(%rdi)
    movq $0, %rax
    retq

clongjmp:
    movq 0(%rdi), %rbp
    movq 8(%rdi), %rsp
    movq 16(%rdi), %rdx
    movq %rdx, 0(%rsp)
    movq $1, %rax
    retq
    
////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 定义上下文内存区域，用于保存BP、SP、返回地址
// 在64位环境，寄存器名称为rbp、rsp、rip
struct context {
    unsigned long rbp;
    unsigned long rsp;
    unsigned long rip;
};

// 定义上下文数据，用于模拟多个协程
struct context ctEntry = {0};
struct context ctArray[2] = { {0}, {0} };
int ct_count = 2;
int ct_idx = -1;

// 保存当前函数现场，并切换到其它函数
void yield()
{
    if (csetjmp( &ctArray[ct_idx] ) == 0)
    {
        clongjmp(&ctEntry);
    }
}

// 协程函数1
void fun1()
{
    int number = 0;

    for (;;)
    {
        printf("fun1() %d \n", number++);
        sleep(1);

        yield();
    }
}

// 协程函数2
void fun2()
{
    int number = 0;
    for (;;)
    {
        printf("fun2() %d \n", number++);
        sleep(1);

        // 模拟协程退出，不再参与调度
        if (number == 3)
        {
            ct_count = 1;
        }

        yield();
    }
}

int main()
{
    // 创建协程1
    // 注意：这里创建了函数自己的堆栈区域
    ctArray[0].rbp = (unsigned long)((char*)malloc(4096) + 4000);
    ctArray[0].rsp = ctArray[0].rbp;
    ctArray[0].rip = (unsigned long)&fun1;
    *( (unsigned long*)(ctArray[0].rbp) ) = 0LL;

    // 创建协程2
    // 注意：这里创建了函数自己的堆栈区域
    ctArray[1].rbp = (unsigned long)((char*)malloc(4096) + 4000);
    ctArray[1].rsp = ctArray[1].rbp;
    ctArray[1].rip = (unsigned long)&fun2;
    *( (unsigned long*)(ctArray[1].rbp) ) = 0LL;

    // 保存调度现场
    int ret = csetjmp(&ctEntry);
    if (ret == 1)
    {
        // 调度协程
        ct_idx = (ct_idx + 1) % ct_count;
        clongjmp( &ctArray[ct_idx] );
    }

    // 启动调度
    clongjmp(&ctEntry);
    return 0;
}
////////////////////////////
test]$ as setjmp.s -o setjmp.o
test]$ gcc jmpcall.c setjmp.o


    
