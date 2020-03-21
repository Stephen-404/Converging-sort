#include <stdio.h>

int ar[8] = { 8, 7, 6, 5, 4, 3, 2, 1};

void swap(int i, int j)
{
	if (i != j && ar[i] != ar[j])
	{
		int temp;
		temp = ar[i];
		ar[i] = ar[j];
		ar[j] = temp;
	}
}

void SortEnds (int low, int high)
{
	int nLow = low, nHigh = high;
	for (int k = low; k <= high; k++)
	{
		if (ar[k] < ar[nLow])
			nLow = k;
		if (ar[k] > ar[nHigh])
			nHigh = k;
	}

	swap(nLow, low);

	if (low == nHigh) swap(nLow, high);
	else if (nLow == high) swap(nLow, nHigh);
	else swap(nHigh, high);
}

void ConvergingSort (int low, int high)
{
	if (low <= high)
	{
		SortEnds(low, high);
		ConvergingSort(low + 1, high - 1);
	}
}

void print()
{
	for (int i = 0; i < sizeof(ar) / sizeof(ar[0]); i++)
		printf("%d    ", ar[i]);
	printf("\n");
}

int main()
{
	ConvergingSort(0, sizeof(ar) / sizeof(ar[0]) - 1);
	print();
	return 0;
}
