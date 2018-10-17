
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

初始化数组
`int a[1010] = {0}; //初始化为0`

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

```c

#include<ctype.h>
//getword:get next word or character from input
int getword(char *word,int lim){
	int c,getch(void);
	void ungetch(int);
	char *w = word;
	while(isspace(c = getch()));
	if(c != EOF)
		*w++ = c;
	if(!isalpha(c)){
		*w = '\0';
		return c;
	}
	for(;--lim>0;w++){
		if(!isalum(*w = getch())){
			ungetch(*w);
			break;
		}
	}
	*w = '\0';
	return word[0];
}

```




```C
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAXWORD 100
int getword(char *，int);
struct key *binsearch(char *,struct key *,int);
//count C keywords;pointer version
main(){
	char word[MAXWORD];
	struct key *p;
	while(getword(word,MAXWORD) != EOF){
		if(isalpha(word[0]))
			if((p = binsearch(word,keytab,NKEYS) != EOF)){
				p->count++;
			}
	}
	for(p = keytab;p< keytab + NKEYS;p++){
		if(p->count > 0)
			printf("%4d %s\n",p->count,p->word);
	}
	return 0;
}

//binsearch:find word in tab[0],...,tab[n-1]
struct key *binsearch(char *word,struct key *tab,int n){
	int cond;
	struct key *low = &tab[0];
	struct key *high = &tab[n];
	struct key *mid;
	while(low < high){
		mid = low + (high-low)/2;
		if((cond = strcmp(word,mid->word)<0)
			high = mid;
		else if (cond > 0)
			low = mid  + 1;
		else 
			return mid;
	}
	return NULL;
}
```




```c

#include <stdio.h>
#include<ctype.h>
#include<string.h>
#define MAXWORD 100
struct tnode *addtree(struct tnode *,char *);
void treeprint(struct tnode*);
int getword(char *,int);
struct tnode{
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};
//word frequency count
main(){
	struct tnode *root;
	char word[MAXWORD];
	root = NULL;
	while(getword(word,MAXWORD) != EOF){
		if(isalpha(word[0]))
			root = addtree(root,word);
	}
	treeprint(root);
	return 0;
}
struct tnode *talloc(void);
char *strdup(char *);
//addtree: add a node with w,at or below p

struct treenode *addtree(struct tnode *p,char *w){
	int cond;
	if(p == NULL){
		p = talloc();
		p->word = strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	}
	else if((cond = strcmp(w,p->word)) == 0){
		p->count++;
	}
	else if(cond < 0)
		p->left = addtree(p->left,w);
	else
		p->right = addtree(p->right,w);
	return p;
}
//treeprint: in-order print if tree p
void treeprint(struct tnode *p){
	if(p != NULL){
		treeprint(p->left);
		printf("%4d %s\n",p->count,p->word);
		treeprint(p->right);
	}
}


//talloc:make a tnode
struct tnode *talloc(void){
	return (struct tnode *) malloc(sizeof(struct tnode));
}


char *strdup(char *s){
	char *p;
	p = (char *) malloc(strlen(s) + 1);// +1 for '\0'
	if(p != NULL)
		strcpy(p,s);
	return p;
}

```


```c
struct nlist{	//table entry
	struct nlist *next; //next entry in chain
	char *name;  // defined name
	char *defn;   //replacement text
}

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE]; //pointer table
//hash:form hash value for string s
unsigned hash(char *s){
	unsigned hashval;
	for(hashval = 0;*s != '\0';s++){
		hashval = *s + 31 * hashval;
	}
	return hashval % HASHSIZE;
}

//lookup:look for s in hashtab
struct nlist *lookup(char *s){
	struct nlist *np;
	for(np = hashtab[hash[s]];np != NULL;np = np->next){
		if(strcmp(s,np->name) == 0)
			return np;
	}
	return NULL;
}

//for(ptr = head;ptr != NULL;ptr = ptr->next)

struct nlist *lookup(char *);
char *strup(char *);

//install:put (name,defn) in hashtab
struct nlist *install(char *name,char *defn){
	struct nlist *np;
	unsigned hashval;
	if((np = lookup(name) == NULL)){
		np = (struct nlist *) malloc(sizeof(*np));
		if(np == NULL || (np->name = strdup(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	}
	else 
		free((void *) np->defn);
	if((np->defn = strup(defn)) == NULL)
		return NULL;
	return np;
}




```

