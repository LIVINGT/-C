#include<stdio.h>
#include"binSortedTree.h"
#include<string.h>

node* createNode();
tree* find(tree*t);

void menu()
{
	printf("<------------���ܲ˵�----------->\n");
	printf("\t0.�˳�����\n");
	printf("\t1.�����嵥\n");
	printf("\t2.�����Ʒ\n");
	printf("\t3.ɾ����Ʒ\n");
	printf("\t4.������Ʒ\n");
	printf("\t5.�����嵥\n");
}

void main() {

	tree* t;
	int i = 0;
	menu();
	while (true) {
		int T=0;
		printf("��ѡ����:\n");
		scanf("%d", &T);
		if (T == 0) {
			printf("�������˳�\n");
			break;
		}
		switch (T) {
		case 1:
			if (i == 0) {
				t = init();
				i++;
				printf("�����嵥���\n");
			}
			else {
				printf("�嵥�Ѿ�����\n");
			}
			break;
		case 2:
			t = addNode(t, createNode());
			printf("��Ʒ��ӳɹ�\n");
			break;
		case 3:
			printf("������ɾ����Ʒ����:\n");
			char name[10];
			scanf("%s", name);
			t = delNode(t, name);
			break;
		case 4:
			printNode(find(t)->P_Cosmetic);
			break;
		case 5:
			display(t);
			break;
		default :
			printf("�޴˹���\n");
			break;
		}
	}

	
}


node* createNode()
{
	node* nod;
	nod = (node*)malloc(sizeof(node));
	char name[10];
	int price;
	printf("�����뻯ױƷ����:\n");
	scanf("%s", name);
	printf("�����뻯ױƷ�۸�:\n");
	scanf("%d", &price);
	strcpy(nod->name, name);
	nod->pric = price;
	return nod;
}

tree* find(tree*t) {
	printf("��������ҵ���Ʒ����:\n");
	char name[10];
	scanf("%s", name);
	return findNode_name(t, name);
}