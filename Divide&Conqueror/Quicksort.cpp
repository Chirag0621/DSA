#include <iostream>
using namespace std;
int partition(int arr[], int si, int ei)
{
    int i = si - 1;
    int pivot = arr[ei];
    for (int j = si; j < ei; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[ei]);
    return i;
}
void quicksort(int *arr, int si, int ei)
{
    if (si >= ei)
    {
        return;
    }
    int pivotIndex = partition(arr, si, ei);
    quicksort(arr, si, pivotIndex - 1);
    quicksort(arr, pivotIndex + 1, ei);
}
int main()
{
    int arr[] = {5, 9, 7, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, n - 1);
    cout << "Array after sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}