#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>

#define TRY(c, a) if(setjmp(c) == 0) {a}
#define THROW(c, a)  longjmp(c, a) 

int main(int argc, char const *argv[])
{
    jmp_buf env;
    int i;

    i = setjmp(env);

    printf("i=%d\n",i);
    if(i!=0) exit(0);
    
    longjmp(env, 2);
    printf("never reached here!");


    return 0;
}
