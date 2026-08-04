#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};


bool hasCycle(ListNode* head) {

    if (head == nullptr)
        return false;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}


int main() {

    // Creating linked list: 3 -> 2 -> 0 -> -4
    //                        ^          |
    //                        |__________|

    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    // Create cycle
    head->next->next->next->next = head->next;

    if (hasCycle(head))
        cout << "Cycle detected" << endl;
    else
        cout << "No cycle" << endl;

    return 0;
}