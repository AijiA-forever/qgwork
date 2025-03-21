#include <stdio.h>
#include <stdlib.h>

// 定义单链表节点结构
typedef struct Node {
    int data;
    struct Node* next;
} Node;

//创建新节点 
Node* createNode(int data){
	Node* newNode = (Node*)malloc(sizeof(Node));
	if(!newNode){
		printf("内存分配失败！");
		exit(1);
	}
	newNode -> data = data;
	newNode -> next = NULL;
	return newNode;
}

//判断链表是否为空
int isEmpty(Node* head){
	if(head -> next){
		return 0;
	}else{
		return 1;
	}
}

//在链表头部添加节点
void addHead(Node* head,int data){
	Node* newNode = createNode(data);
	newNode -> next = head -> next;
	head -> next = newNode;
}

//在链表尾部添加节点
void addTail(Node* head,int data){
	Node* newNode = createNode(data);
	Node* temp = head;
	while(temp -> next){
		temp = temp -> next;
	}
	temp -> next = newNode;
}

//删除指定节点
void deleteNode(Node* head,int data){
	Node* current = head;
    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }
    if(current->next != NULL){
    	Node* temp = current->next;
        current->next = temp->next;
        free(temp);
	}
}

//显示链表
void display(Node* head){
	Node* temp = head->next;
	while(temp){
		printf("%d -> ",head -> next);
		temp = temp->next;
	}
} 

//销毁链表
void freeList(Node* head){
	Node* temp;
	while(head){
		temp = head;
		head = head->next;
		free(temp);
	}
} 
