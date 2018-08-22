
```C
/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */ 
int binsearch(int x, int v[], int n) { 
    int low, high, mid; 
    low = 0; 
    high = n - 1; 
    while (low <= high) {
         mid = (low+high)/2; 
         if (x < v[mid]) 
            high = mid - 1; 
         else if (x > v[mid])
            low = mid + 1; 
         else /* found match */ 
            return mid; 
    } 
    return -1; /* no match */ 
} 
```

可能会用两次test。


用一次test,
```c
int binsearch(int x, int v[], int n){ 
    int low, high, mid; 
    low = 0; 
    high = n - 1; 
    while (low < high) {
         mid = (low+high)/2; 
         if (x < v[mid]) 
            high = mid - 1; 
         else
            low = mid;
    } 
    if(v[mid] == x)
        return mid; 
    return -1;
} 
```

```C
// Shellsort: sort v[0]...v[n-1] into increasing order
void shellsort(int v[],int n){
    int gap,i,j,temp;
    for(gap = n/2;gap > 0;gap /= 2){
        for(i = gap;i<n;i++){
            for(j = i-gap;j>=0&&v[j]>v[j+gap];j-=gap){
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
        }
    }
}
```



```C
#include #define MAXLINE 1000 /* maximum input line length */ 
int getline(char line[], int max) 
int strindex(char source[], char searchfor[]);
char pattern[] = "ould"; /* pattern to search for */ /* find all lines matching pattern */ 

//If the return type is omitted, int is assumed. 
main(){ 
    char line[MAXLINE]; 
    int found = 0; 
    while (getline(line, MAXLINE) > 0) 
        if (strindex(line, pattern) >= 0) {
            printf("%s", line);
            found++; 
        } 
    return found; 
} 

/* getline: get line into s, return length */
int getline(char s[], int lim) { 
    int c, i; 
    i = 0;
    while(--lim > 0 && (c=getchar()) != EOF && c != '\n') 
        s[i++] = c; 
    if (c == '\n')
        s[i++] = c; 
    s[i] = '\0';
    return i;
}



/* strindex: return index of t in s, -1 if none */ 
int strindex(char s[], char t[]){ 
    int i, j, k; 
    for(i = 0; s[i] != '\0'; i++){
         for(j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++);
            if (k > 0 && t[k] == '\0') return i; 
    } 
    return -1; 
} 



```





```C
//main.c
#include <stdio.h>
#include <stdlib.h> // for atof()  
#include "calc.h"
#define MAXOP 100  // max size of operand or operator  
/* reverse Polish calculator */ 
main() { 
    int type; 
    double op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (type) { 
            case NUMBER:
                push(atof(s)); 
                break; 
            case '+': 
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop()); 
                break; 
            case '-':
                op2 = pop(); 
                push(pop() - op2); 
                break; 
            case '/': 
                op2 = pop(); 
                if (op2 != 0.0) 
                    push(pop() / op2); 
                else printf("error: zero divisor\n"); 
                break;
            case '\n': 
                printf("\t%.8g\n", pop()); 
                break; 
            default: 
                printf("error: unknown command %s\n", s); 
                break; 
        } 
    } 
    return 0; 
} 
```

```c
//calc.h
#define NUMBER '0' // signal that a number was found  
int getop(char []); 
int getch(void);
void push(double); 
double pop(void); 
void ungetch(int);
```

```c
//stack.c
#include <stdio.h>
#include "calc.h"
#define MAXVAL 100 /* maximum depth of val stack */
int sp = 0; /* next free stack position */     
double val[MAXVAL]; /* value stack */

 /* push: push f onto value stack */
 void push(double f){
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
 }

 /* pop: pop and return top value from stack */
 double pop(void){
    if(sp > 0)
        return val[--sp];
    else{
        printf("error: stack empty\n");
        return 0.0;
    }
 } 
```

```c
//getop.c
#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getch(void);
void ungetch(int);
/* getop: get next character or numeric operand */
int getop(char s[]){
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c; /* not a number */

    i = 0;
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()));
    if (c == '.') /* collect fraction part */ 
        while (isdigit(s[++i] = c = getch()));
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
} 
```


```C
//getch.c
#include<stdio.h>
#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

/* get a (possibly pushed-back) character */
int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c){
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
} 
```


references:
the c programming language


