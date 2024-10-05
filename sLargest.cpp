#include <bits/stdc++.h>
using namespace std;
int getSecondOrderElements(int n, vector<int> a)
{
    int largest = a[0];
    int slargest = -1;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > largest)
        {
            slargest = largest;
            largest = a[i];
        }
        else if (a[i] < largest && a[i] > slargest)
        {
            slargest = a[i];
        }
    }
    //       int smallest=a[0];
    //    int ssmallest=smallest;
    //    for(int i=0;i,a.size();i++){
    //        if(a[i]<smallest){
    //            ssmallest=smallest;
    //            smallest=a[i];

    //        }
    //    }
    //    vector<int> arr;
    //    arr.push_back(slargest);
    //    arr.push_back(ssmallest);
    return slargest;
}

int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(4);
    arr.push_back(2);
    arr.push_back(3);
    cout << getSecondOrderElements(5, arr);
    return 0;
}