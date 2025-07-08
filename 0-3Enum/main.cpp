#include <stdio.h>

///enum　枚举名　{枚举元素1,枚举元素2,……};


int main(void)
{
    #if 0
    enum DAY
    {
        MON=1, TUE, WED, THU, FRI, SAT, SUN ///类似宏定义
    };
    ///第一个枚举成员的默认值为整型的 0，后续枚举成员的值在前一个成员上加 1。
    ///我们在这个实例中把第一个枚举成员的值定义为 1，第二个就为 2，以此类推。

    ///可以在定义枚举类型时改变枚举元素的值：
    enum season {spring, summer=3, autumn, winter};
    ///没有指定值的枚举元素，其值为前一元素加 1。也就说 spring 的值为 0，summer 的值为 3，autumn 的值为 4，winter 的值为 5

    #endif

    ///前面我们只是声明了枚举类型，接下来我们看看如何定义枚举变量。
    #if 1
    enum DAY      ///先定义枚举类型
    {
        MON=1, TUE, WED, THU, FRI, SAT, SUN
    };
    enum DAY day; ///再定义枚举变量
    #endif


    #if 0  ///定义枚举类型的同时定义枚举变量
    enum DAY
        {
            MON=1, TUE, WED, THU, FRI, SAT, SUN
        } day;
    #endif

#if 0 ///省略枚举名称，直接定义枚举变量
    enum
    {
        MON=1, TUE, WED, THU, FRI, SAT, SUN
    } day;
     // 遍历枚举元素
    for (day = MON; day <= SUN; day++) {
        printf("枚举元素：%d \n", day);
    }
#endif

#if 1        ///将整数转换为枚举
    enum day
    {
        saturday,
        sunday,
        monday,
        tuesday,
        wednesday,
        thursday,
        friday
    } workday;

    int a = 1;
    enum day weekend;
    weekend = ( enum day ) a;  //类型转换
    //weekend = a; //错误
    printf("weekend:%d",weekend);



#endif







    return 0;
}
