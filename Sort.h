#pragma once

#include <stdio.h>
#include <stdbool.h>

void PrintArr(int* nums, int n);

// ֱ�Ӳ�������
void InsertSort(int* a, int n);

// ϣ������
void ShellSort(int* a, int n);

//ֱ��ѡ������
void SelectSort(int* a, int n);

//������
void HeapSort(int* a, int n);

//ð������
void BubbleSort(int* a, int n);

// ��������hoare�汾
void PartSort1(int* a, int left, int right);