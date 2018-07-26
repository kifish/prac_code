#include<cstdio>
#include<cstring>
struct Node{
    Node* lchild;
    Node* rchild;
    char data;
}node[50];

int loc;
Node* create(){
    node[loc].lchild=node[loc].rchild=NULL;
    return &node[loc++];
} 

char str1[30],str2[30];
void postorder(Node* root){
    if(root->lchild!=NULL)
        postorder(root->lchild);
    if(root->rchild!=NULL)
        postorder(root->rchild);
    printf("%c",root->data);
}

Node* build(int s1,int e1,int s2,int e2){
    Node* ret=create();
    ret->data=str1[s1];
    int i;
    for(i=s2;i<=e2;i++){
        if(str2[i]==str1[s1]){
            break;
        }
    }
    if(i!=s2)
        ret->lchild=build(s1+1,s1+1+(i-1-s2) ,s2,i-1);
    else ret->lchild=NULL;
    if(i!=e2)
        ret->rchild=build(s1+1+(i-1-s2)+1,e1,i+1,e2);
    else ret->rchild=NULL; //NULL可以不写 因为初始为NULL了
    return ret;
}

int main(){
    while(gets(str1)){
        loc=0;
        gets(str2);
        int L1=strlen(str1);
        int L2=strlen(str2);
        Node* root=build(0,L1-1,0,L2-1);
        postorder(root);
        printf("\n");
    }
    return 0;
}
