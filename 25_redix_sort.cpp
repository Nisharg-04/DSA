#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter size of data : ";
    cin >> n;
    int arr[n];
    int max = 0;
    cout << "Enter data : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (max < arr[i])
            max = arr[i];
    }
    int temp = max;
    int c = 0;

    while (temp > 0)
    {
        c++;
        temp /= 10;
    }
    int div = 10;
    deque<deque<int>> a(10);
    for (int i = 0; i < c; i++)
    {
        deque<deque<int>> b(10);
        int k = 0;
        for (int j = 0; j < n; j++)
        {
            if (i == 0)
            {
                a[arr[j] % div].push_back(arr[j]);
            }
            else
            {
                while (true)
                {
                    if (a[k].empty())
                    {
                        k++;
                        continue;
                    }
                    else
                    {
                        b[(a[k].front() / 10) % 10].push_back(a[k].front());
                        a[k].pop_front();
                        break;
                    }
                }
            }
        }

        if (i != 0)
            a = b;
        div *= 10;
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        int k = 0;
        while (true)
        {

            if (a[k].empty())
            {
                k++;
                continue;
            }
            else
            {
                cout << " " << a[k].front() << " ";

                a[k].pop_front();
                break;
            }
        }
    }
}
