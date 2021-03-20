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
