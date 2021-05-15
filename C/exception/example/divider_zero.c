#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>

static jmp_buf env;

double divide(double a, double b){
    if(b == 0)
        longjmp(env,1);
    return a / b;
}

int main(int argc, char const *argv[])
{
    double res;
    if(setjmp(env) == 0)
        res = divide(3, 0);
    else
        printf("Divide by zero!\n");
    return 0;
}
