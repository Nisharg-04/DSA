class CustomStack {
public:
    vector<int> arr;
    int size;
    int top;
    CustomStack(int maxSize) {
        size = maxSize;
        top = -1;
        arr.resize(maxSize);
    }

    void push(int x) {
        if (top == size - 1) {
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (top == -1) {
            return -1;
        }
        return arr[top--];
    }

    void increment(int k, int val) {
        int temp;
        if (k <=
         top) {
            temp = k - 1;

        } else {

            temp = top;
        }
        for (int i = 0; i <= temp; i++) {
            arr[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */