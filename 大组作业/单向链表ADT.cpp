#include <stdio.h>
#include <stdlib.h>

// ���嵥����ڵ�ṹ
typedef struct Node {
    int data;
    struct Node* next;
} Node;

//�����½ڵ� 
Node* createNode(int data){
	Node* newNode = (Node*)malloc(sizeof(Node));
	if(!newNode){
		printf("�ڴ����ʧ�ܣ�");
		exit(1);
	}
	newNode -> data = data;
	newNode -> next = NULL;
	return newNode;
}

//�ж������Ƿ�Ϊ��
int isEmpty(Node* head){
	if(head -> next){
		return 0;
	}else{
		return 1;
	}
}

//������ͷ����ӽڵ�
void addHead(Node* head,int data){
	Node* newNode = createNode(data);
	newNode -> next = head -> next;
	head -> next = newNode;
}

//������β����ӽڵ�
void addTail(Node* head,int data){
	Node* newNode = createNode(data);
	Node* temp = head;
	while(temp -> next){
		temp = temp -> next;
	}
	temp -> next = newNode;
}

//ɾ��ָ���ڵ�
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

//��ʾ����
void display(Node* head){
	Node* temp = head->next;
	while(temp){
		printf("%d -> ",head -> next);
		temp = temp->next;
	}
} 

//��������
void freeList(Node* head){
	Node* temp;
	while(head){
		temp = head;
		head = head->next;
		free(temp);
	}
} 
