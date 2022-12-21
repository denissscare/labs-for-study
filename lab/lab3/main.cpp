#include<iostream>
#include <ctime>
#include <cstdlib>

using namespace std; 


static inline unsigned long long int tick()
{
	unsigned long long int d;
	__asm __volatile__("rdtsc" : "=A" (d));
	return d;
}

unsigned long long int start = 0;
unsigned long long int finish = 0;

#define SPEED_START start = tick();
#define SPEED_FINISH finish = tick();

void fillArray(int*, int, int, int);
void printArr(int*, int);
void bubbleSort(int*, int);
void insertionSort(int*, int);
void uniqueArray(int*, int);


int main() {
	int n = 0;
	int a = 0;
	int b = 100;
	cout << "enter the size: ";
	cin >> n;
	cout << "enter the range [a, b]:\na: ";
	cin >> a;
	cout << "b: ";
	cin >> b;

	cout << "\n\n";

 	int *arr = new int[n];

	fillArray(arr, n, a, b);
	cout << "Filled array: ";
	printArr(arr, n);
	cout << "\n";
	bubbleSort(arr, n);
	cout << "bubbleSort: ";
	printArr(arr, n);
	cout << "SPEED: " << finish - start << endl;

	cout << "\n\n";

	fillArray(arr, n, a, b);
	cout << "Filled array: ";
	printArr(arr, n);
	cout << "\n";
	insertionSort(arr, n);
	cout << "insertionSort: ";
	printArr(arr, n);
	cout << "SPEED: " << finish - start << endl;
	cout << "\n\n";

	uniqueArray(arr, n);
	cout << "Unique array: ";
	printArr(arr, n);

	delete[] arr;

	return 0;
}




void bubbleSort(int *array, int size) {
	SPEED_START;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (array[j] > array[j + 1]) {
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	SPEED_FINISH;
}

void insertionSort(int* array, int size) {
	SPEED_START;
	int temp, 
		item; 
	for (int counter = 1; counter < size; counter++)
	{
		temp = array[counter]; 
		item = counter - 1; 
		while (item >= 0 && array[item] > temp) 
		{
			array[item + 1] = array[item]; 
			array[item] = temp;
			item--;
		}
	}
	SPEED_FINISH; 
}

void printArr(int* array, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

void fillArray(int* array, int size, int a, int b) {
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % (b - a + 1) + a;
	}
}

void uniqueArray(int* array, int size) {
	int j = 0, r = 0;
	while (++j < size)
		if (array[r] != array[j] && ++r != j)
			array[r] = array[j];
}