#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

char words[90][90];
int main()
{
    //pat 是单点测试
    int idx = 0;
    while (scanf("%s", words[idx]) != EOF){
        idx++;
    }
        ;
    for (int i = idx - 1; i >= 0; i--)
    {
        if (i != idx - 1){
            // printf("%d\n",i); 
            printf(" %s", words[i]);
        }
        else
            printf("%s", words[i]);
    }
    //    printf("\n");
    return 0;
}
