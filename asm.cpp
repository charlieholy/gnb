#include<stdio.h>

#define _mBeginASM      __asm__ __volatile__(
#define _mEndASM        );


int main(int argc,char* argv[]){
        int a=44,b=33,c;
 #if 1
        __asm__ __volatile__(
        "addl   %%ebx,%%eax "
        :"=a"(c)   //output
        :"b"(b),"a"(a) //input
        );
 #endif
        printf("%d\n",c);
        return 0;
}
///////////////////////
77
