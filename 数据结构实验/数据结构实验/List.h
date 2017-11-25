#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>

typedef struct Person {
	char p_Name[10];
	int p_Sex;
	int p_Tel;
} person;

typedef struct Node {
	person *p;
	Node *next;
	Node *front;
} list;

list* init() {
	return NULL;
}

list* add_Person(list* lis, char name[], int sex, int num) {
	list *p = lis;
	list *q = (list*)malloc(sizeof(list));
	person *temp = (person*)malloc(sizeof(person));
	strcpy(temp->p_Name, name);
	temp->p_Sex = sex;
	temp->p_Tel = num;
	q->p = temp;
	if (!p) {
		q->next = NULL;
		q->front = NULL;
		p = q;
		return p;
	}
	while (p->next) {
		p = p->next;
	}
	p->next = q;
	q->front = p;
	q->next = NULL;
	return lis;
}

list* add_Person_i(list* lis,char name[],int sex,int num,int i) {
	list *p = lis;
	list*q = (list*)malloc(sizeof(list));
	person *temp = (person*)malloc(sizeof(person));
	strcpy(temp->p_Name, name);
	temp->p_Sex = sex;
	temp->p_Tel = num;
	q->p = temp;
	if (i == 0) {
		if (!p) {
			q->front = NULL;
			q->next = NULL;
			p = q;
			return p;
		}
		else {
			p->front = q;
			q->front = NULL;
			q->next = p;
			return q;
		}
	}
	else {
		if (!p) {
			printf("empty!\n");
			return lis;
		}else{
			while (i&&p->next) {
				p = p->next;
				i--;
			}
			if (i > 0) {
				printf("找不到位置\n");
				return lis;
			}
			else if (p->next) {
				p->next = q;
				q->next = NULL;
				q->front = p;
				return lis;
			}
			else {
				q->next = p->next;
				q->front = p->next->front;
				p->next = q;
				p->next->front = q;
				return lis;
			}
		}
	}
}

list* delEndNode(list* lis) {
	list* p = lis;
	if (!p) {
		printf("empty!\n");
		return NULL;
	}
	while (p->next) {
		p = p->next;
	}
	p->front->next = NULL;
	p->front = NULL;
	p->next = NULL;
	free(p);
	return lis;
}

list* findNode_Name(list* lis, char name[]) {
	list* p = lis;
	if (!p) {
		printf("empty!\n");
		return NULL;
	}
	while (p&&strcmp(p->p->p_Name,name)!=0) {
		p = p->next;
	}
	if (!p) {
		printf("没有找到联系人!\n");
		return NULL;
	}
	return p;
}

list* delNode_Name(list* lis, char name[]) {
	list *q = lis;
	list *p = findNode_Name(q, name);
	p->front->next = p->next;
	p->next->front = p->front;
	p->next = NULL;
	p->front = NULL;
	free(p);
	printf("该联系人删除成功\n");
	return q;
}

void printPerson(person* p)
{
	printf("%s\t", p->p_Name);
	printf("%d\t", p->p_Sex);
	printf("%d\n", p->p_Tel);
}

void display(list *lis)
{
	
	if (lis==NULL) {
		printf("empty!\n");
		return;
	}
	else {
		list *p = lis;
		while (p) {
			printPerson(p->p);
			p = p->next;
		}
	}
}