//https://github.com/kifish/prac_code/tree/master/%E4%B9%9D%E5%BA%A6oj
#include <iostream>
using namespace std;

#define MAXLEN 50
typedef int KeyType;

typedef  struct                     
{ KeyType  key;                                             
} elementType;  

typedef  struct
{ elementType   data[MAXLEN+1]; 
  int   len;
} SeqList;                      

void creat(SeqList &L)
{ int i;
  cin>>L.len;
  for(i=1;i<=L.len;i++)
     cin>>L.data[i].key;   
}

int  binSearch(SeqList T, KeyType k);

int main () 
{  SeqList L;  KeyType k;
   creat(L);
   cin>>k;
   int pos=binSearch(L,k);
   if(pos==0) cout<<"NOT FOUND"<<endl;
   else cout<<pos<<endl;
   return 0;
}

/* 请在这里填写答案 */
int binSearch (SeqList T, KeyType k){
    int left = 1;
    int right = T.len;
    int center = (left+right)/2;
    while(left<=right){
        center = (left+right)/2;
        if (k==T.data[center].key){
        return center;
        }
        else if (k>T.data[center].key){
            left = center+1;
        }
        else if (k<T.data[center].key){
            right = center-1;
        }
    }
    return 0;
}
