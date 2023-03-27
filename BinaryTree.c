#define _CRT_SECURE_NO_WARNINGS 1

#include "Binarytree.h"

BTNode* BuyNode(BTDataTypt x)
{
	BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
	assert(newNode);
	newNode->data = x;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;
	return newNode;
}

BTNode* CreatTree(void)
{
	BTNode* n1 = BuyNode(1);
	BTNode* n2 = BuyNode(2);
	BTNode* n3 = BuyNode(3);
	BTNode* n4 = BuyNode(4);
	BTNode* n5 = BuyNode(5);
	BTNode* n6 = BuyNode(6);

	n1->leftChild = n2;
	n1->rightChild = n3;
	n2->leftChild = n4;
	n3->leftChild = n5;
	n3->rightChild = n6;

	return n1;
}

void PreOrder(BTNode* root)
{
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	printf("%d ", root->data);
	PreOrder(root->leftChild);
	PreOrder(root->rightChild);
}

void InOrder(BTNode* root)
{
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	InOrder(root->leftChild);
	printf("%d ", root->data);
	InOrder(root->rightChild);
}

void PostOrder(BTNode* root)
{
	if (root == NULL) {
		printf("NULL ");
		return;
	}

	PostOrder(root->leftChild);
	PostOrder(root->rightChild);
	printf("%d ", root->data);
}

int TreeDepth(BTNode* root)
{
	if (root == NULL) {
		return 0;
	}

	int leftDepth = TreeDepth(root->leftChild);
	int rightDepth = TreeDepth(root->rightChild);

	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

int TreeSize(BTNode* root)
{
	if (root == NULL) {
		return 0;
	}

	return TreeSize(root->leftChild) + TreeSize(root->rightChild) + 1;
}

int TreeKLevel(BTNode* root, int k)
{
	if (root == NULL) {
		return 0;
	}
	if (k == 1) {
		return 1;
	}
	return TreeKLevel(root->leftChild, k - 1) +
		TreeKLevel(root->rightChild, k - 1);
}

bool isSingleValTree(BTNode* root)
{
	if (root == NULL) {
		return true;
	}

	if (root->leftChild && 
			root->data != root->leftChild->data) {
		return false;
	}
	if (root->rightChild && 
			root->data != root->rightChild->data) {
		return false;
	}

	return isSingleValTree(root->leftChild) && 
			isSingleValTree(root->rightChild);
}