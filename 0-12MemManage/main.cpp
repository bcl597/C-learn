#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <string.h>
///1   void *calloc(int num, int size);  contiguous allocation
///在内存中动态地分配 num 个长度为 size 的连续空间，并将每一个字节都初始化为 0。
///所以它的结果是分配了 num*size 个字节长度的内存空间，并且每个字节的值都是 0。

///2	void free(void *address);
///该函数释放 address 所指向的内存块,释放的是动态分配的内存空间。

///3	void *malloc(int num);   memory allocation
///在堆区分配一块指定大小的内存空间，用来存放数据。这块内存空间在函数执行完成后不会被初始化，它们的值是未知的。

///4	void *realloc(void *address, int newsize);
///该函数重新分配内存，把内存扩展到 newsize。



int main(void) {

    ///int *arr =(int *) malloc(40);
    ///🔥 为什么能“看起来没出错”？
    ///这是因为 C 语言并不保护你不去越界访问内存，如果你越界访问了未分配的区域，但那块内存碰巧还没有被系统分配给别的用途（或还在你进程的合法范围内），就可能：
    ///
    ///没有立即报错（如段错误）。
    ///
    ///输出了“似乎正常的值”，但这些值是垃圾值或残留数据。

    ///正确分配
    int *arr = (int *)malloc(40*sizeof (int)); // 分配10个int
    for (int i = 0; i < 40; ++i)
    {
        //arr[i]=i;
        printf("a[%d]=%d\n",i,*(arr+i));
    }
    free(arr);

    int *p = (int *)calloc(10,sizeof(int));//申请10个int类型空间-连续无间隔的
    for(int i = 0; i < 10; i++)
    {
        printf("p[%d] = %d\n", i, p[i]);//测试：没有初始化前试着打印申请的内存值
    }
    free(arr);//打印完后释放该内存


#if 1
    char name[100];
    char *description;

    strcpy(name, "Zara Ali");

    /* 动态分配内存 */
    description = (char *)malloc( 200 * sizeof(char) );
    if( description == NULL )
    {
        fprintf(stderr, "Error - unable to allocate required memory\n");
    }
    else
    {
        strcpy( description, "Zara ali a DPS student in class 10th");
    }
    printf("Name = %s\n", name );
    printf("Description: %s\n", description );



#endif


    return 0;
}