typedef

```c

typedef int Length;
Length len,maxlen;
Length *lengths[];

typedef char *String;
String p,lineptr[MAXLINES],alloc(int);
int strcmp(String,String);
p = (String) malloc(100); //100 个bytes

typedef struct tnode *Treeptr;
typedef struct tnode{ // the tree node
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
}Treenode;

//Treenode, a structure
//Treeptr, a pointer to the structure

Treeptr talloc(void){
    return (Treeptr) malloc(sizeof(Treenode));
}

typedef int (*PFI)(char *,char *);
PFI strcmp,numcmp;


```


```c


union u_tag{
	int ival;
	float fval;
	char *sval;
}u;
//union 的存储空间是最大类型所需的空间


//使用union的时候 只能把他始终对待成同一种类型

if(utype == INT)
	printf("%d\n",u.ival);
if(utype == FLOAT)
	printf("%f\n",u.fval);
if(utype == STRING)
	printf("%s\n",u.sval);
else 
	printf("bad type %d in utype\n",utype);



#define KEYWORD 01
#define EXTERNAL 02
#define STATIC 04

enum {KEYWORD = 01,EXTERNAL = 02,STATIC = 04};

flags |= EXTERNAL | STATIC;
//turns on the EXTERNAL and STATIC bit in flags,while
flags &= ~(EXTERNAL | STATIC);
//turns them off

if((flags & (EXTERNAL | STATIC)) == 0)
//is true if both bits are off


//more naturally
//bitfield
struct{
	unsigned int is_keyword : 1;
	unsigned int is_extern : 1;
	unsigned int is_extern : 1;
}flags;
//This defines a variable table called flags that contains three 1 - bit fields.
//The number following the colon represents the field width in bits.
//The fields are declared unsigned intto ensure that they are unsigned quantities.

flags.is_extern = flags.is_static = 1;
flags.is_extern = flags.is_static = 0;

if(flags.is_extern == 0 && flags.is_static == 0)




```




```c
#include<stdarg.h>
#include<stdio.h>
//minprintf: minimal printf with variable argument list
void minprintf(char *fmt,...){
	va_list ap;//points to each unnamed arg in turn
	char *p,*sval;
	int ival;
	double dval;
	va_start(ap,fmt); // make ap point to 1st unnamed arg
	for(p = fmt;*p;p++){
		if(*p != '%'){
			putchar(*p);
			continue;
		}
		switch(*++p){
			case 'd':
				ival = va_arg(ap,int);
				printf("%d",ival);
				break;
			case 'f':
				dval = va_arg(ap,double);
				printf("%f",dval);
				break;
			case 's':
				for(sval = va_arg(ap,char *);*sval;sval++)
					putchar(*sval);
				break;
			default:
				putchar(*p);
				break;
		}
	}
	va_end(ap); //clean up when done
}
```

```c
#include<stdio.h>
main(){ //rudimentary calculator
	double sum,v;
	sum = 0;
	while(scanf("%lf",&v) == 1)
		printf("%t%.2f\n",sum += v);
	return 0;
}
```

