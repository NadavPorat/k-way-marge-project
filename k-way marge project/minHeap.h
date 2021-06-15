#pragma once
#include "General.h"
namespace kway
{

	class minHeap
	{
		private:
			minHeapNode* m_NodeArr;
			int m_HeapPhzSize;
			int m_HeapLogSize;

		public:

			// Constructor: creates a min heap of given size
			minHeap( int size);

			// Constructor: creates a min heap of given size
			~minHeap() { delete[] this->m_NodeArr; }

			//Insrt key to heap
			void InsertNode(int i_Val, int* i_Arr, int i_SizeofArr);

			// to get index of left child of node at index i
			int Left(int i) { return (2 * i + 1); }

			// to get index of right child of node at index i
			int Right(int i) { return (2 * i + 2); }

			// to get the root
			int GetMin() {return m_NodeArr[0].GetVal();}

			// to get the root
			int GetPhzSize() {return m_HeapPhzSize;}

			// to fIX HEAP by Algo learned in class
			void FixHeap(int node );

			// to fIX HEAP by Algo learned in class
			void SwapNodeHeap(minHeapNode* x, minHeapNode* y);

			// to get node per
			int parent(int i) { return (i - 1) / 2; }

			//delete min in the heap and return it
			int DeleteMinHeap();


	};

}