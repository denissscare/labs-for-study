#include <iostream>
#include <time.h>

using namespace std;
void heapify(int arr[], int n, int i)
{
    int largest = i;   // root element
    int l = 2*i + 1; // left 
    int r = 2*i + 2; // right

 
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

void randomElements(int arr[], int n){
    srand(time(NULL));
    for(int i = 0; i < n; ++i){ 
        arr[i] = rand() % 100;
    }
}

int main()
{
    int size;    
    cout << "Enter size array :\n";
    cin >> size;
    
    int arr[size];
    randomElements(arr, size);

    cout << "Initial array: \n";
    printArray(arr, size);

    heapSort(arr, size);

    cout << "Sorted array \n";
    printArray(arr, size);
}