```c
#include <stdio.h>
#define getchar()  getc(stdin)
#define putchar(c) putc((c),stdout)

//cat : concatenate files, version 1
main(int argc,char *argv[]){
	FILE *fp;
	void filecopy(FILE*,FILE*);
	if(argc == 1) //no args;copy standard input
		filecopy(stdin,stdout);
	else
		while(--argc > 0){
			if((fp = fopen(*++argv,"r")) == NULL){
				printf("cat:can't open %s \n",*argv);
				return 1;
			}
			else{
				filecopy(fp,stdout);
				fclose(fp);
			}
		}
		return 0;
}

void filecopy(FILE *ifp,FILE *ofp){
	int c;
	while((c = getc(ifp)) != EOF)
		putc(c,ofp);
}

```

```c
#include <stdio.h>
#define getchar()  getc(stdin)
#define putchar(c) putc((c),stdout)

//cat : concatenate files, version 2
main(int argc,char *argv[]){
	FILE *fp;
	void filecopy(FILE*,FILE*);
	char *prog = argv[0]; //program name for errors
	if(argc == 1) //no args;copy standard input
		filecopy(stdin,stdout);
	else
		while(--argc > 0){
			if((fp = fopen(*++argv,"r")) == NULL){
				fprintf(stderr,"%s:can't open %s\n",prog,*argv);
				exit(1);
			}
			else{
				filecopy(fp,stdout);
				fclose(fp);
			}
		}
	if(ferror(stdout)){ //check if an error occurred on the stream stdout  
		fprintf(stderr,"%s: error writing stdout\n",prog);
		exit(2);
	}
	exit(0);
}

void filecopy(FILE *ifp,FILE *ofp){
	int c;
	while((c = getc(ifp)) != EOF)
		putc(c,ofp);
}

```

```c
//fgets: get at most n chars from iop
char *fgets(char *s,int n ,FILE *iop){
	register int c;
	register char *cs;
	cs = s;
	while(--n > 0 && (c = getc(iop)) != EOF){
		if((*cs++ = c) == '\n')
			break;
	}
	*cs = '\0';
	return (c == EOF && cs == s) ? NULL : s;
}

//fputs: put string s on file iop
int fputs(char *s,FILE *iop){
	int c;
	while(c = *s++)
		putc(c,iop);
	return ferror(iop) ? EOF : 0;
}


//getline: read a line, return length
int getline(char *line,int max){
	if(fgets(line,max,stdin) == NULL)
		return 0;
	else 
		return strlen(line);
}


```


```c
#include "syscalls.h"
//read is a system call
//getchar: unbuffered single character input
int getchar(void){
	char c;
	return (read(0,&c,1) == 1) ? (unsigned char) c : EOF;
}
main(){ //copy input to output
	char buf[BUFSIZ];
	int n;
	while((n = read(0,buf,BUFSIZ)) > 0)
		write(1,buf,n);
	return 0;
}
```

```C
#include "syscalls.h"
//read is a system call
//getchar: simple buffered version
int getchar(void){
	static char buf[BUFSIZ];
	static char *bufp[BUFSIZ]
	static int n = 0;
	if(n == 0){ // buffer is empty
		n = read(0,buf,sizeof buf);
		bufp = buf;
	}
	return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}
main(){ //copy input to output
	char buf[BUFSIZE];
	int n;
	while((n = read(0,buf,BUFSIZE)) > 0)
		write(1,buf,n);
	return 0;
}
```
```c
#include "syscalls.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdarg.h>
#define PERMS 0666 //RW for owner,group,others
void error(char *,...);
//cp: copy f1 to f2
main(int argc,char *argv[]){ 
	int f1,f2,n;
	char buf[BUFSIZ];
	if(argc != 3)
		error("Usage:cp from to");
	if((f1 = open(argv[1],O_RDONLY,0)) == -1)
		error("cp: can't open %s",argv[1]);
	if((f2 = creat(argv[2],PERMS)) == -1)
		error("cp: can't create %s,mode %03o",argv[2],PERMS);
	while((n = read(f1,buf,BUFSIZ)) > 0)
		if(write(f2,buf,n) != n)
			error("cp: write error on file %s",argv[2]);
	return 0;
}


//error: print an error message and die
void error(char *fmt,...){
	va_list args;
	va_start(args,fmt);
	fprintf(stderr,"error:");
	vprintf(stderr,fmt,args);
	fprintf(stderr,"\n");
	va_end(args);
	exit(1);
}
```


