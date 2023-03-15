#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

ListNode* BuyNode(LTDataType x)
{
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if(newNode == NULL)
    {
        perror("BuyNode::malloc");
        return NULL;
    }
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

bool ListEmpty(ListNode* pHead)
{
    assert(pHead);
    return pHead->next == pHead;
}

ListNode* LTInit(void)
{
    ListNode* newList = BuyNode(0);
    if(newList == NULL)
    {
        perror("LTInit::BuyNode");
        return NULL;
    }
    newList->data = 0;
    newList->prev = newList;
    newList->next = newList;
    return newList;
}

//void ListPushBack(ListNode* pHead, LTDataType x)
//{
//    assert(pHead);
//    ListNode* newNode = BuyNode(x);
//    ListNode* tail = pHead->prev;
//    tail->next = newNode;
//    newNode->prev = tail;
//    newNode->next = pHead;
//    pHead->prev = newNode;
//}

void ListPushBack(ListNode* pHead, LTDataType x)
{
    assert(pHead);
    ListInsert(pHead, x);
}

//void ListPopBack(ListNode* pHead)
//{
//    assert(pHead);
//    if(ListEmpty(pHead)) {
//        return;
//    }
//    ListNode* tail = pHead->prev;
//    ListNode* prevNode = tail->prev;
//    prevNode->next = pHead;
//    pHead->prev = prevNode;
//    free(tail);
//    tail = NULL;
//}

void ListPopBack(ListNode* pHead)
{
    assert(pHead);
    if(ListEmpty(pHead)) {
        return;
    }
    ListErase(pHead->prev);
}

void ListPrint(ListNode* pHead)
{
    assert(pHead);
    ListNode* cur = pHead->next;
    while(cur != pHead)
    {
        printf("%d<->", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

//void ListPushFront(ListNode* pHead, LTDataType x)
//{
//    assert(pHead);
//    ListNode* nextNode = pHead->next;
//    ListNode* newNode = BuyNode(x);
//    pHead->next = newNode;
//    newNode->prev = pHead;
//    newNode->next = nextNode;
//    nextNode->prev = newNode;
//}

void ListPushFront(ListNode* pHead, LTDataType x)
{
    assert(pHead);
    ListInsert(pHead->next, x);
}

//void ListPopFront(ListNode* pHead)
//{
//    assert(pHead);
//    assert(!ListEmpty(pHead));
//    ListNode* head = pHead->next;
//    ListNode* newHead = pHead->next->next;
//    pHead->next = newHead;
//    newHead->prev = pHead;
//    free(head);
//}

void ListPopFront(ListNode* pHead)
{
    assert(pHead);
    if(ListEmpty(pHead)) {
        return;
    }
    ListErase(pHead->next);
}

ListNode* ListFind(ListNode* pHead, LTDataType x)
{
    assert(pHead);
    ListNode* cur = pHead->next;
    while(cur != pHead)
    {
        if(cur->data == x) {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

void ListInsert(ListNode* pos, LTDataType x)
{
    assert(pos);
    ListNode* preNode = pos->prev;
    ListNode* newNode = BuyNode(x);
    preNode->next = newNode;
    newNode->prev = preNode;
    newNode->next = pos;
    pos->prev = newNode;
}

void ListErase(ListNode* pos)
{
    assert(pos);
    ListNode* prevNode = pos->prev;
    ListNode* nextNode = pos->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    free(pos);
}

void ListDestory(ListNode* pHead)
{
    assert(pHead);
    while(!ListEmpty(pHead))
    {
        ListPopFront(pHead);
    }
    free(pHead);
}
