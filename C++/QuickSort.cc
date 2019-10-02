//Swap function
template <typename T>
void swap(T* A, int i, int j)
{
	T tmp = A[i];
	A[i] = A[j];
	A[j] = tmp;
};

//Partition function
template <typename T>
int partition(T *A, int first, int last)
{
	//mid piviot avoids worst case scenario
	int pivot = first + (last-first)/2;
	swap(A, pivot, last);
	for(int i = first; i < last; i++)
	{
		if(A[i] <= A[last])
		{
			swap(A, first, i);
			first++;
		}
	}
	swap(A, first, last);
	return first;
};

//Quicksort function
template <typename T>
void QuickSort(T *A, int firstIndex, int lastIndex)
{
	if(firstIndex < lastIndex)
	{
		int pivot = partition(A, firstIndex, lastIndex);
		QuickSort(A, firstIndex, pivot-1);
		QuickSort(A, pivot+1, lastIndex);
	}
};
