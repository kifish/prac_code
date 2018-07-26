
/*
二叉排序树，左子树小于等于根，右子树大于等于根。递归建立。

中序遍历即可得不递减序列。

*/

#include<cstdio>

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
    printf("%d ",T->data);
    if(T->lchild!=NULL)
        preorder(T->lchild);
    if(T->rchild!=NULL)
        preorder(T->rchild);
} 

void inorder(Node* T){
    if(T->lchild!=NULL)
        inorder(T->lchild);
    printf("%d ",T->data);
    if(T->rchild!=NULL)
        inorder(T->rchild);
}

void postorder(Node* T){
    if(T->lchild!=NULL)
        postorder(T->lchild);
    if(T->rchild!=NULL)
        postorder(T->rchild);
    printf("%d ",T->data);
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
    while(scanf("%d",&n)!=EOF){
        loc=0;
        //Node* T=create();  mistake
        Node* T = NULL;
        while(n--){
            int tmp;
            scanf("%d",&tmp);
            T=insert(T,tmp);
        }
        preorder(T);
        printf("\n");
        inorder(T);
        printf("\n");
        postorder(T);
        printf("\n");
    }
    return 0;
}
