```C++
//二叉排序树和二叉搜索树(BST)基本上是一个意思
/*
 判断两组序列能否构成同一颗二叉搜索树，只需建树后，前序/后序＋中序，若相同，则是同一棵二叉树。

反之需要前序/后序＋中序才能重建二叉树。

C语言里的字符数组可以在最后一个字符后添加空字符（0），方便使用字符串函数。

C++ 清空string

str.clear ( );
或者str=“”；

 string 可以直接作为形参传入。
 
#include<iostream>
#include<string>
using namespace std; 

void output(string a){
    for(int i=0;i<a.length();i++)
        cout<<a[i];
}
int main(){
    string a;
    cin>>a;
    output(a);
}
*/
    
    
    
    
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


/*另一种解法
#include<cstdio>
#include<cmath>
#include<string>
#include<iostream>
using namespace std;

string res;

string temp;
struct Node{
    Node* lchild;
    Node* rchild;
    char data;
}node[105];
int loc;
int idx;
Node* create(){
    node[loc].lchild=node[loc].rchild=NULL;
    return &node[loc++];  //要返回节点的地址 
}
Node* insert(Node* root,char x){
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
void preorder(Node* root){   
    res+=root->data;
    if(root->lchild)
            preorder(root->lchild);
    if(root->rchild)
            preorder(root->rchild);
    
}
void inorder(Node* root){
    if(root->lchild)
         inorder(root->lchild);
    res+=root->data;
    if(root->rchild)
         inorder(root->rchild);
}

void postorder(Node* root){
    if(root->lchild)
         postorder(root->lchild);
    if(root->rchild)
         postorder(root->rchild);
     res+=root->data;
    
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        loc=0;
        Node* root=NULL;
        cin>>temp;
        for(int i=0;i<temp.size();i++)
            root=insert(root,temp[i]);
           res="";
        preorder(root);
        inorder(root);
        string res1=res;
        while(n--){
            cin>>temp;
            Node* root=NULL;   //记得这里重新建树
             for(int i=0;i<temp.size();i++)
                root=insert(root,temp[i]);
             res="";
            preorder(root);
            inorder(root);
            string res2=res;
            if(res1==res2)
                puts("YES");
            else puts("NO");
        
        }
    }
    return 0;
}

*/


```
