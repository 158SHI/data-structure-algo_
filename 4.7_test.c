#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


struct ListNode
{
    int val;
    struct ListNode* next;    
};

 struct TreeNode
 {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };
 
    struct ListNode* GetMidNode(struct ListNode* left, struct ListNode* right)
{
    struct ListNode* fast = left;
    struct ListNode* slow = left;
    while (fast != right && fast->next != right)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

struct TreeNode* TreeBuild(struct ListNode* left, struct ListNode* right)
{
    //right始终指向尾节点的下一个位置
    if (left == right) {
        return NULL;
    }

    struct ListNode* midNode = GetMidNode(left, right);
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    assert(root);
    root->val = midNode->val;

    root->left = TreeBuild(left, midNode);
    root->right = TreeBuild(midNode->next, right);

    return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head)
{
    return TreeBuild(head, NULL);
}