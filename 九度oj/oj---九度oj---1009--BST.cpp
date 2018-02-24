```C++
//二叉排序树和二叉搜索树(BST)基本上是一个意思

#include<cstdio>
#include<string>
#include<cstring>
using namespace std; 

char str[20];

string a;

struct Node{
    Node* lchild;
    Node* rchild;
    int data;
}Tree[105];
int loc;

Node* create(){
    Tree[loc].lchild=Tree[loc].rchild=NULL;
    return &Tree[loc++];
}

void preorder(Node* T){
    a+=T->data+'0';
    if(T->lchild!=NULL)
        preorder(T->lchild);
    if(T->rchild!=NULL)
        preorder(T->rchild);
} 

void inorder(Node* T){
    if(T->lchild!=NULL)
        inorder(T->lchild);
    a+=T->data+'0';
    if(T->rchild!=NULL)
        inorder(T->rchild);
}

/*
void iinorder(Node* T){
    if(T->lchild!=NULL)
        iinorder(T->lchild);
    printf("%d",T->data);
    if(T->rchild!=NULL)
        iinorder(T->rchild);
}
*/

void postorder(Node* T){
    if(T->lchild!=NULL)
        postorder(T->lchild);
    if(T->rchild!=NULL)
        postorder(T->rchild);
    a+=T->data+'0';
}

Node* insert(Node* T,int x){
    if(T==NULL){
        T=create();
        T->data=x;
        return T;// important
    }
    else if(x<T->data){
        T->lchild=insert(T->lchild,x);
    }
    else if(x>T->data){
        T->rchild=insert(T->rchild,x);
    }
    return T;
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF&&n!=0){
        loc=0;
        scanf("%s",str);
        //printf("1:%s",str);
        //Node* T=create();  mistake
        Node* T = NULL;
        int tmp=strlen(str);
        int L=tmp;
        while(tmp){ //mistake:判断的时候tmp就减1了 导致下标出错 
        //    printf("****");
        //    printf("%d : %d",L-tmp,str[L-tmp]-'0');
            T=insert(T,str[L-tmp]-'0');
            tmp--; 
        }
    //    printf("---------");
        //iinorder(T);
        a="";
        preorder(T);
        inorder(T);
        string b=a;
        //printf("2:%s",b.c_str());
        while(n--){
            loc=0;
            scanf("%s",str);
            //Node* T=create();  mistake
            Node* T = NULL;
            int tmp=strlen(str);
            int L=tmp;
            while(tmp){
                T=insert(T,str[L-tmp]-'0');
                tmp--;
            }
            a="";
            preorder(T);
            inorder(T);
            if(b==a)
                puts("YES");
            else puts("NO");
        }
    }
    return 0;
}
```
