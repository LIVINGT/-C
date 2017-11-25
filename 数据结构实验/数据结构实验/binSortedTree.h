#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct CosmeticNode {
	char name[10];
	int pric;
}node;

typedef struct binSortedTree {
	node *P_Cosmetic;
	binSortedTree *parent;
	binSortedTree *left;
	binSortedTree *right;
} tree;

tree *init() {
	return NULL;
}

tree* insert(tree* t, tree* t2) {
	tree *t1 = t;
	tree *t_p = t->parent;
	while (t1) {
		if (t1->P_Cosmetic->pric > t2->P_Cosmetic->pric) {
			t_p = t1;
			t1 = t1->left;
		}
		//if (t1->P_Cosmetic->pric <= t2->P_Cosmetic->pric) 
		else{
			t_p = t1;
			t1 = t1->right;
		}
	}
	//printf("",);
	if (t_p->P_Cosmetic->pric > t2->P_Cosmetic->pric) {
		t_p->left = t2;
		t2->parent = t_p;
		t2->left = NULL;
		t2->right = NULL;
	}
	else {
		t_p->right = t2;
		t2->parent = t_p;
		t2->left = NULL;
		t2->right = NULL;
	}
	return t;
}

tree* addNode(tree* bintree, node *node) {
	tree* t = bintree;
	tree* t2 = (tree*)malloc(sizeof(tree));
	t2->P_Cosmetic = node;
	if (!t) {
		t2->left = NULL;
		t2->right = NULL;
		t2->parent = NULL;
		t = t2;
		return t;
	}
	return insert(t, t2);
}

tree* findNode_name(tree* t, char name[]) {
	tree* p = t;
	if (!p) {
		return NULL;
	}
	if (strcmp(p->P_Cosmetic->name, name) == 0)
		return p;
	if (strcmp(p->P_Cosmetic->name, name) != 0) {

		if (findNode_name(p->left, name) != NULL)
			return findNode_name(p->left, name);
		if (findNode_name(p->right, name))
			return findNode_name(p->right, name);
	}
	return NULL;
}

tree* delNode(tree* t, char name[])
{
	tree *temp=t;
	tree *p = findNode_name(temp, name);
	if (!p) {
		printf("没有该商品!");
		return t;
	}
	if (!p->parent) {
		tree* q;
		q = p->right;
		while (q->left) {
			q = q->left;
		}
		q->parent = NULL;
		q->left = p->left;
		p->left->parent = q;
		p->left = NULL;
		p->right = NULL;
		free(p);
	}
	else if (p->left == NULL&&p->right == NULL) {
		if (p->parent->left == p)
			p->parent->left = NULL;
		if (p->parent->right == p)
			p->parent->right = NULL;
		p->parent = NULL;
		free(p);
	}
	else {
		tree* q = p->right;
		while (q->left)
			q = q->left;
		if (!q->parent->right) {
			q->left = p->left;
			q->right = p->right;
			q->parent->left = NULL;
			q->parent = p->parent;
			p->parent = NULL;
			p->left = NULL;
			p->right = NULL;
			free(p);
		}
		else{
			q->left = p->left;
			q->right->right = p->right;
			q->parent->left = NULL;
			q->parent = p->parent;
			p->parent = NULL;
			p->left = NULL;
			p->right = NULL;
			free(p);
		}
	}
	printf("删除成功\n");
	return temp;
}

void printNode(CosmeticNode *node) {
	printf("%s\t", node->name);
	printf("%d\n", node->pric);
}

void display(tree* t) {
	if (!t) {
		printf("empty!\n");
		return;
	}
	tree* p = t;
	if (p->left) {
		display(p->left);
	}
	printNode(p->P_Cosmetic);
	if (p->right) {
		display(p->right);
	}
}
