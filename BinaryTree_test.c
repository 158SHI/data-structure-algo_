#define _CRT_SECURE_NO_WARNINGS 1

#include "Binarytree.h"

int main()
{
	BTNode* root = CreatTree();
	//PreOrder(root);
	//InOrder(root);
	//PostOrder(root);
	//printf("TreeSize = %d\n", TreeSize(root));
	//printf("%d %d\n", TreeKLevel(root, 2), TreeKLevel(root, 3));
	//printf("TreeDepth = %d\n", TreeDepth(root));
	LevelOrder(root);
	return 0;
}