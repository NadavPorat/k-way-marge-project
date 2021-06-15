#include "kWaySort.h"

namespace kway
{
    void quickSort(int i_Arr[], int i_Low, int i_High)
    {
        if (i_Low < i_High)
        {
            /* pi is partitioning index, arr[p] is now
               at right place */
            int pi = partition(i_Arr, i_Low, i_High);

            quickSort(i_Arr, i_Low, pi - 1);
            quickSort(i_Arr, pi + 1, i_High);
        }
    }

    int partition(int i_Arr[], int i_Low, int i_High)
    {

        int pivot = i_Arr[i_High];
        int i = (i_Low - 1);

        for (int j = i_Low; j <= i_High - 1; j++)
        {
            if (i_Arr[j] <= pivot)
            {
                i++;
                std::swap(i_Arr[i], i_Arr[j]);
            }
        }
        std::swap(i_Arr[i+1], i_Arr[i_High]);
        return (i + 1);
    }

    int* SortMergeKArrays(int* i_ArrToSort, int i_SizeOfArray, int i_ValOfK)
    {
        if (i_SizeOfArray <=i_ValOfK || i_ValOfK==1)
        {
            quickSort(i_ArrToSort, 0, i_SizeOfArray-1);
       
            return i_ArrToSort;
        }
        else
        {
            int* sizeOfEachSubArr= new int[i_ValOfK];
            int** split = splitArr(i_ArrToSort, i_SizeOfArray, i_ValOfK, sizeOfEachSubArr); 

            for (int i = 0; (i < i_ValOfK) ; ++i)
            {
                split[i]= SortMergeKArrays(split[i], sizeOfEachSubArr[i], i_ValOfK);
            }

            int* resArr = mergeArr(split, i_SizeOfArray, i_ValOfK, sizeOfEachSubArr);

            for (int i=0;i< i_ValOfK; ++i)
            {
                delete[]  split[i];
            }
            delete[]  split;

            return resArr;
        }
    }

    int** splitArr(int* i_ToSplitArr, int i_SizeOfArray, int i_ValOfK, int* i_SizeOfSubArr)
    {
        int currNum = 0;
        int numInSubArr = 0;;
        int valSizeDivK = i_SizeOfArray / i_ValOfK;
        int** split = new int* [i_ValOfK];
        int curry = i_SizeOfArray % i_ValOfK;
     
        if (curry != 0)
        {
            valSizeDivK++;
        }
        

        for (int j = 0; j < i_ValOfK; j++)
        {
            split[j] = new int[valSizeDivK];
             numInSubArr = 0;

            for (int s = 0; s < valSizeDivK && currNum <i_SizeOfArray; s++, currNum++)
            {
                split[j][s] = i_ToSplitArr[currNum];
                numInSubArr++;
            }
            curry--;
            if (curry == 0)
            {
                valSizeDivK--;
            }
            i_SizeOfSubArr[j] = numInSubArr;
            
        }

        return split;
    }


    int* mergeArr(int** i_SplitOrgArr, int i_SizeOfArray, int i_ValOfK, int* i_SizeOfSubArr)
    {
        minHeap heap(i_ValOfK);
        int currNum = 0;
        int* resultArr = new int[i_SizeOfArray];

        for (int i = 0; i < i_ValOfK; i++)
        {
            heap.InsertNode(i_SplitOrgArr[i][0], i_SplitOrgArr[i], i_SizeOfSubArr[i]);
            
        }

        while ((heap.GetPhzSize() > 0) && (currNum < i_SizeOfArray))
        {

            resultArr[currNum] = heap.DeleteMinHeap();
            currNum++;
        }
     

        return resultArr;
    }

}
