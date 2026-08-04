#include <iostream>
#include <stack>

using namespace std;


class MinStack {

public:

    stack<int> st;
    stack<int> minSt;


    MinStack() {

    }


    void push(int val) {

        st.push(val);

        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }


    void pop() {

        if (st.top() == minSt.top()) {
            minSt.pop();
        }

        st.pop();
    }


    int top() {

        return st.top();
    }


    int getMin() {

        return minSt.top();
    }
};



int main() {

    MinStack obj;


    obj.push(-2);
    obj.push(0);
    obj.push(-3);


    cout << "Minimum: "
         << obj.getMin()
         << endl;


    obj.pop();


    cout << "Top: "
         << obj.top()
         << endl;


    cout << "Minimum: "
         << obj.getMin()
         << endl;


    return 0;
}