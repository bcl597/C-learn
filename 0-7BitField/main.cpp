#include <stdio.h>

///位域是一种特殊的结构体成员，允许我们按位对成员进行定义，指定其占用的位数。
///如果程序的结构中包含多个开关的变量，即变量值为 TRUE/FALSE，如下：
#define TURE 1
#define FALSE 0


struct
{
    unsigned int widthValidated;
    unsigned int heightValidated;
} status;
///这种结构需要 8 字节的内存空间，但在实际上，在每个变量中，我们只存储 0 或 1
///如果您在结构内使用这样的变量，您可以定义变量的宽度来告诉编译器，您将只使用这些字节。例如，上面的结构可以重写成：

struct
{
    unsigned int widthValidated : 1;
    unsigned int heightValidated : 1;
} status2;

///对齐问题
struct bs {
    int a:8;  // 占8位
    int b:2;  // 占2位
    int c:6;  // 占6位
} data;
///以上代码定义了一个名为 struct bs 的结构体，data 为 bs 的结构体变量，共占四个字节
/// 1.位域成员的类型
///你的结构体中，位域的基础类型是 int，在大多数平台上，int 是 4 字节（32位）。

///2.位域不能跨越基础类型边界
///这意味着所有位域成员会尝试存放在同一个 int（32位）里，只要空间够用。如果不够用，会开辟新的 4 字节空间来放。

///3.结构体大小必须是最大成员对齐的整数倍
///结构体在内存中，其总大小会按最大对齐单位对齐。


struct packed_struct {
    unsigned int f1 : 1;   // 1位的位域
    unsigned int f2 : 1;   // 1位的位域
    unsigned int f3 : 1;   // 1位的位域
    unsigned int f4 : 1;   // 1位的位域
    unsigned int type : 4; // 4位的位域
    unsigned int my_int : 9; // 9位的位域
};



int main(void)
{
    status2.heightValidated=1;
    status2.widthValidated=3;
    printf("%d %d \n",status2.heightValidated,status2.widthValidated);

    struct packed_struct pack;

    pack.f1 = 1;
    pack.f2 = 0;
    pack.f3 = 1;
    pack.f4 = 0;
    pack.type = 7;
    pack.my_int = 255;

    printf("f1: %u\n", pack.f1);
    printf("f2: %u\n", pack.f2);
    printf("f3: %u\n", pack.f3);
    printf("f4: %u\n", pack.f4);
    printf("type: %u\n", pack.type);
    printf("my_int: %u\n", pack.my_int);


    struct bs1{
        unsigned a:1;
        unsigned b:3;
        unsigned c:4;
    } bit,*pbit;
    bit.a=1;    /* 给位域赋值（应注意赋值不能超过该位域的允许范围） */
    bit.b=7;    /* 给位域赋值（应注意赋值不能超过该位域的允许范围） */
    bit.c=15;    /* 给位域赋值（应注意赋值不能超过该位域的允许范围） */
    printf("%d,%d,%d\n",bit.a,bit.b,bit.c);    /* 以整型量格式输出三个域的内容 */
    pbit=&bit;    /* 把位域变量 bit 的地址送给指针变量 pbit */
    pbit->a=0;    /* 用指针方式给位域 a 重新赋值，赋为 0 */
    pbit->b&=3;    /* 使用了复合的位运算符 "&="，相当于：pbit->b=pbit->b&3，位域 b 中原有值为 7，与 3 作按位与运算的结果为 3（111&011=011，十进制值为 3） */
    pbit->c|=1;    /* 使用了复合位运算符"|="，相当于：pbit->c=pbit->c|1，其结果为 15 */
    printf("%d,%d,%d\n",pbit->a,pbit->b,pbit->c);    /* 用指针方式输出了这三个域的值 */

    return 0;
}



typedef unsigned char BYTE;
