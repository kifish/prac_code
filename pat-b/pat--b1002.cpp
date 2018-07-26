
#include<cstdio>
#include<cstring>//memset
char str[105];
int outstr[50];
char map[11][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu","shi"};
int main(){
    while(scanf("%s",str)!=EOF){
        int sum=0;
        for(int i=0;str[i]!='\0';i++){   //Here 0 is equal to '\0'.
            sum+=str[i]-'0';
        }
        memset(str,0,sizeof(str));
        int pos=0;
        while(sum!=0){
            outstr[pos++]=sum%10;
            sum/=10;
        }    
        for(int i=pos-1;i>=0;i--){
            int t=outstr[i];
            if(i==pos-1) printf("%s",map[t]);//t is the row index.map[t] is not equal to map[t][].
            else printf(" %s",map[t]);
        }
    }
    return 0;
}
