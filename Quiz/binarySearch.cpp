#include <iostream>
using namespace std;

void swap(int *xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void bubbleSort(int arr[], int n)
{
  int i, j;
  bool swapped;
  for (i = 0; i < n - 1; i++)
  {
    swapped = false;
    for (j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(&arr[j], &arr[j + 1]);
        swapped = true;
      }
    }

    if (swapped == false)
      break;
  }
}

int binarySearch(int arr[] , int n) {
  
}

int main()
{
  int arr[] = {1, 15, 5, 7, 10, 9, 10, 3, 45, 155, 56, 18, 88, 23, 99, 111, 100};
  bubbleSort(arr, 17);
  for (int i = 0; i < 17; i++)
  {
    cout << arr[i] << " ";
  }
}