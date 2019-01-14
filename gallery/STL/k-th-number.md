https://github.com/kifish/prac_code/blob/master/gallery/%E5%88%86%E6%B2%BB/%E5%AF%BB%E6%89%BE%E4%B8%AD%E4%BD%8D%E6%95%B0.md


 



1.随机选择算法可以。
2.STL有现成的。
nth_element()函数

头文件：#include<algorithm>

作用：nth_element作用为求第n大的元素，并把它放在第n-1位置上，下标是从0开始计数的，也就是说求第0小的元素就是最小的数。


如：a[start,end]元素区间。排序后a[n]就是数列中第n+1大的数（下标从0开始计数）。要注意的是a[start,n),

    a[n,end]内的大小顺序还不一定。只能确定a[n]是数列中第n+1大的数。当然a[start,n)中的数肯定不大于

    a[n,end]中的数。对给定范围[first,last)内的元素进行重新布置.方法是,nth位置的元素放置的值就是把所有元素排序后在nth位置的值.把所有不大于nth的值放到nth的前面,把所有不小于nth的值放到nth后面.

 
注意：nth_element()函数仅仅是将第n大的数排好了位置，并不返回值。

//nth_element example
#include<iostream>//std::cout
#include<algorithm>//std::nth_element,std::random_shuffle
#include<vector>//std::vector

boolmyfunction(inti,intj){return(i<j);}

intmain(){
std::vector<int>myvector;

//setsomevalues:
for(inti=1;i<10;i++)myvector.push_back(i);//123456789

std::random_shuffle(myvector.begin(),myvector.end());

//usingdefaultcomparison(operator<):
std::nth_element(myvector.begin(),myvector.begin()+5,myvector.end());

//usingfunctionascomp
std::nth_element(myvector.begin(),myvector.begin()+5,myvector.end(),myfunction);

//printoutcontent:
std::cout<<"myvectorcontains:";
for(std::vector<int>::iteratorit=myvector.begin();it!=myvector.end();++it)
std::cout<<''<<*it;
std::cout<<'\n';

return0;
} 


#include<iostream>
#include<algorithm>
using namespace std; 
int main() { 
    int a[]={1,3,4,5,2,6,8,7,9};
    int i; 
    cout<<"数列如下："<<endl; 
    for(i=0;i<9;i++) cout<<a[i]<<" ";
    //nth_element(a,a+5,a+9);排序范围
     nth_element(a,a+4,a+9); 
    cout<<"排列后数列如下："<<endl; 
    for(i=0;i<9;i++) cout<<a[i]<<" ";
     cout<<endl<<"输出第五大的数： "<<a[4]<<endl; //注意下标是从0开始计数的 
     return 0; 
 } 

 总结：排列后大于所求值的数在右边，小于所求值的数在左边。共n个数，求第k大数。关键代码如下：
nth_element(a,a+n-k,a+n);
 cout<<a[n-k]; 
