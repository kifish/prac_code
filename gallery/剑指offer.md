```C
#include<cstdio>

struct ListNode{
    int v;
    ListNode* next;
}
void add_to_tail(ListNode** head,int value){
    ListNode* new_node = new ListNode();
    new_node->v = value;
    new_node->next = NULL;

    if(*head == NULL){
        *head = new_node;
    }
    else{
        ListNode* cur_node = *head;
        while (cur_node->next != NULL)
            cur_node = cur_node->next;
        cur_node->next = new_node;
    }
}
```





```c
#include<cstdio>

struct ListNode{
    int v;
    ListNode* next;
}

void remove_node(ListNode** head,int value){
    if(head == NULL || *head == NULL) return;
    ListNode* to_be_deleted = NULL;
    if((*head)->v == value){
        to_be_deleted = *head;
        *head = (*head)->next;
    }
    else{
        ListNode* cur_node = *head;
        while(cur_node->next != NULL && cur_node->next->v != value)
            cur_node = cur_node->next;
        if(cur_node->next != NULL && cur_node->next->v == value){
            to_be_deleted = cur_node->next;
            cur_node->next = cur_node->next->next;
        }
    }

    if(to_be_deleted != NULL){
        delete to_be_deleted;
        to_be_deleted = NULL;
    }
}
```

```C
#include<cstdio>

struct ListNode{
    int v;
    ListNode* next;
}

void print_reverse_list(ListNode* head){
    std::stack<ListNode*> nodes;
    ListNode* cur_node = head;
    while(cur_node != NULL){
        nodes.push(cur_node);
        cur_node = cur_node->next;
    }
    while(!nodes.empty()){
        cur_node = nodes.top()
        printf('%d\t',cur_node->v);
        nodes.pop();
    }
}
```

```c
#include<cstdio>

struct ListNode{
    int v;
    ListNode* next;
}

void print_reverse_list(ListNode* head){
    if(head != NULL){
        if(head->next != NULL){
            print_reverse_list(head->next);
        }
        printf("%d\t",head->v);
    }
}
```


```C
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

void print_digits(char* num) {
	bool first = true;
	int len = strlen(num);
	for (int i = 0; i < len; i++) {
		if (!first) {
			putchar(num[i]);
		}
		if (num[i] != '0' && first) {
			first = false;
			putchar(num[i]);
		}
	}
	//0
	if (first) {
		printf("0");
	}
	printf("\n");
}


void recursive(char* num, int len, int index) {
	if (index == len) {
		print_digits(num);
		return;
	}

	for (int i = 0; i < 10; i++) {
		num[index] = i + '0';
		recursive(num, len, index + 1);
	}
}

void print_nums(int n) {
    if(n <= 0) return;
	char* num = new char[n + 1];
	num[n] = '\0';
	for (int i = 0; i < 10; i++) {
		num[0] = i + '0';
		recursive(num, n, 1);
	}
    delete[] num;
}



int main() {
	int n;
	//scanf("%d", &n);
	cin >> n;
	print_nums(n);
	while (1);
	return 0;
}
```