```c

#include <fcntl.h>
#include "syscalls.h"
#define PERMS 0666 // RW for owner,group,other

#define NULL 0
#define EOF (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20 // max #files open at once 


typedef struct _iobuf{
	int cnt;//characters left
	char *ptr; //next character position
	char *base; //location of buffer
	int flag; // mode of file access 
	int fd;
}FILE;

extern FILE _iob[OPEN_MAX];
#define stdin (%_iob[0])
#define stdout (%_iob[1])
#define stderr (&_iob[2])

enum _flags{
	_READ = 01, //file open for reading
	_WRITE = 02, //file open for writing
	_UNBUF = 04, //file is unbuffered
	_EOF = 010, // EOF has occurred on this file
	_ERR = 020 //error occurred on this file
};

int _fillbuf(FILE *);
int _flushbuf(int,FILE *);

#define feof(p) (((p)->flag & _EOF) != 0)
#define ferror(p) (((p)->flag & _ERR) != 0)
#define fileno(p) ((p)->fd)

#define getc(p) (--(p)->cnt >= 0 \
			  ? (unsigned char) *(p)->ptr++ : _fillbuf(p))

#define putc(x,p) (--(p)->cnt >= 0 \
			? *(p)->ptr++ = (x) : _flushbuf((x),p))


#define getchar() getc(stdin)
#define putchar(x) putc((x),stdout)




FILE *fopen(char *name,char *mode){
	int fd;
	FILE *fp;
	if(*mode != 'r' && *mode != 'w' && *mode != 'a')
		return NULL;
	for(fp = _iob;fp < _iob + OPEN_MAX;fp++)
		if((fp->flag) & (_READ | _WRITE) == 0)
			break; //found free slot
	if(fp >= _iob + OPEN_MAX) // no free slots
		return NULL;
	if(*mode == 'w')
		fd = creat(name,PERMS);
	else if(*mode == 'a')
		if((fd = open(name,O_RDONLY,0)) == -1)
			fd = creat(name,PERMS);
		lseek(fd,0L,2);
	else 
		fd = open(name,O_RDONLY,0);
	if(fd == -1) //couldn't access name
		return NULL;
	fp->fd = fd;
	fp->cnt = 0;
	fp->base = NULL;
	fp->flag = (*mode == 'r') ? _READ : _WRITE;
	return fp;
}

```


```c
#include "syscalls.h"
//get: read n bytes from position pos
int get(int fd,long pos,char *buf,int n){
    if(lseek(fd,pos,0) >= 0) //get to pos
        return read(fd,buf,n);
    else
        return -1;
}
```
```C
#include "syscalls.h"
//_fillbuf: allocate and fill input buffer
int _fillbuf(FILE *fp){
	int bufsize;
	if((fp->flag & (_READ | _EOF_ERR)) != _READ)
		return EOF;
	bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
	if(fp->base == NULL) //no buffer yet
		if(((fp->base) = (char *) malloc(bufsize)) == NULL)
			return EOF; //can't get buffer
	fp->ptr = fp->base;
	fp->cnt = read(fp->fd,fp->ptr,bufsize);
	if(--fp->cnt < 0){
		if(fp->cnt == -1)
			fp->flag |= _EOF;
		else 
			fp->flag |= _ERR;
		fp->cnt = 0;
		return EOF;
	}
	return (unsigned char) *fp->ptr++;
}


FILE _iob[OPEN_MAX] = { //stdin,stdout,stderr
	{0,(char *) 0,(char *) 0, _READ,0},
	{0,(char *) 0,(char *) 0, _WRITE,1},
	{0,(char *) 0,(char *) 0,_WRITE,|_UNBUF,2}
}
```


