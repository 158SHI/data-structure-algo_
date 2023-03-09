#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

void test1(void)
{
    ListNode* newListHead = LTInit();
    ListPushBack(newListHead, 1);
    ListPushBack(newListHead, 2);
    ListPushBack(newListHead, 3);
    ListPushBack(newListHead, 4);
    ListPrint(newListHead);
    
    ListPopBack(newListHead);
    ListPopBack(newListHead);
    ListPrint(newListHead);
    
    ListPushFront(newListHead, 2);
    ListPushFront(newListHead, 3);
    ListPushFront(newListHead, 4);
    ListPushFront(newListHead, 5);
    ListPrint(newListHead);
}

void test2(void)
{
    ListNode* newListHead = LTInit();
    ListPushFront(newListHead, 2);
    ListPushFront(newListHead, 3);
    ListPushFront(newListHead, 4);
    ListPushFront(newListHead, 5);
    ListPrint(newListHead);
    
    ListPopFront(newListHead);
    ListPopFront(newListHead);
    ListPopFront(newListHead);
    
    ListPrint(newListHead);
}

void test3(void)
{
    ListNode* newListHead = LTInit();
    ListPushBack(newListHead, 1);
    ListPushBack(newListHead, 2);
    ListPushBack(newListHead, 3);
    ListPushBack(newListHead, 4);
    ListPushBack(newListHead, 5);
    
    ListPrint(newListHead);
    ListNode* pos = NULL;
//    if((pos = ListFind(newListHead, 3)))
//    {
//        printf("%d\n", pos->data);
//    }
    if((pos = ListFind(newListHead, 3)))
    {
        ListInsert(pos, 30);
    }
    ListPrint(newListHead);
    
    if((pos = ListFind(newListHead, 30)))
    {
        ListErase(pos);
    }
    ListPrint(newListHead);
    ListDestory(newListHead);
    
}

void test4(void)
{
    ListNode* newList = LTInit();
    ListPopBack(newList);
    ListPopFront(newList);
    ListPrint(newList);
    ListPushBack(newList, 1);
    ListPrint(newList);
}

int main()
{
    //test1();
    //test2();
    //test3();
    test4();
    return 0;
}
