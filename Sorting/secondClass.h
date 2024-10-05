#include <bits/stdc++.h>
using namespace std;
class sorting
{
public:
    int *arr;
    int n;
    sorting()
    {
        cout << "Enter The Size of The Array" << endl;
        cin >> n;
        arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand();
        }
    }
    void bubbleSort()
    {

        for (int i = 0; i < n - 1; i++)
        {

            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
    void selectionSort()
    {
        for (int i = 0; i < n - 1; i++)
        {
            int minIdx = i;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] < arr[i])
                    minIdx = j;
            }
            swap(arr[i], arr[minIdx]);
        }
    }
    void insertionSort()
    {
        int i, j, key;
        for (int i = 1; i < n; i++)
        {
            j = i - 1;
            key = arr[i];
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
    void display()
    {
        for (int i = 0; i < n; i++)
        {

            cout << arr[i] << " ";
        }
    }
    void duration(int option)
    {
        auto start = chrono::high_resolution_clock::now();
        if (option == 1)
        {
            bubbleSort();
        }
        else if (option == 2)
        {
            selectionSort();
        }
        else
        {
            insertionSort();
        }
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = end - start;
        cout << "Execution Time :" << duration.count() << " seconds" << endl;
    }
};