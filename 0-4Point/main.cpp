#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <malloc.h>


#if 1   ///����ָ�롢ָ�뺯��
    int fun1(int a,int b)
    {
        return  a+b;
    }
    ///ִ������������ָ�����͵ĺ�����
    int* fun2(int a,int b)
    {
///       int c=a+b;
///        int *p=&c;
///        return p;   ///c ��һ�� �ֲ�����
                    /// �����������ڽ��ں��� fun2 �ڣ�һ���������أ����ͱ�����
///       int *p=&(a+b);
///        return p;
///        return &(a+b);  ///�������һ�����Ƕ�һ�� ���ʽֵ��R-value�� ȡ��ַ������������Ϊ a + b ��ʱ����һ�������ռ䣬��ֻ��һ��˲���ֵ
        ///��ȷд����ʹ�þ�̬����ڴ�
        int *p = (int *)malloc(sizeof(int));///// �������һ�� int ��С���ڴ棬p ָ����
        *p = a + b;                                /// �� a+b �Ľ��д�����뵽���ڴ�
        return p;                                  /// ���ظ��ڴ��ַ��������
    }

///? ���� 2��ʹ�� static ��̬����

int fun3(int a, int b) {
    static int c;
    c = a + b;
    return c;
}

///��̬�����������ڹᴩ��������
///ȱ���ǣ������̰߳�ȫ����ε��ûḲ��

int (*pf)(int a,int b); ///ָ������ָ��

#endif



#if 1   ///ʵ���ַ���copy��compare

///void Copystr(char src ,char des)
///���Ǵ���ġ��㴫����� char ���ͣ������ַ�����������Ҫ������� �ַ�����char * ָ�룩��

void CopyStr(char *src ,char *des)
{
    ///while (src!=NULL)  �����������ԶΪ��ģ����� src == NULL����������Ҫ�������ж��ַ����Ƿ񵽽�β�����Ƿ�Ϊ '\0'����������ָ���Ƿ�Ϊ�ա�
    while (*src!='\0')
    *des++=*src++;
    *des = '\0';  // �����˿���������
}

///���߼�д��һ�� while ѭ����

void CopyStr2(char *src, char *des)
{
    while ((*des++ = *src++) != '\0');  // ���ø�ֵ���ʽ�ķ���ֵ
}

int CompareStr(char *str1, char *str2)
{
    while (*str1 && *str2) {
        if (*str1 != *str2) {
            return *str1 - *str2;  // ����ʱ���ز�ֵ
        }
        str1++;
        str2++;
    }
    return *str1 - *str2;  // ���ĳ���ַ�����ǰ����
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
#if 0 ///ָ���������
        int* pa= nullptr;
        int a=10,b=5;
        pa=&a;
        int *pb=&b;///����ֱ������ָ��
        printf("pa->%d\n",*pa);
        printf("pb->%d\n",*pb);
#endif

#if 0  ///����ָ��
        int**ppa= nullptr;
        int *pa= nullptr;
        int a=10;
        pa=&a;ppa=&pa;
    printf("paָ���˱���a\n");
    printf("����a�ĵ�ַ����pa��ֵ��pa=%p\n",pa);
    printf("ppaָ����ָ�����pa\n");
    printf("pa�ĵ�ַ����ppa��ֵ��ppa=%p\n",ppa);
    printf("ͨ��ppa�õ�pa��ֵ����Եõ�a���ڴ��ַ���Ӷ�����a\n");
    printf("a=**ppa=%d\n",**ppa);
    printf("a=*pa=%d\n",*pa);

#endif
#if 0 ///ָ������������ָ��
        ///ָ�����鶨��
        int a1=1,a2=2,a3=3;
        int* pa[3]={&a1,&a2,&a3}; ///pa�����飬Ԫ����int*����  ָ��������һ��ָ������Ԫ�ص����顣
        printf("pa[0]=%p->:%d\n",pa[0],*pa[0]);
        printf("pa[1]=%p->:%d\n",pa[1],*pa[1]);
        printf("pa[2]=%p->:%d\n",pa[2],*pa[2]);

        ///����ָ�붨��
        ///����ָ����һ��ָ�����������ָ�룬������ָ������ĵ�һ��Ԫ�ء�
        /// ��Ȼ����ָ���ָ��������Ԫ�ص�ָ������ֵ�Ͽ�����ͬ����ָ����ͬ���ڴ��ַ���������ǵ����ͺ�������Ϊ��ȫ��ͬ
        ///�������� (*����ָ����)[���鳤��];
        /// ������Ԫ�ص�����������ָ������
        int (*pb)[3];///pa��ָ�룬ָ����һ��int����
        int arb[3]={1,2,3};
        pb=&arb;
        printf("*pb=%d\n",**pb);
        printf("*pb=%d\n",*(*pb+1));
        printf("*pb=%d\n",*(*pb+2));
        ///��2   *pb��ʵ������arb   (*pb)[0] == arb[0]
        printf("%d\n", (*pb)[0]); // 10
        printf("%d\n", (*pb)[1]); // 20
        printf("%d\n", (*pb)[2]); // 30
        ///���� 3��ͨ����ʱ��int *q = *pb;  // *p �õ����� int[3]��������ʽת��Ϊ int*
    //        printf("%d\n", q[0]); // 10
    //        printf("%d\n", q[1]); // 20����


    ///����ָ�������
        ///��ָͨ�룺ptr + 1 �ƶ� sizeof(Ԫ������) �ֽڡ�
        int arr[5];
        int *p1 = arr;
        p1 + 1;  // �ƶ� 4 �ֽڣ����� int ռ 4 �ֽ�

        ///����ָ�룺ptr + 1 �ƶ� sizeof(��������) �ֽڡ�
        int (*p2)[5] = &arr;
        p2 + 1;  // �ƶ� 20 �ֽڣ�5 �� int��ÿ�� 4 �ֽڣ�

#endif
#if 0   ///ָ�뺯���뺯��ָ��
        ///����ָ�붨��
        pf=&fun3;  ///���� pf=fun3
        int x;
        x = (*pf)(1,2); ///���÷�ʽҲ������  x = pf();
        printf("X=%d\n",x);
#endif

#if 0   ///ָ�����ַ�����ʹ��
        char *a="its your choice!";///a ��һ�� ָ�� char ��ָ�룬ָ������ַ������׵�ַ
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
    ///ע����char *s1="apple" ������ �������ַ�������
    int result = CompareStr(s1, s2);
    if (result == 0)
        printf("�����ַ������\n");
    else if (result < 0)
        printf("s1 С�� s2\n");
    else
        printf("s1 ���� s2\n");

    LinkStr(s1,s2);
    printf("%s",s2);
#endif
#if 1   ///�ַ�����ָ��
    char *a;
    char b='c';
    a=&b;
    printf("%c\n",*a);
    *a='d';
    printf("%c\n",*a);

#endif



    return  0;



}
