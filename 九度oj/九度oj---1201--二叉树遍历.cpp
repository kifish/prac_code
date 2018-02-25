/*
0是NULL的一个实现，但NULL不是0。

指针的数值是其所指向的内存的地址。
很多时候我们需要标明“这个指针当前为无效指针，它不指向任何可以使用的内存空间”，因为不能在指针外附加一个标志位，所以就需要设定一个特别的值，当指针的数值是这个值时，我们就认为这个指针当前是无效指针
因为内存从0开始的一段区域正常情况下是不允许读写的，所以我们规定，“当指针数值为0时，也就是它指向内存地址0时，这个指针就是不正常的指针，也就是我们所要声明的“该指针当前无效””。
为了明示这个意义。通常使用#define NULL 0语句来将指针与NULL比较。程序可读性大大提高.。



*/




/*
void preorder(Node* root){  
    printf("%d ",root->data);
    if(root->lchild!=NULL)
        return    preorder(root->lchild);
    if(root->rchild!=NULL)
        return    preorder(root->rchild);
    return; 
}
这样的写法是错误的，有了上面的return的之后，其他子树还没遍历到，就返回了。
*/
#include<cstdio>
#include<cmath>

struct Node{
    Node* lchild;
    Node* rchild;
    int data;
}node[105];
int loc;
Node* create(){
    node[loc].lchild=node[loc].rchild=NULL;
    return &node[loc++];  //要返回节点的地址 
}
Node* insert(Node* root,int x){
    if(root==NULL){
        root=create();
        root->data=x;
        return root;//要返回根节点的指针 
    }
    else if(x>root->data){
        root->rchild=insert(root->rchild,x);
    }
    else if(x<root->data){
        root->lchild=insert(root->lchild,x);
    }
    return root;
}
void preorder(Node* root){  //return 可以不写 
    printf("%d ",root->data);
    if(root->lchild!=NULL)
            preorder(root->lchild);
    if(root->rchild!=NULL)
            preorder(root->rchild);
    
}
void inorder(Node* root){
    if(root->lchild!=NULL)
         inorder(root->lchild);
    printf("%d ",root->data);
    if(root->rchild!=NULL)
         inorder(root->rchild);
}

void postorder(Node* root){
    if(root->lchild!=NULL)
         postorder(root->lchild);
    if(root->rchild!=NULL)
         postorder(root->rchild);
    printf("%d ",root->data);
    
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        loc=0;
        int tmp;
        Node* root=NULL;
        while(n--){
            scanf("%d",&tmp);
            root=insert(root,tmp);
        }
        preorder(root);
        printf("\n");
        inorder(root);
        printf("\n");
        postorder(root);
        printf("\n");
    }
    return 0;
}



//其实可以去掉部分NULL。 NULL默认是0了。
/*
#include<cstdio>
#include<cmath>

struct Node{
    Node* lchild;
    Node* rchild;
    int data;
}node[105];
int loc;
Node* create(){
    node[loc].lchild=node[loc].rchild=NULL;
    return &node[loc++];  //要返回节点的地址 
}
Node* insert(Node* root,int x){
    if(!root){
        root=create();
        root->data=x;
        return root;//要返回根节点的指针 
    }
    else if(x>root->data){
        root->rchild=insert(root->rchild,x);
    }
    else if(x<root->data){
        root->lchild=insert(root->lchild,x);
    }
    return root;
}
void preorder(Node* root){  //return 可以不写 
    printf("%d ",root->data);
    if(root->lchild)
            preorder(root->lchild);
    if(root->rchild)
            preorder(root->rchild);
    
}
void inorder(Node* root){
    if(root->lchild)
         inorder(root->lchild);
    printf("%d ",root->data);
    if(root->rchild)
         inorder(root->rchild);
}

void postorder(Node* root){
    if(root->lchild)
         postorder(root->lchild);
    if(root->rchild)
         postorder(root->rchild);
    printf("%d ",root->data);
    
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        loc=0;
        int tmp;
        Node* root=NULL;
        while(n--){
            scanf("%d",&tmp);
            root=insert(root,tmp);
        }
        preorder(root);
        printf("\n");
        inorder(root);
        printf("\n");
        postorder(root);
        printf("\n");
    }
    return 0;
}


*/
