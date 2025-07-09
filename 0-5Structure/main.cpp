#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stddef.h>

struct Books
{
    char  title[50];
    char  author[50];
    char  subject[100];
    int   book_id;
} book;

struct __attribute__ ((__packed__)) student
{
    int a;
    char b;
    float c;
}std1;

struct  student2
{
    int a;
    char b;
    float c;
}std2;

struct __attribute__((aligned(8))) student3
{
    int a;
    char b;
    float c;
}std3;

#if 0 ///结构体声明
///此声明声明了拥有3个成员的结构体，分别为整型的a，字符型的b和双精度的c
///同时又声明了结构体变量s1
///这个结构体并没有标明其标签
struct
{
    int a;
    char b;
    double c;
} s1;


struct SIMPLE
{
    int a;
    char b;
    double c;
};
///用SIMPLE标签的结构体，另外声明了变量t1、t2、t3
struct SIMPLE t1, t2[20], *t3;

///也可以用typedef创建新类型
typedef struct
{
    int a;
    char b;
    double c;
} Simple2;
//现在可以用Simple2作为类型声明新的结构体变量
Simple2 u1, u2[20], *u3;
#endif

#if 0  ///结构体嵌套  ///此结构体的声明包含了其他的结构体
struct COMPLEX
{
    char string[100];
    struct SIMPLE a;
};

//此结构体的声明包含了指向自己类型的指针
struct NODE
{
    char string[100];
    struct NODE *next_node;
};
#endif

#if 0 ///结构作为函数参数
void printBook( struct Books book )
{
    printf( "Book title : %s\n", book.title);
    printf( "Book author : %s\n", book.author);
    printf( "Book subject : %s\n", book.subject);
    printf( "Book book_id : %d\n", book.book_id);
}

#endif




int main(void)
{
#if 0
    Books xhs;
    strcpy(xhs.title, "One-Tap");  // ? 正确使用
    strcpy(xhs.author, "David");
    strcpy(xhs.subject, "GO");
    xhs.book_id = 0;

    printf("sizeof(xhs)==%d",sizeof (xhs));
    printf("sizeof(std1)==%d",sizeof (std1));///边界对齐 4+4+4=12
#endif

#if 1   ///结构体大小  了解结构体的内存布局和对齐方式，
///可以使用 offsetof 宏和 __attribute__((packed)) 属性等进一步控制和查询结构体的大小和对齐方式。
    printf("结构体 book 大小为: %zu 字节\n", sizeof(book));
#endif

#if 0 ///offsetof

    //offsetof宏的使用 计算偏移量
    size_t ret1 = offsetof( struct Books,subject);
    printf("%zd\n", ret1);
    size_t ret2 = offsetof( struct Books,subject[1]);
    printf("%zd\n", ret2);

#endif

#if 1  ///__attribute__ ((__packed__))紧凑模式
    printf("结构体std1大小：%d\n",sizeof (std1)); ///4+1+4
    printf("结构体std2大小：%d\n",sizeof (std2));///4+4+4
    printf("结构体std3大小：%d\n",sizeof (std3));///8+8+8

#endif



#if 0 ///结构体相互嵌套

    ///如果两个结构体互相包含，则需要对其中一个结构体进行不完整声明，如下所示：
    struct B;    //对结构体B进行不完整声明

///结构体A中包含指向结构体B的指针
  typedef  struct A
    {
        struct B *partner;
        //other members;
    };

///结构体B中包含指向结构体A的指针，在A声明完后，B也随之进行声明
    typedef struct B
    {
        struct A *partner;
        int bb;
        //other members;
    };
  A VV;
  VV.partner->partner->partner->partner->partner->partner->partner->partner->partner->partner->partner->partner->partner->partner->partner->bb=12;

#endif



    return 0;
}