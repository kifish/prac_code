int first=1;

for(int i = 1; i<=n; i++)
    if(a[i])
    {if(first)
        first=0;
     else printf(" ");
     printf("%d",i);
    }
    
    
for(int =n-1; i>=1; i--)
    printf("%d ", a[i]);
printf("%d\n", a[0]);  //最后一个数单独处理 
