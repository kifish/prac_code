	#include<cstdio>
	int main(){
	    char a;
	    int n;
	     
	    while(scanf("%d %c",&n,&a)!=EOF){ //scanf 读入须有空格 
	        printf("%c",a);
	        for(int i = 1;i<n;i++) printf("%c",a);
	        printf("\n");
	        for(int i = 0;i<(n+1)/2-2;i++){
	            printf("%c",a);
	            for(int j = 0;j<n-2;j++)printf(" ");
	            printf("%c",a);
	            printf("\n");
	        }
	        printf("%c",a);
	        for(int i = 1;i<n;i++) printf("%c",a);
	    }
	     
	    return 0;
	}
　　//实际上即使行与行之间不空一行，行间距还是比列间距大的。确定好是空1行还是空2行。
