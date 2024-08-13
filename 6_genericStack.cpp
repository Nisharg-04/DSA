#include<iostream>
using namespace std;

template <class T>
class stackS
{
    T *arr;
    int size, top;
public:
    stackS(int s)
    {
        size = s;
        top = -1;
        arr = new T[size];
    }
    void push(int ele)
    {
        if(top == size - 1)
        {
            cout << "Stack overflow" << endl;
        }
        else
        {
            arr[++top] = ele;
        }
    }
    T pop()
    {
        if(top == -1)
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        else
        {
            return arr[top--];
        }
    }
    void display()
    {
        for(int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    stackS<int> s(10);
    s.push(5);
    s.push(2);
    s.push(1);
    cout << s.pop() << endl;
    s.display();
    return 0;
}

