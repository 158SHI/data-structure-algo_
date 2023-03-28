#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

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

int TreeDepth(BTNode* root);
int TreeSize(BTNode* root);
int TreeKLevel(BTNode* root, int k);

bool isSingleValTree(BTNode* root);

void LevelOrder(BTNode* root);