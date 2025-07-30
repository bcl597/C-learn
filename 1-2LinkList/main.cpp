#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;
///LNode*是结构体指针，和LinkList完全等价的
///输入3,4,5,6,7,9999
void list_head_insert(LNode* &L) ///或者void list_head_insert(LinkList &L)
{
    L=(LinkList) malloc(sizeof (LNode));//申请头结点空间，头指针指向头结点
    L->next=NULL;
    ElemType x;
    scanf("%d",&x);
    LNode* s;//用来指向申请的新结点
    while (x!=999)
    {
        s=(LinkList) malloc(sizeof (LNode));
        s->data=x;
        s->next=L->next;//s的next指向原本链表的第一个结点
        L->next=s;//头结点的next，指向新结点
        scanf("%d",&x);
    }
}

void list_tail_insert(LNode* &L)
{
    L=(LinkList) malloc(sizeof (LNode));
    L->next= NULL;
    ElemType x;
    scanf("%d",&x);
    LNode *s,*r=L;//s是用来指向申请的新结点，r始终指向链表尾部
    while (x!=999)
    {
        s=(LinkList) malloc(sizeof (LNode));
        s->data=x;
        r->next=s;//新结点给尾结点的next指针
        r=s;//r要指向新的尾部
        scanf("%d",&x);
    }   r->next=NULL;//让尾结点的next为NULL

}

void printf_list(LinkList L) {
    L=L->next;
    while (L != NULL)
    {
        printf("%3d",L->data);
        L=L->next;
    }
    printf("\n");
}

///按位置查找
LinkList GetElem(LinkList L,int SearchPos)
{
    int j=0;
    if (SearchPos<0)return NULL;
    while (L&&j<SearchPos)
    {
        L=L->next;
        j++;
    }
    return L;
}

///按值查找
LinkList LocateElem(LinkList L,ElemType SearchVal)
{
    while (L!=NULL)
    {
        if(L->data==SearchVal)//如果找到对应的值，就返回那个结点的地址
        {
            return L;
        }
        L=L->next;
    }
    return NULL;
}

///i代表插入到第几个位置
bool ListFrontInsert(LinkList L,int i,ElemType InsertVal)
{
    LinkList p= GetElem(L,i-1);
    if(NULL==p)
    {
        return false;
    }
    LinkList q;
    q=(LinkList)malloc(sizeof(LNode));//为新结点申请空间
    q->data=InsertVal;
    q->next=p->next;
    p->next=q;
    return true;

}

//删除第i个位置的元素
//删除时L是不会变的，所以不需要加引用
bool ListDelete(LinkList L,int i)
{
    LinkList p= GetElem(L,i-1);//拿到要删除结点的前一个结点
    if(NULL==p)
    {
        return false;
    }
    LinkList q=p->next;//拿到要删除的结点指针
    p->next=q->next;//断链
    free(q);//释放被删除结点的空间
    return true;
}


int main(void)
{
    LNode* L;
    //list_head_insert(L);
    list_tail_insert(L);
    printf_list(L);

    LNode* search;
    //按位置查找
    search=GetElem(L,2);
    if(search!=NULL)
    {
        printf("Succeeded in searching by serial number:2\n");
        printf("%d\n",search->data);
    }
    search=LocateElem(L,6);//按值查询
    if(search!=NULL)
    {
        printf("Search by value succeeded\n");
        printf("%d\n",search->data);
    }
    bool ret;
    ret=ListFrontInsert(L,2,99);//新结点插入第i个位置
    printf_list(L);


    return 0;
}

