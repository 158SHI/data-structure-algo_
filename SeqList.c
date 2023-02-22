#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

void SeqListInit(SeqList* ps)
{
	assert(ps);
	ps->a = (SLDateType*)malloc(sizeof(SLDateType) * INIT_CAPACITY);
	if (ps->a == NULL)
	{
		perror("SeqListInit::malloc");
		return;
	}
	ps->size = 0;
	ps->capacity = INIT_CAPACITY;
}

void SeqListDestroy(SeqList* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SeqListPrint(const SeqList* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void CheckCapaAndExp(SeqList* ps)
{
	if (ps->size == ps->capacity)
	{
		SLDateType* tmp = (SLDateType*)realloc(ps->a, sizeof(SLDateType) * ps->capacity * 2);
		if (tmp != NULL)
		{
			ps->a = tmp;
			ps->capacity *= 2;
		}
		else
		{
			perror("CheckCapaAndExp::realloc");
			return;
		}
	}
}

void SeqListPushBack(SeqList* ps, const SLDateType x)
{
	assert(ps);
	CheckCapaAndExp(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	if (ps->size == 0)
	{
		printf("The Sequence list is empty_\n");
		return;
	}
	ps->size--;
}

void SeqListPushFront(SeqList* ps, const SLDateType x)
{
	assert(ps);
	CheckCapaAndExp(ps);
	memmove(ps->a + 1, ps->a, sizeof(SLDateType) * ps->size);
	ps->a[0] = x;
	ps->size++;
}

void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	if (ps->size == 0)
	{
		printf("The Sequence list is empty_\n");
		return;
	}
	memmove(ps->a, ps->a + 1, sizeof(SLDateType) * (ps->size - 1));
	ps->size--;
}

int SeqListFind(SeqList* ps, const SLDateType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void SeqListInsert(SeqList* ps, const int pos, const SLDateType x)
{
	//在pos位置的前面插入
	assert(ps);
	CheckCapaAndExp(ps);
	memmove(ps->a + pos + 1, ps->a + pos, sizeof(SLDateType) * (ps->size - pos));
	ps->a[pos] = x;
	ps->size++;
}

void SeqListErase(SeqList* ps, const int pos)
{
	assert(ps);
	if (ps->size == 0)
	{
		printf("The Sequence list is empty_\n");
		return;
	}
	memmove(ps->a + pos, ps->a + pos + 1, sizeof(SLDateType) * (ps->size - pos - 1));
	ps->size--;
}