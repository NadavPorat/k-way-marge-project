#include "minHeap.h"

namespace kway
{
	minHeap::minHeap(int size)
	{
		if (size <= 0)
		{
			throw  "Error heap size must be postive";
		}
		m_HeapLogSize = size;
		m_HeapPhzSize = 0;
		m_NodeArr = new minHeapNode[size];
	}

	void minHeap::FixHeap(int i_nodeIndex)
	{
		int min = 0;
		int left = Left(i_nodeIndex);
		int right = Right(i_nodeIndex);
		//Find the min between left and right.
		if (left < m_HeapPhzSize && m_NodeArr[left].GetVal() < m_NodeArr[i_nodeIndex].GetVal())
		{
			min = left;
		}
		else
		{
			min = i_nodeIndex;
		}
		if (right < m_HeapPhzSize && m_NodeArr[right].GetVal() < m_NodeArr[min].GetVal())
			min = right;
		if (min != i_nodeIndex)
		{
			SwapNodeHeap(&m_NodeArr[i_nodeIndex], &m_NodeArr[min]);
			FixHeap(min);
		}

	}

	void minHeap::SwapNodeHeap(minHeapNode* x, minHeapNode* y)
	{
		minHeapNode temp = *x;
		*x = *y;
		*y = temp;

	}

	void minHeap:: InsertNode(int i_Val, int* i_Arr, int i_SizeofArr)
	{
		// First insert the new key at the end

		minHeapNode ToInsert(i_Val, i_Arr, i_SizeofArr);
		int indexToInsert = m_HeapPhzSize ;
		this->m_NodeArr[indexToInsert ]=ToInsert;
		m_HeapPhzSize++;

		// Fix the min heap property if it is violated
		while (indexToInsert != 0 && m_NodeArr[parent(indexToInsert)].GetVal()>m_NodeArr[indexToInsert].GetVal())
		{
			SwapNodeHeap(&m_NodeArr[indexToInsert], &m_NodeArr[parent(indexToInsert)]);
			indexToInsert = parent(indexToInsert);
		}
	}

	int minHeap::DeleteMinHeap()
	{
		if (this->m_HeapPhzSize == 0)
		{
			throw "The heap is empty";
		}
		else
		{
			int val = -1;
			val = m_NodeArr[0].GetMinInArr();

			if ((m_NodeArr[0].GetIfOverAllArr())&&(m_HeapPhzSize > 1))
			{
				m_NodeArr[0] = m_NodeArr[m_HeapPhzSize - 1];
				m_HeapPhzSize--;
			
			}
			else if((m_HeapPhzSize == 1)&& (m_NodeArr[0].GetIfOverAllArr()))
			{
				m_HeapPhzSize--;
			}
			if (m_HeapPhzSize > 0)
			{
				FixHeap(0);
			}
			return val;
		}

	}
}