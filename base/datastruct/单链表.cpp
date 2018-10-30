#include <stdio.h>
#include <stdlib.h>
 
typedef int Etype;
 
//定义结点类型 
typedef struct Node
{
    Etype data;              //单链表中的数据域 
    struct Node *next;          //单链表的指针域 
}Node,*List,*position;
 
 
//单链表的初始化
 
List ListInit()
{
    Node* L;
    //List L;
    L = (Node*)malloc(sizeof(Node));   //申请结点空间 
    if(L == NULL)                       //判断是否有足够的内存空间 
        printf("申请内存空间失败\n");
    L->next = NULL;                  //将next设置为NULL,初始长度为0的单链表 
 return L;
}
 
 
//单链表的建立1，头插法建立单链表
 
List ListCreatH()
{
    Node *L;
    L = (Node*)malloc(sizeof(Node));   //申请头结点空间
    L->next = NULL;                      //初始化一个空链表
     
    Etype x;                         //x为链表数据域中的数据
    while(scanf("%d",&x) != EOF)
    {
        Node* p;
        p = (Node*)malloc(sizeof(Node));   //申请新的结点 
        p->data = x;                     //结点数据域赋值 
        p->next = L->next;                    //将结点插入到表头L-->|2|-->|1|-->NULL 
        L->next = p; 
    }
    return L; 
} 
 
 
//单链表的建立2，尾插法建立单链表
 /*
List ListCreatT()
{
    Node* L;
    L = (Node*)malloc(sizeof(Node));   //申请头结点空间
    L->next = NULL;                  //初始化一个空链表
    Node* r;
    r = L;                          //r始终指向终端结点，开始时指向头结点 
    Etype x;                         //x为链表数据域中的数据
    while(scanf("%d",&x) != EOF)
    {
        Node* p;
        p = (Node*)malloc(sizeof(Node));   //申请新的结点 
        p->data = x;                     //结点数据域赋值 
        r->next = p;                 //将结点插入到表头L-->|1|-->|2|-->NULL 
        r = p; 
    }
    r->next = NULL; 
     
    return L;   
}
*/
 
 
//单链表的插入，在链表的第i个位置插入x的元素
 
List ListInsert(List L,int i,Etype x)
{
    Node* temp;                      //pre为前驱结点 
    temp = L;
    int index = 0;
    for (index = 1; index < i; index++)
        temp = temp->next;                 //查找第i个位置的前驱结点 i-1,head 0
    Node* p;                                //插入的结点为p
    p = (Node*)malloc(sizeof(Node));
    p->data = x; 
    p->next = temp->next;
    temp->next = p;
    //free(temp);  //此处不能删除，等于删除该地址所指向的node 
     
    return L;                           
} 
 
 
//单链表的删除，在链表中删除值为x的元素
 
List ListDelete(List L,Etype x)
{
    Node *p,*pre;                   //pre为前驱结点，p为查找的结点。 
    p = L->next;
    while(p->data != x)              //查找值为x的元素 
    {   
        pre = p; 
        p = p->next;
    }
    pre->next = p->next;          //删除操作，将其前驱next指向其后继。 
    free(p);
    return L;
} 
 
 
int main()
{
    List list,start;
    printf("请输入单链表的数据："); 
    list = ListCreatH();
    for(start = list->next; start != NULL; start = start->next)
        printf("%d ",start->data);
    printf("\n");
 
 
    int i;
    Etype x;
    printf("请输入插入数据的位置：");
    scanf("%d",&i);
    printf("请输入插入数据的值：");
    scanf("%d",&x);
    ListInsert(list,i,x);
    for(start = list->next; start != NULL; start = start->next)
        printf("%d ",start->data);
    printf("\n");
    printf("请输入要删除的元素的值：");
    scanf("%d",&x);
    ListDelete(list,x); 
    for(start = list->next; start != NULL; start = start->next)
        printf("%d ",start->data);
    printf("\n");
     
    return 0;
}
