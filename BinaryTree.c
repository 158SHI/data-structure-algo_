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

}

void InOrder(BTNode* root)
{

}

void PostOrder(BTNode* root)
{

}

void TreeDepth(BTNode* root)
{
	
}

void TreeSize(BTNode* root)
{

}

void TreeKLevel(BTNode* root, int k)
{

}