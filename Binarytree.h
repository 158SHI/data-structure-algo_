#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int BTDataTypt;

typedef struct BTNode
{
	BTDataTypt data;
	struct BTNode* leftChild;
	struct BTNode* rightChild;
}BTNode;

BTNode* BuyNode(BTDataTypt x);
BTNode* CreatTree(void);

void PreOrder(BTNode* root);
void InOrder(BTNode* root);
void PostOrder(BTNode* root);

void TreeDepth(BTNode* root);
void TreeSize(BTNode* root);
void TreeKLevel(BTNode* root, int k);