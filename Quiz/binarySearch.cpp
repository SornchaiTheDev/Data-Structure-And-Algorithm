#include <iostream>
#include <cmath>

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

int binarySearch(int arr[], int n, int find)
{
  int count = 0;
  int min = 0;     // Corrected from 1 to 0
  int max = n - 1; // Corrected from n to n - 1
  int mid;

  while (min <= max)
  {
    mid = (min + max) / 2;

    if (arr[mid] == find)
    {
      count++;
      return count;
    }

    if (arr[mid] < find)
    {
      min = mid + 1;
    }
    else
    {
      max = mid - 1;
    }
    count++;
  }

  return -1;
}

int main()
{
  int arr[] = {1, 15, 5, 7, 10, 9, 10, 3, 45, 155, 56, 18, 88, 23, 99, 111, 100};
  bubbleSort(arr, 17);
  cout << "[ ";
  for (int i = 0; i < 17; i++)
  {
    cout << arr[i] << " ";
  }
  cout << "] ";

  cout << endl;
  int times = binarySearch(arr, 17, 5);

  cout
      << "Find 5 in array . Found in " << times << "times." << endl;
  times = binarySearch(arr, 17, 90);
  if (times == -1)
  {
    cout << "Find 90 in array . but Not found" << endl;
  }
  else
  {
    cout << "Find 90 in array . Found in " << times << "times." << endl;
  }
}