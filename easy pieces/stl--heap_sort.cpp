//http://blog.csdn.net/morewindows/article/details/6967409


#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int Maxn=20;
void print_vector_int(vector<int> &vet)
{
    for(vector<int>::iterator pos = vet.begin();pos!=vet.end();pos++)
        printf("%d ",*pos);
    putchar('\n');    
}

int main(){
    
    int a[Maxn];
    int i;
    for(i=0;i<Maxn;++i)
        a[i]=rand()%(Maxn*2);
    vector<int> *pvet= new vector<int>(40);
    pvet->assign(a,a+Maxn);
    
    make_heap(pvet->begin(),pvet->end());
    print_vector_int(*pvet);
    
    pvet->push_back(25);
    print_vector_int(*pvet);
    printf("-------");
    push_heap(pvet->begin(),pvet->end());
    print_vector_int(*pvet);
    
    pop_heap(pvet->begin(),pvet->end());
    pvet->pop_back();
    pop_heap(pvet->begin(),pvet->end());
    pvet->pop_back();
    print_vector_int(*pvet);
    
    sort_heap(pvet->begin(),pvet->end());
    print_vector_int(*pvet);
    
    delete pvet;
    return 0;    
}
