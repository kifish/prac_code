```C
//
// Created by k on 2018/9/22.
//

#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
#include <set>
using namespace std;

int main(){
    set S;
    set::iterator j;
    string s;
    while(cin>>s) S.insert(s);
    for(j = S.begin();j!= S.end();++j){
        cout<<*j<<endl;
    }
    return 0;
}




```



```C
//
// Created by k on 2018/9/22.
//

#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
#include <map>
using namespace std;

int main(){
    map M;
    map::iterator j;
    string s;
    while(cin>>s) M[s]++;//默认初始化为0 
    for(j = M.begin();j!= M.end();++j){
        cout<<j->first<<" "<<j->second<<endl;
    }
    return 0;
}




```


```C
//
// Created by k on 2018/9/22.
//

#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
#include <map>
using namespace std;


//hash table
typedef struct node *nodeptr;//nodeptr 是一个指针，则*nodeptr 是一个node
//typedef 相当于给类型起别名
typedef struct node{
    char *word;
    int count;
    nodeptr next;
}node;

#define NHASH 29989
#define MULT 31

nodeptr bin[NHASH];

//map s string to a positive integer less than NHASH
//具体见原文
unsigned int hash(char *p){
    unsigned int h = 0;
    for(;*p;p++)
        h = MULT * h + *p;
    return h % NHASH;
}




char buf[105];

int main(){
    for(int i = 0;i<NHASH;++i) bin[i] = NULL;
    while(scanf("%s",buf) != EOF)
    return 0;
}

void incword(char *s){
    int h = hash(s);
    for(nodeptr p = bin[h];p != NULL;p = p->next){
        if(strcmp(s,p->word) == 0){
            (p->count)++;
            return;
        }
    }
    nodeptr p = (nodeptr)malloc(sizeof(node));
    //malloc 返回的是 void*
    //nodeptr 强制类型转换为 nodeptr类型
    p->count = 1;
    p->word = (char*)malloc(strlen(s) + 1);
    strcpy(p->word,s);
    p->next = bin[h];//insert the node at the front of the list
    bin[h] = p;
}



```