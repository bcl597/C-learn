#include <stdio.h>


#define  message_for(a, b) \
    printf(#a " and " #b ": We love you!\n")
///使用了 #a 和 #b 来把参数变成字符串字面量
///标记粘贴运算符（##）
///宏定义内的标记粘贴运算符（##）会合并两个参数。它允许在宏定义中两个独立的标记被合并为一个标记。例如：
#define tokenpaster(n) printf("token" #n " = %d", token##n)

#define MAX(x,y) ((x) > (y) ? (x) : (y))
int main()
{
#if 0 ///展示ANSI C标准中常用的预定义宏及其用途
    // 打印当前源文件名（字符串常量）
    printf("当前文件: %s\n", __FILE__);

    // 打印编译日期（"MMM DD YYYY"格式）
    printf("编译日期: %s\n", __DATE__);

    // 打印编译时间（"HH:MM:SS"格式）
    printf("编译时间: %s\n", __TIME__);

    // 打印当前行号（十进制整数）
    printf("当前行号: %d\n", __LINE__);

    // 检查是否符合ANSI/ISO标准（1表示符合）
    printf("ANSI标准: %d\n", __STDC__);

    // 实用示例：调试信息输出
    printf("\n[调试信息] %s (第%d行) 编译于 %s %s\n",
           __FILE__, __LINE__, __DATE__, __TIME__);
#endif


    ///宏延续运算符（\）
    message_for(Carole, Debra);

    int token34 = 40;

    tokenpaster(34);



    return 0;
}
