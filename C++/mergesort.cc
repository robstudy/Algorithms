//MERGE and MERGESORT
template <typename T>
void merge(T *A, int low, int mid, int high)
{
	int i, j, k;
	int n1 = mid - low + 1;
	int n2 = high - mid;
	
	//temp arrays left and right
	T* L = new T[n1];
	T* R = new T[n2];
	
	//Copy data temp arrays L[] and R[]
	for(i = 0; i < n1; i++)
		L[i] = A[low+i];
	for(j = 0; j < n2; j++)
		R[j] = A[mid+1+j];
	
	//Merge the temp arrays back into A[low..high]
	i = 0; //Initial index of first sub-array
	j = 0; //Initial index of second sub-array
	k = low; //Initial index of merged sub-array
	
	while(i < n1 && j < n2)
	{
		if(L[i] <= R[j])
		{
			A[k] = L[i];
			i++;
		}
		else 
		{
			A[k] = R[j];
			j++;
		}
		k++;
	}
	
	//Copy the remaining elements of L[], if there are any
	while(i < n1)
	{
		A[k] = L[i];
		i++; 
		k++;
	}
	
	//Copy the remaining elements of R[], if there are any
	while(j < n2)
	{
		A[k] = R[j];
		j++;
		k++;
	}
	
	delete[] R;
	delete[] L;
};

template <typename T>
void MergeSort(T *A, int low, int high)
{
	int mid;
	
	//Check for base case
	if(low < high)
	{
		//First, divide in half
		mid = low + (high - low)/2;
		
		//First recursive call
		MergeSort(A, low, mid);
		//Second recursive call
		MergeSort(A, mid+1, high);
		//The merge function call
		merge(A, low, mid, high);
	}
};
