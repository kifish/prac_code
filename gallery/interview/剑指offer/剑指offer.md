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

```C
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct Node{
    Node* left;
    Node* right;
    char data;
};

Node* create(){
    Node* node = new Node();
    node->left = node->right = NULL;
    return node;
}

string a,b;
Node* build(int s1,int e1,int s2,int e2){
    char root_val = a[s1];
    Node* root = create();
    root->data = root_val;
    int root_idx = 0;
    for(int i = s2;i<=e2;i++){
        if(b[i] == root_val){
            root_idx = i;
            break;
        }
    }

    if(root_idx != s2){
        root->left = build(s1+1,s1+root_idx-e2,s2,root_idx-1);
    }
    if(root_idx != e2){
        root->right = build(s1+root_idx-s2+1,e1,root_idx+1,e2);
    }
    return root;
}

void postorder(Node* root){
    if(root->left)
        postorder(root->left);
    if(root->right)
        postorder(root->right);
    cout<<root->data;
}
int main() {
    while(cin>>a>>b){
     Node* tree = build(0,a.size()-1,0,b.size()-1);
     postorder(tree);
     cout<<endl;
    }
    return 0;
}
```

```c
struct ListNode{
    int value;
    ListNode* next;
};
void delete_node(ListNode** list_head, ListNode* to_be_delete){
    if(!list_head || !to_be_delete)
        return;

    //要删除的结点不是尾节点
    if(to_be_delete->next != NULL){
        ListNode* next_node = to_be_delete->next;
        to_be_delete->value = next_node->value;
        to_be_delete->next = next_node->next;

        delete next_node;
        next_node = NULL;
    }
    // 链表只有一个结点
    else if(*list_head == to_be_delete){
        delete to_be_delete;
        to_be_delete = NULL;
        *list_head = NULL;
    }
    //链表有多个结点，删除尾结点
    else{
        ListNode* cur_node = *list_head;
        while (cur_node->next != to_be_delete){
            cur_node = cur_node->next;
        }
        cur_node->next = NULL;
        delete to_be_delete;
        to_be_delete = NULL;
    }
}
```



```C
struct ListNode{
    int value;
    ListNode* next;
};

ListNode* find_kth_to_tail(ListNode* head, unsigned int k){
    if(head == NULL || k == 0){
        return NULL;
    }
    ListNode* node_ahead = head;
    ListNode* node_behind = NULL;
    for(unsigned int i = 0;i<k-1;i++){
        if(node_ahead->next != NULL){
            node_ahead = node_ahead->next;
        }
        else
            return NULL;
    }
    node_behind = head;
    while(node_ahead->next != NULL){
        node_ahead = node_ahead->next;
        node_behind = node_behind->next;
    }
    return node_behind;
}
```


```C
struct ListNode{
    int value;
    ListNode* next;
};

ListNode* reverse_list(ListNode* head){
    if(head == NULL) return NULL;

    ListNode* cur_node = head;
    ListNode* prev_node = NULL;
    ListNode* next_node;
    ListNode* reverse_list_head;
    while (cur_node != NULL){
        if(cur_node->next == NULL){
            reverse_list_head = cur_node;
        }
        next_node = cur_node->next;
        cur_node->next = prev_node;

        prev_node = cur_node;
        cur_node = next_node;
    }
    return reverse_list_head;
}
```

