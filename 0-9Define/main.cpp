#include <stdio.h>


#define  message_for(a, b) \
    printf(#a " and " #b ": We love you!\n")
///ʹ���� #a �� #b ���Ѳ�������ַ���������
///���ճ���������##��
///�궨���ڵı��ճ���������##����ϲ������������������ں궨�������������ı�Ǳ��ϲ�Ϊһ����ǡ����磺
#define tokenpaster(n) printf("token" #n " = %d", token##n)

#define MAX(x,y) ((x) > (y) ? (x) : (y))
int main()
{
#if 0 ///չʾANSI C��׼�г��õ�Ԥ����꼰����;
    // ��ӡ��ǰԴ�ļ������ַ���������
    printf("��ǰ�ļ�: %s\n", __FILE__);

    // ��ӡ�������ڣ�"MMM DD YYYY"��ʽ��
    printf("��������: %s\n", __DATE__);

    // ��ӡ����ʱ�䣨"HH:MM:SS"��ʽ��
    printf("����ʱ��: %s\n", __TIME__);

    // ��ӡ��ǰ�кţ�ʮ����������
    printf("��ǰ�к�: %d\n", __LINE__);

    // ����Ƿ����ANSI/ISO��׼��1��ʾ���ϣ�
    printf("ANSI��׼: %d\n", __STDC__);

    // ʵ��ʾ����������Ϣ���
    printf("\n[������Ϣ] %s (��%d��) ������ %s %s\n",
           __FILE__, __LINE__, __DATE__, __TIME__);
#endif


    ///�������������\��
    message_for(Carole, Debra);

    int token34 = 40;

    tokenpaster(34);



    return 0;
}
