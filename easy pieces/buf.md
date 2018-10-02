
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


