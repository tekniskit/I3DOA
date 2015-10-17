template<class T>
void insertionsort(T data[], const int n)
{
	int j, temp;

	for (int i = 0; i < n; i++)
	{
		j = i;

		while (j > 0 && data[j] < data[j - 1])
		{
			//temp = data[j];
			//data[j] = data[j - 1];
			//data[j - 1] = temp;
			swap(data[j], data[j - 1]);
			j--;
		}
	}
}


template<class T>
void quicksort(T data[], int first, int last) {
	int lower = first + 1, upper = last;
	swap(data[first], data[(first + last) / 2]);
	T bound = data[first];
	while (lower <= upper) {
		while (data[lower] < bound)
			lower++;
		while (bound < data[upper])
			upper--;
		if (lower < upper)
			swap(data[lower++], data[upper--]);
		else lower++;
	}
	swap(data[upper], data[first]);
	if (first < upper - 1)
		quicksort(data, first, upper - 1);
	if (upper + 1 < last)
		quicksort(data, upper + 1, last);
}

template<class T>
void quicksort(T data[], const int n) {
	int i, max;
	if (n < 2)
		return;
	for (i = 1, max = 0; i < n; i++)// find the largest
		if (data[max] < data[i])    // element and put it
			max = i;                // at the end of data[];
	swap(data[n - 1], data[max]); // largest el is now in its
	quicksort(data, 0, n - 2);     // final position;
}

template<class T>
void quicksort2(T data[], int first, int last, unsigned int bc) {
	if (last - first < bc)
	{
		insertionsort(data, (last - first));
		return;
	}
	int lower = first + 1, upper = last;
	swap(data[first], data[(first + last) / 2]);
	T bound = data[first];
	while (lower <= upper) {
		while (data[lower] < bound)
			lower++;
		while (bound < data[upper])
			upper--;
		if (lower < upper)
			swap(data[lower++], data[upper--]);
		else lower++;
	}
	swap(data[upper], data[first]);
	if (first < upper - 1)
		quicksort2(data, first, upper - 1, bc);
	if (upper + 1 < last)
		quicksort2(data, upper + 1, last, bc);
}

template<class T>
void quicksort2(T data[], const int n, unsigned int bc) {
	int i, max;
	if (n < 2)
		return;
	for (i = 1, max = 0; i < n; i++)// find the largest
		if (data[max] < data[i])    // element and put it
			max = i;                // at the end of data[];
	swap(data[n - 1], data[max]); // largest el is now in its
	quicksort2(data, 0, n - 2, bc);     // final position;
}