#include<stdio.h>
#include"List.h"
#include<string.h>

/*list* createList();
list* add(list* lis);
void findPerson(list* lis);
list* delPerson(list* lis);

void menu() {
	printf("�˵���\n");
	printf("1.����ͨѶ¼\n");
	printf("2.�����ϵ��\n");
	printf("3.ɾ����ϵ��\n");
	printf("4.������ϵ��\n");
	printf("5.�����ϵ��\n");
	printf("0.�˳�ͨѶ¼\n");
}*/

/*void main() {
	int T;
	list* lis;
	menu();
	int i = 0;
	while (true) {
		printf("��ѡ����:\n");
		scanf("%d", &T);
		if (T == 0) {
			printf("�����˳�!\n");
			break;
		}
			
		switch (T) {
		case 1:
			if (i>0) {
				printf("�����Ѿ�����\n");
				break;
			}
			else {
				lis = createList();
				printf("ͨѶ¼�����ɹ�\n");
				i++;
			}
			break;
		case 2:
			lis = add(lis);
			printf("��ϵ����ӳɹ�\n");
			break;
		case 3:
			lis = delPerson(lis);
			break;
		case 4:
			findPerson(lis);
			break;
		case 5:
			display(lis);
			break;
		default:
			break;
		}

	}
}*/


/*list* createList() {
	list* lis;
	lis = init();
	return lis;
}*/

list *add(list* lis) {
	char name[10];
	int sex;	
	int num;
	printf("��������ϵ������:\n");
	scanf("%s", name);
	printf("��������ϵ���Ա�:\n");
	scanf("%d", &sex);
	printf("��������ϵ��ʽ:\n");
	scanf("%d", &num);
	/*printf("�������������Ա�\n");
	scanf("%s%c", name, &sex);
	printf("��������ϵ��ʽ:\n");
	scanf("%d", &num);*/
	return add_Person(lis, name, sex, num);
}

void findPerson(list* lis) {
	char name[10];
	printf("��������ϵ������:");
	scanf("%s", name);
	list *p = findNode_Name(lis, name);
	printPerson(p->p);
}

list* delPerson(list* lis) {
	char name[10];
	printf("��������ϵ������:");
	scanf("%s", name);
	list *p = delNode_Name(lis, name);
	return p;
}