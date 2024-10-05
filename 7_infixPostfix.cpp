#include <iostream>
#include <string>
using namespace std;

template<class T>
class stack
{
    T *arr;
    int top, size;
public:
    stack(int size)
    {
        this->size= size;
        top = -1;
        arr = new T[size];
    }
    bool isEmpty()
    {
        if(top == -1)
            return 1;
        else
            return 0;
    }
    bool isFull()
    {
        if(top == size - 1)
            return 1;
        else
            return 0;
    }
    void push(T ele)
    {
        if(isFull())
            cout << "Stack overflow" << endl;
        else
            arr[++top] = ele;
    }
    T pop()
    {
        if(isEmpty())
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        else
            return arr[top--];
    }
    T stackTop()
    {
        return arr[top];
    }
};

int isOperator(char ch)
{
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return 1;
    else
        return 0;
}

int popOrNot(char st, char ch)
{
    if(st == '+' || st == '-')
    {
        if(ch == '+' || ch == '-')
            return 1;
        else
            return 0;
    }
    else if(st == '*' || st == '/')
    {
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
            return 1;
        else
            return 0;
    }
    else if(st == '^')
    {
        if(ch == '^')
            return 0;
        else
            return 1;
    }
    return 0;
}

int main()
{
    string in;
    cin >> in;
    stack<char> s(50);
    string out;
    for(int i = 0; i < in.length(); i++)
    {
        if(isOperator(in[i]))
        {
            while(!s.isEmpty() && popOrNot(s.stackTop(), in[i]))
            {
                char temp = s.pop();
                out.push_back(temp);
            }
            s.push(in[i]);
        }
        else
        {
            out.push_back(in[i]);
        }
    }
    while(!s.isEmpty())
    {
        char temp = s.pop();
        out.push_back(temp);
    }
    cout << out << endl;
}
