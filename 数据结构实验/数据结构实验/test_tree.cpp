#include<stdio.h>
#include"binSortedTree.h"
#include<string.h>

node* createNode();
tree* find(tree*t);

void menu()
{
	printf("<------------功能菜单----------->\n");
	printf("\t0.退出程序\n");
	printf("\t1.创建清单\n");
	printf("\t2.添加物品\n");
	printf("\t3.删除物品\n");
	printf("\t4.查找物品\n");
	printf("\t5.遍历清单\n");
}

void main() {

	tree* t;
	int i = 0;
	menu();
	while (true) {
		int T=0;
		printf("请选择功能:\n");
		scanf("%d", &T);
		if (T == 0) {
			printf("程序已退出\n");
			break;
		}
		switch (T) {
		case 1:
			if (i == 0) {
				t = init();
				i++;
				printf("创建清单完成\n");
			}
			else {
				printf("清单已经存在\n");
			}
			break;
		case 2:
			t = addNode(t, createNode());
			printf("商品添加成功\n");
			break;
		case 3:
			printf("请输入删除物品名称:\n");
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
			printf("无此功能\n");
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
	printf("请输入化妆品名称:\n");
	scanf("%s", name);
	printf("请输入化妆品价格:\n");
	scanf("%d", &price);
	strcpy(nod->name, name);
	nod->pric = price;
	return nod;
}

tree* find(tree*t) {
	printf("请输入查找的物品名称:\n");
	char name[10];
	scanf("%s", name);
	return findNode_name(t, name);
}