```C
//dirent.h
#define NAME_MAX 14 //longest filename component;system-dependent
typedef struct{  //portable directory entry
	long ino;   // inode number
	char name[NAME_MAX + 1];  //name + '\0' terminator
}Dirent;

typedef struct{ //minimal DIR: no buffering,etc
	int fd;  	//file descriptor for the directory
	Dirent d;   //the directory entry
}DIR;

DIR *opendir(char *dirname);
Dirent *readdir(DIR *dfd);
void closedir(DIR *dfd);

char *name;
struct stat stbuf;
int stat(char *,struct stat *);

//stat(name,&stbuf);
//fills the structure stbuf with the inode information for the file name.



#include <sys/stat.h>

struct stat{ //inode information returned by stat
	dev_t st_dev;//device of inode
	ino_t st_ino; //inode number
	short st_mode; //mode bits
	short st_nlink; //number of links to file
	short st_uid; //owners user id
	short st_gid; //owners group id
	dev_t st_rdev; //for special files
	off_t st_size; //file size in characters
	time_t st_atime; //time last accessed 
	time_t st_mtime; //time last modified
	time_t st_ctime; //time originally created
}

#define S_IFMT 0160000  //type if file: 
#define S_IFDIR 004000  //directory
#define S_IFCHR 002000  //character special
#define S_IFBLK 006000  //block special
#define S_IFREG 001000  //regular


#include <stdio.h>
#include <string.h>
#include "syscalls.h"
#include <fcntl.h> //flags for read and write
#include <sys/type.h> //typedefs
#include <sys/stat.h> //structure returned by stat
#include "direct.h"

void fsize(char *);
//print file name
main(int argc,char **argv){
	if(argc == 1) //default:current directory
		fsize(".");
	else 
		while(--argc > 0)
			fsize(*++argv);
	return 0;
}

int stat(char *,struct stat *);
void dirwalk(char *,void (*fcn)(char *));


//fsize: print the name of file "name"
void fsize(char *name){
	struct stat stbuf;
	if(stat(name,&stbuf) == -1){
		fprintf(stderr,"fsize:can't access %s\n",name);
		return;
	}
	if((stbuf.st_mode & S_IFMT) == S_IFDIR)
		dirwalk(name,fsize);
	printf("%8ld %s\n",stbuf.st_size,name);
}

#define MAX_PATH 1024
//dirwalk: apply fcn to all files in dir
void dirwalk(char *dir,void (*fcn)(char *)){
	char name[MXA_PATH];
	Dirent *dp;
	DIR *dfd;
	if((dfd = opendir(dir)) == NULL){
		fprintf(stderr,"dirwalk: can't open %s\n",dir);
		return;
	}
	while((dp = readdir(dfd)) != NULL){
		if(strcmp(dp->name,".") == 0 ||
			strcmp(dp->name,".."))
				continue; //skip self and parent
		if(strlen(dir) + strlen(dp->name) + 2 > sizeof(name))
			fprintf(stderr,"dirwalk: name %s %s too long \n",dir,dp->name);
		else{
			sprintf(name,"%s/%s",dir,dp->name);
			(*fcn)(name);
		}
	}
	closedir(dfd);
}

#include <sys/dir.h>
#ifndef DIRSIZ
#define DIRSIZ 14
#endif
struct direct{ //directory entry
	ino_t d_ino; //inode number
	char d_name[DIRSIZ]; //long name does not have '\0'
}
//information ino_t can be found in <sys/types.h>
//typedef is used to ensure the portability



int fstat(int fd,struct stat *);
//opendir: open a directory for readdir calls
DIR *opendir(char *dirname){
	int fd;
	struct stat stbuf;
	DIR *dp;
	if((fd = open(dirname,O_RDONLY,0)) == -1
		|| fstat(fd,&stbuf) == -1
		|| stbuf.st_mode & S_IFMT != S_IFDIR
		||(dp = (DIR *) malloc(sizeof(DIR))) == NULL)
		return NULL;
	dp->fd = fd;
	return dp;
}

//closedir: close directory opened by opendir
void closedir(DIR *dp){
	if(dp){
		close(dp-fd);
		free(dp);
	}
}

#include<sys/dir.h> //local directory structure
//readdir: read directory entries in sequence
Dirent *readdir(DIR *dp){
	struct dirent dirbuf; //local directory structure
	struct Dirent d; //return: portable structure
	while(read(dp->fd,(char *) &dirbuf,sizeof(dirbuf)) ==
			sizeof(dirbuf)){
		if(dirbuf.d_ino == 0) //slot not in use
			continue;
		d.ino = dirbuf.d_ino;
		strcpy(d.name,dirbuf.d_name,DIRSIZ);
		d.name[DIRSIZ] = '\0'; //ensure termination
		return &d;
	}
	return NULL;
}
```
```c
typedef long Align; // for alignment to long boundary

union header{ //block header
	struct{
		union header *ptr; //next block if on free list
		unsigned size; //size of this block;
	}s;
	Align x; //force alignment of blocks
};
//The Align field is never used;
//it just forces each header to be aligned on a worst - case boundary.

typedef union header Header;

static Header base; //empty list to get started
static Header *freep = NULL; //start of free list
//malloc: general-purpose storage allocator
void *malloc(unsigned nbytes){
	Header *p,*prevp;
	Header *moreroce(unsigned);
	unsigned nunits;
	nunits = (nbytes + sizeof(Header) - 1) / sizeof(header) + 1;
	if((prevp = freep) == NULL){ // no free list yet
		base.s.ptr = freeptr = prevptr = &base;
		base.s.size = 0;
	}	
	for(p = prevp->s.ptr; ;prevp = p,p = p->s.ptr){
		if(p->s.size >= nunits){ //big enough
			if(p->s.size == nunits) //exactlt
				prevp->s.ptr = p->s.ptr;
			else{ //allocate tail end
				p->s.size -= nunits;
				p += p->s.size;
				p->s.size = nunits;
			}
			freep = prevp;
			return (void *)(p+1);//真正存放data的空间的起始地址，+1代表加一个Header所占的总bytes，正好偏移到存储区的起始地址
		}
		if(p == freep) //wrapped around free list,空闲链表环转了一圈
			if((p = moreroce(nunits)) == NULL)
				return NULL;	// none left
	}
}

#define NALLOC 1024 //minimum #units to request
//morecore: ask system for more memory
static Header *morecore(unsigned nu){
	char *cp,*sbrk(int);
	Header *up;
	if(nu < NALLOC)
		nu = NALLOC;
	cp = sbrk(nu * sizeof(Header));
	if(cp == (char *) -1) //no space at a;;
		return NULL;
	up = (Header *) cp;
	up->s.size = nu;
	free((void *)(up + 1));
	return freep;
}


//free: put block ap in free list
void free(void *ap){
	Header *bp,*p;
	bp = (Header *)ap - 1; //point to block header
	for(p = freep;!(bp > p && bp < p->s.ptr);p = p->s.ptr){
		if(p >= p->s.ptr && (bp>p || bp < p->s.ptr))
			break;
	}
	if(bp + bp->s.size == p->s.ptr){ //join to upper nbt
		bp->s.size += p->s.ptr->s.size;
		bp->s.ptr = p->s.ptr->s.ptr;
	}
	else
		bp->s.ptr = p->s.ptr;
	if(p + p->s.size == bp){ //join to lower nbr
		p->s.size += bp->s.size;
		p->s.ptr = bp->s.ptr;
	}
	else 
		p->s.ptr = bp;
	freep = p;
}
```


references:
the c programming language


