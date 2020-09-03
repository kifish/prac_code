#include<cstdio>
#include<cstring>

void print_digits(char *num)
{
    bool first = true;
    int len = strlen(num);
    for (int i = 0; i < len; i++)
    {
        if (!first)
        {
            putchar(num[i]);
        }
        if (num[i] != '0' && first)
        {
            first = false;
            putchar(num[i]);
        }
    }
    //0
    if (first)
    {
        printf("0");
    }
    printf("\n");
}


void recursive(char* num,int len,int index){
    if(index == len){
        print_digits(num);
        return;
    }

    for(int i = 0;i<10;i++){
        num[index] = i + '0';
        recursive(num,len,index+1);
    }
}


void print_nums(int n){
    char* num = new char[n+1];
    num[n] = '\0';
    for(int i =0;i<10;i++){
        num[0] = i + '0';
        recursive(num,n,1);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    print_nums(n);
    return 0;
}