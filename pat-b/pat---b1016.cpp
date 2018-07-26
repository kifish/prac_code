#include<cstdio>
int process(int n,int d){
    int res=0;
    while(n!=0){
        if(n%10==d)
            res=res*10+n%10;
        n/=10;
    }
    return res;
}
int main(){
    int a,da,b,db,pa,pb;
    while(scanf("%d %d %d %d",&a,&da,&b,&db)!=EOF){
        pa=process(a,da);
        pb=process(b,db);
        printf("%d\n",pa+pb);
    }
    return 0;
}
