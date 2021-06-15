#pragma once

namespace kway
{

	class minHeapNode
	{

	private:
		int m_NodeVal;
		int* m_arrOfNode;
		int m_SizeOfArr;
		int m_IndexOfCurrValue; /// we move the index each time we get min of arr

	public:
		minHeapNode();
		minHeapNode(int i_NodeVal, int* i_PointerToArr, int i_SizeOfArr);
		minHeapNode(const minHeapNode& other);
		int GetVal() { return m_NodeVal; }
		int GetSizeOfARR() { return m_SizeOfArr; }
		int GetIndexOfCurrVal() { return m_IndexOfCurrValue; }
		bool GetIfOverAllArr() {return(m_SizeOfArr == m_IndexOfCurrValue);}
		int GetMinInArr();
		minHeapNode& operator=(const minHeapNode& other);
	};

}