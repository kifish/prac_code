
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




```C
/* qsort: sort v[left]...v[right] into increasing order */
// 空间复杂度O(N)
void qsort(int v[], int left, int right){
    int i, last;
    void swap(int v[], int i, int j); 
    if(left >= right) /* do nothing if array contains */
        return; /* fewer than two elements */
    swap(v, left, (left + right)/2); /* move partition elem */
    last = left; /* to v[0] */
    for (i = left + 1; i <= right; i++) /* partition */
        if(v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last); /* restore partition elem */
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j){
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
} 





```C
#define ALLOCSIZE 10000 /* size of available space */
static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf; /* next free position */
/* return pointer to n characters */

char *alloc(int n){
    if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits */
        allocp += n;
        return allocp - n; /* old p */
    } else /* not enough room */
        return 0;
    }

/* free storage pointed to by p */
void afree(char *p){
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p;
}

```





多个字符串排序
```C
#include <stdio.h>
#include <string.h>
#define MAXLINES 5000  /* max #lines to be sorted */
char *lineptr[MAXLINES]; /* pointers to text lines */
//数组lineptr存放的是指针，对某个指针进行*操作,得到对应变量是char类型的。
//指针本身就是变量，这些指针里面存放了指向的(另外的)变量的地址。
//在这个问题中，这些指针存放的地址是字符串的起始地址
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);
/* sort input lines */
main(){
    int nlines; /* number of input lines read */
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } 
    else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000 /* max length of any input line */
int getline(char *, int);
char *alloc(int);
/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines){
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || p = alloc(len) == NULL)
            return -1;
        else{ 
            line[len-1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines){
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
} 

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right){
    int i, last;
    //循环不变量:
    //last 始终是 小于pivot 的元素的集合的 顺序排列的 最后一个元素的 index
    void swap(char *v[], int i, int j);
    if (left >= right) /* do nothing if array contains */
        return; /* fewer than two elements */
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    //这一步后,0,1,...,last-1(th)元素都是 小于pivot的
    //last (th) 为pivot
    qsort(v, left, last-1); 
    qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j){
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
} 




```



```C
#include<stdio.h>
#include<string.h>
#define MAXLINE 1000

int getline(char *line, int max);


//It is rare that one uses pointer expressions 
//more complicated than these; in such cases,
//breaking them into two or three steps will be more intuitive.
//find:print lines that match pattern from 1st arg
main(int argc, char *argv[]) {
	char line[MAXLINE];
	long lineno = 0;
	int c, except = 0, number = 0, found = 0;
	while (--argc > 0 && (*++argv)[0] == '-') { // 下一个字符串
		while (c = *++argv[0]) { // 下一个字符
			switch (c){
			case 'x':
				except = 1;
				break;
			case'n':
				number = 1;
				break;
			default:
				printf("find: illegal option %c\n", c);
				argc = 0;
				found = -1;
				break;//default 加break，是为了避免以后添加新case的时候，忘记加break
			}
		}
		if (argc != 1)
			printf("Usage: find -x -n pattern\n");
		else 
			while (getline(line, MAXLINE) > 0) {
				lineno++;
				if ((strstr(line, *argv) != NULL) != except) {
					if (number) 
						printf("%ld:", lineno);
					printf("%s", line);
					found++;
				}
			}
	}
}
```


```C
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define MAXLINES 5000
char *lineptr[MAXLINES];
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(void *lineptr[], int left, int right, int(*comp)(void *, void *));
int numcmp(char *, char *);
main(int argc, char *argv[]) {
	int nlines;
	int numeric = 0;
	if (argc > 1 && strcmp(argv[1], "-n") == 0)
		numeric = 1;
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort((void**)lineptr, 0, nlines - 1, (int (*)(void*, void*))(numeric ? numcmp : strcmp));
		writelines(lineptr, nlines);
		return 0;
	}
	else {
		printf("input too big to sort\n");
		return 1;
	}
}

//qsort : sort v[left],...v[right] into increasing order
void qsort(void *v[], int left, int right, int(*comp)(void *, void *)) {
	int i, last;
	void swap(void *v[], int, int);
	if (left >= right)
		return;
	swap(v, left, (left + right) / 2);
	last = left;
	for (int i = left + 1; i <= right; i++) {
		if ((*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);
	}
	swap(v, left, last);
	qsort(v, left, last - 1, comp);//comp 相当于函数的起始地址
	qsort(v, last + 1, right, comp);
	//return;
}

//numcmp:compare s1 and s2 numerically
int numcmp(char *s1, char *s2) {
	double v1, v2;
	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	return 0;
}

void swap(void *v[], int i, int j) {
	void *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}



```


```c

struct point {
	int x;
	int y;
}x,y,z;

struct point pt;
struct maxpt = { 320,200 };

struct rect {
	struct point pt1;
	struct point pt2;
};

struct rect screen;
//screen.pt1.x


struct point makepoint(int x, int y) {
	struct point temp;
	temp.x = x;
	temp.y = y;
	return temp;
}

struct point middle;
struct point makepoint(int, int);
screen.pt1 = makepoint(0, 0);
screen.pt2 = makepoint(XMAX, YMAX);

middle = makepoint((screen.pt1.x + screen.pt2.x) / 2, (screen.pt1.y + screen.pt2.y) / 2);


//值传递
addpoint(struct point p1, struct point p2) {
	p1.x += p2.x;
	p1.y += p2.y;
	return p1;
}

//ptinrect:return 1 if p in r,0 if not
int ptinrect(struct point p, struct rect r) {
	return p.x >= r.pt1.x && p.x <= r.pt2.x && p.y >= r.pt1.y && p.y <= r.pt2.y;
}

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))


struct rect canonrect(struct rect r) {
	struct rect temp;
	temp.pt1.x = min(r.pt1.x, r.pt2.x);
	temp.pt1.y = min(r.pt1.y, r.pt2.y);
	temp.pt2.x = max(r.pt1.x, r.pt2.x);
	temp.pt2.y = max(r.pt1.y, r.pt2.y);
	return temp;
}


struct point origin, *pp;
pp = &origin;
printf("origin is (%d,%d)\n", (*pp).x, (*pp).y);
printf("origin is (%d,%d)\n", pp->x, pp->y);

struct rect r, *rp = &r;


struct key {
	char *word;
	int count;
}keytab[NKEYS];

struct key keytab2[NKEYS];

struct key {
	char *word;
	int count;
}keytab2[] = {
	"auto",0,
	"break",0,
	"while",0
};


struct key {
	char *word;
	int count;
}keytab2[] = {
	{"auto",0},
	{"break",0},
	{"while",0}
};

```



references:
the c programming language


