#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LENGTH(array) (sizeof(array) / sizeof(array[0]))

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]); // ������arr������ָ��ʹ��
    }
}



#if 0
///C �������������    ����������ʽ�Ľ����һ��

///��һ��
void myFunction1(int *param)///��ʽ������һ��ָ��
{
   ;
}

void myFunction2(int param[10])///��ʽ������һ���Ѷ����С�����飺
{
    ;
}

void myFunction3(int param[])///��ʽ������һ��δ�����С������
{
   ;
}
///C �������ʽ����ִ�б߽��顣
#endif




#if 0
///�Ӻ�����������  C ���Բ�������һ��������������Ϊ�����Ĳ��������ǿ���ͨ��ָ������������������������һ��ָ�������ָ��
int * getRandom(void)///���� 10 �������
{
    static int  r[10];
    int i;

    /* �������� */
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
        ///��ȡ���鳤��
        int array[] = {1, 2, 3, 4, 5};
        int length = sizeof(array) / sizeof(array[0]);
        length =LENGTH(array);
        printf("���鳤��Ϊ:sizeof(array) / sizeof(array[0])= %d/%d=%d\n",sizeof(array),sizeof(array[0]) ,length);
    ////��������ʾ����ĵ�ַ����������Ԫ�صĵ�ַ��
    ////������������һ������ָ��
        int *ptr = &array[0]; // ����ֱ��д�� int *ptr = myArray;
        printArray(array, 5); // �����������ݸ�����
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
    ///ָ�������ָ��
    double *p= nullptr;
    double balance[10];

    p = balance;
    for (int i = 0; i < 5; i++ )
    {
        printf("*(balance + %d) : %f\n",  i, *(balance + i) );
    }

#endif

#if 0   ///��̬�����붯̬����
        ///��̬���飺����ʱ�����ڴ棬��С�̶���
        ///��̬���飺����ʱ�ֶ������ڴ棬��С�ɱ䡣
        int staticArray1[5]; // ��̬��������
        int staticArray2[] = {1, 2, 3, 4, 5}; // ��̬������������ʼ��


        int size = 5;
        int *dynamicArray = (int *)malloc(size * sizeof(int)); // ��̬�����ڴ����
        /// ʹ�ö�̬����
        free(dynamicArray); // ��̬�����ڴ��ͷ�

#endif
        return 0;
    }