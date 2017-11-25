#include<stdio.h>
#include"List.h"
#include<string.h>

/*list* createList();
list* add(list* lis);
void findPerson(list* lis);
list* delPerson(list* lis);

void menu() {
	printf("菜单：\n");
	printf("1.创建通讯录\n");
	printf("2.添加联系人\n");
	printf("3.删除联系人\n");
	printf("4.查找联系人\n");
	printf("5.浏览联系人\n");
	printf("0.退出通讯录\n");
}*/

/*void main() {
	int T;
	list* lis;
	menu();
	int i = 0;
	while (true) {
		printf("请选择功能:\n");
		scanf("%d", &T);
		if (T == 0) {
			printf("程序退出!\n");
			break;
		}
			
		switch (T) {
		case 1:
			if (i>0) {
				printf("链表已经创建\n");
				break;
			}
			else {
				lis = createList();
				printf("通讯录创建成功\n");
				i++;
			}
			break;
		case 2:
			lis = add(lis);
			printf("联系人添加成功\n");
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
	printf("请输入联系人姓名:\n");
	scanf("%s", name);
	printf("请输入联系人性别:\n");
	scanf("%d", &sex);
	printf("请输入联系方式:\n");
	scanf("%d", &num);
	/*printf("请输入姓名，性别：\n");
	scanf("%s%c", name, &sex);
	printf("请输入联系方式:\n");
	scanf("%d", &num);*/
	return add_Person(lis, name, sex, num);
}

void findPerson(list* lis) {
	char name[10];
	printf("请输入联系人姓名:");
	scanf("%s", name);
	list *p = findNode_Name(lis, name);
	printPerson(p->p);
}

list* delPerson(list* lis) {
	char name[10];
	printf("请输入联系人姓名:");
	scanf("%s", name);
	list *p = delNode_Name(lis, name);
	return p;
}