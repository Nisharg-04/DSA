#include <bits/stdc++.h>
#include "secondClass.h"
using namespace std;
class newSort : public sorting
{
public:
    void merge(int *arr, int low, int mid, int high)
    {
        int i = low;
        int j = mid + 1;
        vector<int> temp;
        while (i <= mid && j <= high)
        {
            if (arr[i] <= arr[j])
            {
                temp.push_back(arr[i]);
                i++;
            }
            else if (arr[j] < arr[i])
            {
                temp.push_back(arr[j]);
                j++;
            }
        }
        while (i <= mid)
        {
            temp.push_back(arr[i]);
            i++;
        }
        while (j <= high)
        {
            temp.push_back(arr[j]);
            j++;
        }
        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }
    }
    void mergeSort(int *arr, int low, int high)
    {
        if (low >= high)
            return;
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
    int partition(int *arr, int low, int high)
    {
        int key = arr[low];
        int i = low;
        int j = high;
        while (i < j)
        {
            while (arr[i] <= key && i <= high - 1)
            {
                i++;
            }
            while (arr[j] >= key && j >= low + 1)
            {
                j--;
            }
            if (i < j)
            {
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[low], arr[j]);
        return j;
    }
    void quickSort(int *arr, int low, int high)
    {
        if (low < high)
        {
            int pivot = partition(arr, low, high);
            quickSort(arr, low, pivot - 1);
            quickSort(arr, pivot + 1, high);
        }
    }
    void duration(int option)
    {
        auto start = chrono::high_resolution_clock::now();
        if (option == 1)
        {
            mergeSort(arr, 0, n - 1);
        }
        else
        {
            quickSort(arr, 0, n - 1);
        }
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = end - start;
        cout << "Execution Time :" << duration.count() << " seconds" << endl;
    }
};
int main()
{
    newSort s1;
    int option;
    cout << "Enter The Option:" << endl
         << "1. Merge Sort" << endl
         << "2. Quick Sort" << endl;
    cin >> option;
    s1.duration(option);
    // s1.display();
}
