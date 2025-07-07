#include "stdio.h"
#include "memory.h"
#include "string.h"

/*
C语言中的格式化输出符号有很多，以下是一些常见的：

%d 或 %i：用于输出十进制整数。
%u：用于输出无符号十进制整数。
%f：用于输出浮点数。
%s：用于输出字符串。
%c：用于输出字符。
%p：用于输出指针。
%x 或 %X：用于输出十六进制数，%x表示输出小写字母，%X表示输出大写字母。
%o：用于输出八进制数。
%e 或 %E：用于输出科学计数法表示的浮点数。
%g 或 %G：用于输出浮点数，但是没有无意义的零。
*/


int main()
{
    int a;
    unsigned int b;
    float  c;
    double d;
    long int  e;
    long long int f;
    unsigned  long int g;
    unsigned  long long int h;

    a=65;
    b=97;
    c=3.14159;
    d=3.1415926;
    e=12345678901;
    f=1234567890123;
    g=123123123123123;
    h=123132132132123132;

    printf("a=%d\n",a);
    printf("a=%i\n",a);
    printf("b=%d\n",b);
    printf("c=%f\n",c);
    printf("c=%.2f\n",c);
    printf("c=%9.3f\n",c);
    printf("c=%d\n",c);

    printf("c=%f\n");
    printf("d=\n");
    printf("e=\n");
    printf("f=\n");
    printf("g=\n");

    return 0;
}
