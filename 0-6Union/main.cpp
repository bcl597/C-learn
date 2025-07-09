#include <stdio.h>
#include <string.h>
#if 1
///相同的内存位置存储不同的数据类型
///可以定义一个带有多成员的共用体，但是任何时候只能有一个成员带有值
union Data
{
    int i;
    float f;
    char  str[20];
} data;


#endif

int main(void)
{

    printf( "Memory size occupied by data : %d\n", sizeof(data));

    data.i = 10;
    data.f = 220.5;
    strcpy( data.str, "C Programming");

    printf( "data.i : %d\n", data.i);
    printf( "data.f : %f\n", data.f);
    printf( "data.str : %s\n", data.str);
    ///我们可以看到共用体的 i 和 f 成员的值有损坏，因为最后赋给变量的值占用了内存位置

    data.i = 10;
    printf( "data.i : %d\n", data.i);

    data.f = 220.5;
    printf( "data.f : %f\n", data.f);

    strcpy( data.str, "C Programming");
    printf( "data.str : %s\n", data.str);


    return 0;
}
