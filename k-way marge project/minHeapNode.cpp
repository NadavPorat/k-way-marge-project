#include "minHeapNode.h"

namespace kway
{
	minHeapNode::minHeapNode()
	{
		this->m_arrOfNode = new int();
		this->m_IndexOfCurrValue = 0;
		this->m_NodeVal = 0;
		this->m_SizeOfArr = 0;
	}

	minHeapNode::minHeapNode(int i_NodeVal, int* i_PointerToArr, int i_SizeOfArr)
	{
		this->m_NodeVal = i_NodeVal;
		this->m_arrOfNode = i_PointerToArr;
		this->m_SizeOfArr = i_SizeOfArr;
		this->m_IndexOfCurrValue = 0;

	}

	minHeapNode::minHeapNode(const minHeapNode& other)
	{
		m_NodeVal = other.m_NodeVal;
		m_arrOfNode = other.m_arrOfNode;
		m_SizeOfArr = other.m_SizeOfArr;
		m_IndexOfCurrValue = other.m_IndexOfCurrValue;
	}

	int minHeapNode::GetMinInArr()
	{
		int val = -1;
		if (m_IndexOfCurrValue == m_SizeOfArr )
		{
			throw  "End of Array";
		}
		val = m_arrOfNode[m_IndexOfCurrValue];
		m_IndexOfCurrValue++;
		m_NodeVal = m_arrOfNode[m_IndexOfCurrValue]; // we move to next val in arr

		return val;

	}
	minHeapNode& minHeapNode::operator=(const minHeapNode& other)
	{
		if (this != &other) {
			m_NodeVal = other.m_NodeVal;
			m_arrOfNode = other.m_arrOfNode;
			m_SizeOfArr = other.m_SizeOfArr;
			m_IndexOfCurrValue = other.m_IndexOfCurrValue;
		}
		return *this;
	
	}
}