#pragma once
#include "General.h"

namespace kway
{
	int partition(int i_Arr[], int i_Low, int i_High);

	void quickSort(int i_Arr[], int i_Low, int i_High);

	int* SortMergeKArrays(int* i_ArrToSort, int i_SizeOfArray, int i_ValOfK);

	int** splitArr(int* i_ToSplitArr, int i_SizeOfArray, int i_ValOfK, int* i_SizeOfSubArr);

	int* mergeArr(int** i_SplitOrgArr, int i_SizeOfArray, int i_ValOfK, int* i_SizeOfSubArr);
}
