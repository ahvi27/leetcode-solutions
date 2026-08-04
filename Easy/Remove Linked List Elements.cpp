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

ListNode* removeElements(ListNode* head, int val) {
    ListNode dummy(0);
    dummy.next = head;

    ListNode* curr = &dummy;

    while (curr->next != nullptr) {
        if (curr->next->val == val) {
            curr->next = curr->next->next;
        } else {
            curr = curr->next;
        }
    }

    return dummy.next;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
}

int main() {
    // Input:
    // 1 -> 2 -> 6 -> 3 -> 4 -> 6
    // Remove: 6

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(6);

    int val = 6;

    head = removeElements(head, val);

    printList(head);

    return 0;
}