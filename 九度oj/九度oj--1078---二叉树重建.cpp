//通过两种遍历结果重建，必须有中序遍历（找到根的位置）。
#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
struct Node{
    Node* lchild;
    Node* rchild;
    char  data;
}node[50];
string a,b;

int cnt;

Node* create(){
    node[cnt].lchild=node[cnt].rchild=NULL;
    return &node[cnt++];
}

void postorder(Node* root){
    if(root->lchild!=NULL) postorder(root->lchild);
    if(root->rchild!=NULL) postorder(root->rchild);
    printf("%c",root->data);
}
Node* build(int s1,int e1,int s2,int e2){
    Node* ret=create();
    ret->data=a[s1];
    int idx=0;
    for(int i=0;i<b.size();i++){
        if(b[i]==a[s1]){
            idx=i;
            break;    
        }     
    }
    if(idx!=s2)
        ret->lchild=build(s1+1,s1+idx-s2,s2,idx-1);
    if(idx!=e2)
        ret->rchild=build(s1+idx-s2+1,e1,idx+1,e2);
    return ret;
}
int main(){
    
    while(cin>>a){
        cin>>b;
        cnt=0;
        Node* root=build(0,a.size()-1,0,b.size()-1);
        postorder(root);
        printf("\n");
    }    
    return 0;
}
