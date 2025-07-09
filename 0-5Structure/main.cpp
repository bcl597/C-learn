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

#if 0 ///�ṹ������
///������������ӵ��3����Ա�Ľṹ�壬�ֱ�Ϊ���͵�a���ַ��͵�b��˫���ȵ�c
///ͬʱ�������˽ṹ�����s1
///����ṹ�岢û�б������ǩ
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
///��SIMPLE��ǩ�Ľṹ�壬���������˱���t1��t2��t3
struct SIMPLE t1, t2[20], *t3;

///Ҳ������typedef����������
typedef struct
{
    int a;
    char b;
    double c;
} Simple2;
//���ڿ�����Simple2��Ϊ���������µĽṹ�����
Simple2 u1, u2[20], *u3;
#endif

#if 0  ///�ṹ��Ƕ��  ///�˽ṹ������������������Ľṹ��
struct COMPLEX
{
    char string[100];
    struct SIMPLE a;
};

//�˽ṹ�������������ָ���Լ����͵�ָ��
struct NODE
{
    char string[100];
    struct NODE *next_node;
};
#endif

#if 0 ///�ṹ��Ϊ��������
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
    strcpy(xhs.title, "One-Tap");  // ? ��ȷʹ��
    strcpy(xhs.author, "David");
    strcpy(xhs.subject, "GO");
    xhs.book_id = 0;

    printf("sizeof(xhs)==%d",sizeof (xhs));
    printf("sizeof(std1)==%d",sizeof (std1));///�߽���� 4+4+4=12
#endif

#if 1   ///�ṹ���С  �˽�ṹ����ڴ沼�ֺͶ��뷽ʽ��
///����ʹ�� offsetof ��� __attribute__((packed)) ���ԵȽ�һ�����ƺͲ�ѯ�ṹ��Ĵ�С�Ͷ��뷽ʽ��
    printf("�ṹ�� book ��СΪ: %zu �ֽ�\n", sizeof(book));
#endif

#if 0 ///offsetof

    //offsetof���ʹ�� ����ƫ����
    size_t ret1 = offsetof( struct Books,subject);
    printf("%zd\n", ret1);
    size_t ret2 = offsetof( struct Books,subject[1]);
    printf("%zd\n", ret2);

#endif

#if 1  ///__attribute__ ((__packed__))����ģʽ
    printf("�ṹ��std1��С��%d\n",sizeof (std1)); ///4+1+4
    printf("�ṹ��std2��С��%d\n",sizeof (std2));///4+4+4
    printf("�ṹ��std3��С��%d\n",sizeof (std3));///8+8+8

#endif



#if 0 ///�ṹ���໥Ƕ��

    ///��������ṹ�廥�����������Ҫ������һ���ṹ����в�����������������ʾ��
    struct B;    //�Խṹ��B���в���������

///�ṹ��A�а���ָ��ṹ��B��ָ��
  typedef  struct A
    {
        struct B *partner;
        //other members;
    };

///�ṹ��B�а���ָ��ṹ��A��ָ�룬��A�������BҲ��֮��������
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