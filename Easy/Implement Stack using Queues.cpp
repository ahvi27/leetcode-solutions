#include <iostream>
#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q;

public:
    MyStack() {
    }

    void push(int x) {
        int size = q.size();

        q.push(x);

        // Move previous elements behind x
        while (size--) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack st;

    st.push(1);
    st.push(2);
    st.push(3);

    cout << "Top: " << st.top() << endl;

    cout << "Pop: " << st.pop() << endl;
    cout << "Pop: " << st.pop() << endl;

    cout << "Is Empty: " << (st.empty() ? "true" : "false") << endl;

    return 0;
}