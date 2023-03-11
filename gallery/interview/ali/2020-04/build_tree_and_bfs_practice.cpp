#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

const int MAXN = 50;
int pre[MAXN],post[MAXN],inorder[MAXN];

Node* build(int s1,int e1,int s2,int e2){
//    if(s1 > e1) return NULL; //这样写也对
    if(s1 -1 == e1) return NULL;
    int root_idx;
    for(int i = s2;i<=e2;i++){
        if(inorder[i] == post[e1]){
            root_idx = i;
            break;
        }
    }
    Node* root = new Node;//Node* root;是不行的
    root->data = inorder[root_idx];
    root->left = build(s1,s1+root_idx-1-s2,s2,root_idx-1);
    root->right = build(s1+root_idx-s2,e1-1,root_idx+1,e2);
    return root;
}
int n;
vector<int> result;
void bfs(Node* root){
    result.clear();
    queue<Node*> Q;
    Node* tmp;
    Q.push(root);
    while(!Q.empty()){
        tmp = Q.front();
        Q.pop();
        result.push_back(tmp->data);
        if(tmp->left) Q.push(tmp->left);
        if(tmp->right) Q.push(tmp->right);
    }
}
int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&post[i]);
    }
    for(int i = 0;i<n;i++){
        scanf("%d",&inorder[i]);
    }
    Node* root = build(0,n-1,0,n-1);
    bfs(root);
    for(int i = 0;i<result.size();i++){
        if(i!= 0)
            printf(" ");
        printf("%d",result[i]);
    }
    return 0;
}


