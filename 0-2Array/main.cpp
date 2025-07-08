#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LENGTH(array) (sizeof(array) / sizeof(array[0]))

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]); // 数组名arr被当作指针使用
    }
}



#if 0
///C 传递数组给函数    三种声明方式的结果是一样

///第一种
void myFunction1(int *param)///形式参数是一个指针
{
   ;
}

void myFunction2(int param[10])///形式参数是一个已定义大小的数组：
{
    ;
}

void myFunction3(int param[])///形式参数是一个未定义大小的数组
{
   ;
}
///C 不会对形式参数执行边界检查。
#endif




#if 0
///从函数返回数组  C 语言不允许返回一个完整的数组作为函数的参数。但是可以通过指定不带索引的数组名来返回一个指向数组的指针
int * getRandom(void)///生成 10 个随机数
{
    static int  r[10];
    int i;

    /* 设置种子 */
    srand( (unsigned)time( NULL ) );
    for ( i = 0; i < 10; ++i)
    {
        r[i] = rand();
        printf( "r[%d] = %d\n", i, r[i]);

    }

    return r;
}


#endif



int main(void)
{
#if 0
        ///获取数组长度
        int array[] = {1, 2, 3, 4, 5};
        int length = sizeof(array) / sizeof(array[0]);
        length =LENGTH(array);
        printf("数组长度为:sizeof(array) / sizeof(array[0])= %d/%d=%d\n",sizeof(array),sizeof(array[0]) ,length);
    ////数组名表示数组的地址，即数组首元素的地址。
    ////数组名本身是一个常量指针
        int *ptr = &array[0]; // 或者直接写作 int *ptr = myArray;
        printArray(array, 5); // 将数组名传递给函数
#endif


#if 0
        int *p;
        int i;
        p = getRandom();
        for ( i = 0; i < 10; i++ )
        {
            printf( "*(p + %d) : %d\n", i, *(p + i));
        }
    ////printArray(p,10);
#endif




#if 0
    ///指向数组的指针
    double *p= nullptr;
    double balance[10];

    p = balance;
    for (int i = 0; i < 5; i++ )
    {
        printf("*(balance + %d) : %f\n",  i, *(balance + i) );
    }

#endif

#if 0   ///静态数组与动态数组
        ///静态数组：编译时分配内存，大小固定。
        ///动态数组：运行时手动分配内存，大小可变。
        int staticArray1[5]; // 静态数组声明
        int staticArray2[] = {1, 2, 3, 4, 5}; // 静态数组声明并初始化


        int size = 5;
        int *dynamicArray = (int *)malloc(size * sizeof(int)); // 动态数组内存分配
        /// 使用动态数组
        free(dynamicArray); // 动态数组内存释放

#endif
        return 0;
    }