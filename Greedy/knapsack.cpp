#include <bits/stdc++.h>
using namespace std;
class item
{
    int weight;
    int value;

public:
    item()
    {
        weight = 0;
        value = 0;
    }
    item(int a, int b)
    {
        weight = a;
        value = b;
    }
    int getWeight()
    {
        return weight;
    }
    int getValue()
    {
        return value;
    }
};
class knapsack
{
    int size;
    item *arr;
    int maxWeight;

public:
    knapsack()
    {
        size = 0;
        maxWeight = 0;
        arr = NULL;
    }
    knapsack(int s, int m)
    {
        size = s;
        maxWeight = m;
        arr = new item[size];
    }
    void generateItems()
    {

        int x = 10, y = 20;
        for (int i = 0; i < size; i++)
        {
            // int a, b;
            // cout << "Enter The Weight and Value for item " << (i + 1) << endl;
            // cin >> a >> b;
            arr[i] = item(x + rand() % 10, y + rand() % 10);
        }
    }

    void printItems()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i].getValue() << " " << arr[i].getWeight() << " " << (double)arr[i].getValue() / (double)arr[i].getWeight() << endl;
        }
    }

    double getMaxValue()
    {

        double totalVal = 0;
        for (int i = 0; i < 5; i++)
        {
            if (arr[i].getWeight() <= maxWeight)
            {
                totalVal += arr[i].getValue();
                cout << "if" << arr[i].getValue() << endl;
                maxWeight -= arr[i].getWeight();
            }
            else
            {
                cout << "else" << arr[i].getValue() << endl;
                totalVal += ((double)arr[i].getValue() / (double)arr[i].getWeight()) * maxWeight;
                break;
            }
        }
        return totalVal;
    }
    item *getItems()
    {
        return arr;
    }
    int getSize()
    {
        return size;
    }
};
bool vbyw(item a, item b)
{
    if ((double)a.getValue() / (double)a.getWeight() >= (double)b.getValue() / (double)b.getWeight())
    {
        return true;
    }
    return false;
}
bool w(item a, item b)
{
    if (a.getWeight() <= b.getWeight())
    {
        return true;
    }
    return false;
}
bool v(item a, item b)
{
    if (a.getValue() >= b.getValue())
    {
        return true;
    }
    return false;
}

int main()
{
    int s, m;
    cout << "Enter Size and Max Weight :";
    cin >> s >> m;
    knapsack k(s, m);
    k.generateItems();
    // cout << "1. By Value" << endl;
    // sort(k.getItems(), k.getItems() + k.getSize(), v);
    // k.printItems();
    // cout << k.getMaxValue() << endl;
    // cout << "2. By Weight" << endl;
    // sort(k.getItems(), k.getItems() + k.getSize(), w);
    // k.printItems();
    // cout << k.getMaxValue() << endl;
    cout << "3. By Value By Weight" << endl;
    sort(k.getItems(), k.getItems() + k.getSize(), vbyw);
    k.printItems();
    cout << k.getMaxValue() << endl;

    return 0;
}