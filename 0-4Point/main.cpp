#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <malloc.h>


#if 1   ///函数指针、指针函数
    int fun1(int a,int b)
    {
        return  a+b;
    }
    ///执政函数。返回指针类型的函数。
    int* fun2(int a,int b)
    {
///       int c=a+b;
///        int *p=&c;
///        return p;   ///c 是一个 局部变量
                    /// 它的生命周期仅在函数 fun2 内，一旦函数返回，它就被销毁
///       int *p=&(a+b);
///        return p;
///        return &(a+b);  ///这和上面一样，是对一个 表达式值（R-value） 取地址。编译器不会为 a + b 临时开辟一个变量空间，它只是一个瞬间的值
        ///正确写法：使用静态或堆内存
        int *p = (int *)malloc(sizeof(int));///// 向堆申请一个 int 大小的内存，p 指向它
        *p = a + b;                                /// 把 a+b 的结果写入申请到的内存
        return p;                                  /// 返回该内存地址给调用者
    }

///? 方法 2：使用 static 静态变量

int fun3(int a, int b) {
    static int c;
    c = a + b;
    return c;
}

///静态变量生命周期贯穿整个程序
///缺点是：不是线程安全，多次调用会覆盖

int (*pf)(int a,int b); ///指向函数的指针

#endif



#if 1   ///实现字符串copy与compare

///void Copystr(char src ,char des)
///这是错误的。你传入的是 char 类型（单个字符），而我们要处理的是 字符串（char * 指针）。

void CopyStr(char *src ,char *des)
{
    ///while (src!=NULL)  这个条件是永远为真的（除非 src == NULL），但我们要做的是判断字符串是否到结尾（即是否为 '\0'），而不是指针是否为空。
    while (*src!='\0')
    *des++=*src++;
    *des = '\0';  // 别忘了拷贝结束符
}

///或者简写成一行 while 循环：

void CopyStr2(char *src, char *des)
{
    while ((*des++ = *src++) != '\0');  // 利用赋值表达式的返回值
}

int CompareStr(char *str1, char *str2)
{
    while (*str1 && *str2) {
        if (*str1 != *str2) {
            return *str1 - *str2;  // 不等时返回差值
        }
        str1++;
        str2++;
    }
    return *str1 - *str2;  // 如果某个字符串提前结束
}

void LinkStr(char *src,char *des)
{
    while (*des!='\0')des++;
    while (*src!='\0')*des++=*src++;
    *des='\0';

}


#endif







int main(void)
{
#if 0 ///指针变量声明
        int* pa= nullptr;
        int a=10,b=5;
        pa=&a;
        int *pb=&b;///或者直接声明指向
        printf("pa->%d\n",*pa);
        printf("pb->%d\n",*pb);
#endif

#if 0  ///二级指针
        int**ppa= nullptr;
        int *pa= nullptr;
        int a=10;
        pa=&a;ppa=&pa;
    printf("pa指向了变量a\n");
    printf("变量a的地址就是pa的值即pa=%p\n",pa);
    printf("ppa指向了指针变量pa\n");
    printf("pa的地址就是ppa的值即ppa=%p\n",ppa);
    printf("通过ppa得到pa的值则可以得到a的内存地址，从而访问a\n");
    printf("a=**ppa=%d\n",**ppa);
    printf("a=*pa=%d\n",*pa);

#endif
#if 0 ///指针数组与数组指针
        ///指针数组定义
        int a1=1,a2=2,a3=3;
        int* pa[3]={&a1,&a2,&a3}; ///pa是数组，元素是int*类型  指针数组是一种指针类型元素的数组。
        printf("pa[0]=%p->:%d\n",pa[0],*pa[0]);
        printf("pa[1]=%p->:%d\n",pa[1],*pa[1]);
        printf("pa[2]=%p->:%d\n",pa[2],*pa[2]);

        ///数组指针定义
        ///数组指针是一个指向整个数组的指针，而不是指向数组的第一个元素。
        /// 虽然数组指针和指向数组首元素的指针在数值上可能相同（即指向相同的内存地址），但它们的类型和运算行为完全不同
        ///数据类型 (*数组指针名)[数组长度];
        /// 数组中元素的数量（必须指定）。
        int (*pb)[3];///pa是指针，指向了一个int数组
        int arb[3]={1,2,3};
        pb=&arb;
        printf("*pb=%d\n",**pb);
        printf("*pb=%d\n",*(*pb+1));
        printf("*pb=%d\n",*(*pb+2));
        ///法2   *pb其实就类似arb   (*pb)[0] == arb[0]
        printf("%d\n", (*pb)[0]); // 10
        printf("%d\n", (*pb)[1]); // 20
        printf("%d\n", (*pb)[2]); // 30
        ///方法 3：通过临时变int *q = *pb;  // *p 得到的是 int[3]，可以隐式转换为 int*
    //        printf("%d\n", q[0]); // 10
    //        printf("%d\n", q[1]); // 20量简化


    ///数组指针的运算
        ///普通指针：ptr + 1 移动 sizeof(元素类型) 字节。
        int arr[5];
        int *p1 = arr;
        p1 + 1;  // 移动 4 字节（假设 int 占 4 字节

        ///数组指针：ptr + 1 移动 sizeof(整个数组) 字节。
        int (*p2)[5] = &arr;
        p2 + 1;  // 移动 20 字节（5 个 int，每个 4 字节）

#endif
#if 0   ///指针函数与函数指针
        ///函数指针定义
        pf=&fun3;  ///或者 pf=fun3
        int x;
        x = (*pf)(1,2); ///调用方式也有两种  x = pf();
        printf("X=%d\n",x);
#endif

#if 0   ///指针与字符串的使用
        char *a="its your choice!";///a 是一个 指向 char 的指针，指向这个字符串的首地址
        printf("%s\n",a);
        ///a ---->  0x1000:  'i'
        ///         0x1001:  't'
        ///         0x1002:  's'
        ///         ...
        ///         0x1010:  '!'
        ///         0x1011:  '\0'
        for(int i = 0; i < 16; ++i)printf("%c",*(a+i));
#endif

#if 0
    char s1[] = "apple";
    char s2[] = "apricot";
    ///注意与char *s1="apple" 的区别 后者是字符串常量
    int result = CompareStr(s1, s2);
    if (result == 0)
        printf("两个字符串相等\n");
    else if (result < 0)
        printf("s1 小于 s2\n");
    else
        printf("s1 大于 s2\n");

    LinkStr(s1,s2);
    printf("%s",s2);
#endif
#if 1   ///字符变量指针
    char *a;
    char b='c';
    a=&b;
    printf("%c\n",*a);
    *a='d';
    printf("%c\n",*a);

#endif



    return  0;



}
