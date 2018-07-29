
//其中N是用户传入的参数，其值不超过1000。如果N是非负整数，则该函数必须在一行中打印出N!的值，否则打印“Invalid input”。


#include<memory.h>
#include <stdio.h>
#include "iostream"    
#include "math.h"    
void Print_Factorial ( const int N );
int main()
{
    int N;
				
    scanf("%d", &N);
    Print_Factorial(N);
    return 0;
}
void Print_Factorial (const int N)   
{  
    int a[10000];  
    int i,j;  
   	int n = N;
   	if(n<0){printf("Invalid input");return;}
        memset(a,0,sizeof(a));  //clear
        int len=1;  //initialize length
        a[1]=1;  //skip a[0]
        for(i=1;i<=n;i++)  //n!
        {  
            for(j=1;j<=len;j++)  //each bit * i
                a[j]*=i;  
            for(j=1;j<=len;j++)  //adjust
            {  
                if(a[j]<10) continue;  
                
				int pos=j;  
                while (pos<=len)  
                {  
                    if(a[len]>=10)    len++;  
                    a[pos+1] += a[pos]/10;  
                    a[pos]%=10;  
                    pos++;  
                }  
            }  
        }  
        for(i=len;i>=1;i--)  
            printf("%d",a[i]);  
}  
