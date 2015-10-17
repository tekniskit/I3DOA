#pragma once
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Sorting\quicksort.cpp"
#include "Sorting\Stopwatch.h"

using namespace std;



void shuffle(int *arr, size_t n)
{
	if (n > 1)
	{
		size_t i;
		srand(time(NULL));
		for (i = 0; i < n - 1; i++)
		{
			size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
			int t = arr[j];
			arr[j] = arr[i];
			arr[i] = t;
		}
	}
}

int main() {
	const int num = 260;
	int arr[num];
	for (int i = 0; i<num; i++){
		arr[i] = i;
	}
	shuffle(arr, num);
	Stopwatch watch;
	double timearray[num];
	double quicktime = 0;
	int arr2[num];
	memcpy(arr2, arr, num);
	
	watch.start();
	quicksort < int >(arr2, num);
	watch.stop();
	quicktime = watch.getDuration(Stopwatch::Resolution::NANOSECONDS);

	for (int i = 0; i < num; i++)
	{
		Stopwatch watch2;
		memcpy(arr2, arr, num);
		watch2.start();
		quicksort2 < int >(arr2, num, i);
		watch2.stop();
		timearray[i] = watch2.getDuration(Stopwatch::Resolution::NANOSECONDS);
	}

	for (int i = 0; i < num; i = i + 2)
	{
		cout << "Ratio with " << i << " basecase is: " << timearray[i]/quicktime << endl;
	}

	//insertionsort<int>(arr, num);

	

	//while (1);
	std::getchar();
	return 0;
}