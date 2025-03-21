#include <stdio.h>
#include <stdlib.h>

// ���嵥����ڵ�ṹ
typedef struct DoublyNode{
    int data;
    struct DoublyNode* prev;
    struct DoublyNode* next;
} DoublyNode;

//�����µĽڵ�
DoublyNode* createDoublyNode(int data){
	DoublyNode* newDoublyNode = (DoublyNode*)malloc(sizeof(DoublyNode));
	if (newDoublyNode == NULL) {
        printf("�ڴ����ʧ��\n");
        exit(1);
    }
    newDoublyNode->data = data;
    newDoublyNode->prev = NULL;
    newDoublyNode->next = NULL;
    return newDoublyNode;
}

//�ж��Ƿ�Ϊ��
int isEmpty(DoublyNode* head) {
    return head->next == NULL;
}

//��ͷ����ӽڵ�
void addHead(DoublyNode* head,int data){
	DoublyNode* newNode = createDoublyNode(data);
	DoublyNode* temp = head->next;
	if(temp) temp->prev = newNode;
	newNode->next = temp;
	newNode->prev = head;
	head->next = newNode;
}

//��β����ӽڵ�
void addTail(DoublyNode* head,int data){
	DoublyNode* newNode = createDoublyNode(data);
    DoublyNode* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    newNode->prev = temp;
    temp->next = newNode;
}

//ɾ�������е�ָ���ڵ�
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

//��ʾ����Ԫ��
void display(DoublyNode* head){
	while(head -> next){
		printf("%d <-> ",head -> next -> data);
		head = head->next;
	}
}

//��������
void freeDoublyNode(DoublyNode* head){
	DoublyNode* temp;
	while(head){
		temp = head;
		head = head->next;
		free(temp);
	}
} 
