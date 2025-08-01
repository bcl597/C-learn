#include <stdio.h>
#include <stdarg.h>


///有时，您可能会碰到这样的情况，您希望函数带有可变数量的参数，而不是预定义数量的参数。

///C 语言为这种情况提供了一个解决方案，它允许您定义一个函数，能根据具体的需求接受可变数量的参数。

///声明方式为：int func_name(int arg1, ...);

/*
请注意，函数 func() 最后一个参数写成省略号，即三个点号（...），省略号之前的那个参数是 int，代表了要传递的可变参数的总数。
为了使用这个功能，您需要使用 stdarg.h 头文件，该文件提供了实现可变参数功能的函数和宏。具体步骤如下：
定义一个函数，最后一个参数为省略号，省略号前面可以设置自定义参数。
在函数定义中创建一个 va_list 类型变量，该类型是在 stdarg.h 头文件中定义的。
使用 int 参数和 va_start() 宏来初始化 va_list 变量为一个参数列表。宏 va_start() 是在 stdarg.h 头文件中定义的。
使用 va_arg() 宏和 va_list 变量来访问参数列表中的每个项。
使用宏 va_end() 来清理赋予 va_list 变量的内存。

 常用的宏有：
va_start(ap, last_arg)：初始化可变参数列表。ap 是一个 va_list 类型的变量，last_arg 是最后一个固定参数的名称（也就是可变参数列表之前的参数）。该宏将 ap 指向可变参数列表中的第一个参数。
va_arg(ap, type)：获取可变参数列表中的下一个参数。ap 是一个 va_list 类型的变量，type 是下一个参数的类型。该宏返回类型为 type 的值，并将 ap 指向下一个参数。
va_end(ap)：结束可变参数列表的访问。ap 是一个 va_list 类型的变量。该宏将 ap 置为 NULL。


*/
///现在让我们按照上面的步骤，来编写一个带有可变数量参数的函数，并返回它们的平均值：
int fun1(int num,...)
{
    va_list valist;
    double  sum=0;
    int i;

    ///为 num 个参数初始化 valist
    va_start(valist, num);
    /* 访问所有赋给 valist 的参数 */
    for (i = 0; i < num; i++)
    {
        sum += va_arg(valist, int);
    }
    /* 清理为 valist 保留的内存 */
    va_end(valist);

    return sum/num;
}




int main(void)
{
    int avg;

    avg=fun1(2,2,3);
    printf("%d\n",avg);
    avg=fun1(3,2,3,4);
    printf("%d\n",avg);
    avg=fun1(1,5);
    printf("%d\n",avg);


    return 0;
}