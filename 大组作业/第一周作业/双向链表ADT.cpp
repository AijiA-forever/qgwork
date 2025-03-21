#include <stdio.h>
#include <stdlib.h>

// 定义单链表节点结构
typedef struct DoublyNode{
    int data;
    struct DoublyNode* prev;
    struct DoublyNode* next;
} DoublyNode;

//创建新的节点
DoublyNode* createDoublyNode(int data){
	DoublyNode* newDoublyNode = (DoublyNode*)malloc(sizeof(DoublyNode));
	if (newDoublyNode == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    newDoublyNode->data = data;
    newDoublyNode->prev = NULL;
    newDoublyNode->next = NULL;
    return newDoublyNode;
}

//判断是否为空
int isEmpty(DoublyNode* head) {
    return head->next == NULL;
}

//在头部添加节点
void addHead(DoublyNode* head,int data){
	DoublyNode* newNode = createDoublyNode(data);
	DoublyNode* temp = head->next;
	if(temp) temp->prev = newNode;
	newNode->next = temp;
	newNode->prev = head;
	head->next = newNode;
}

//在尾部添加节点
void addTail(DoublyNode* head,int data){
	DoublyNode* newNode = createDoublyNode(data);
    DoublyNode* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    newNode->prev = temp;
    temp->next = newNode;
}

//删除链表中的指定节点
void deleteNode(DoublyNode* head,int data){
	DoublyNode* temp = head;
	while(temp->next != NULL && temp->next->data != data){
		temp = temp->next;
	}
	if(temp->next){
		temp = temp->next;
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		free(temp);
	}
}

//显示链表元素
void display(DoublyNode* head){
	while(head -> next){
		printf("%d <-> ",head -> next -> data);
		head = head->next;
	}
}

//销毁链表
void freeDoublyNode(DoublyNode* head){
	DoublyNode* temp;
	while(head){
		temp = head;
		head = head->next;
		free(temp);
	}
} 
