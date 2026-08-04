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


ListNode* merge(ListNode* l1, ListNode* l2) {

    ListNode dummy(0);
    ListNode* curr = &dummy;


    while (l1 && l2) {

        if (l1->val <= l2->val) {

            curr->next = l1;
            l1 = l1->next;

        } else {

            curr->next = l2;
            l2 = l2->next;
        }

        curr = curr->next;
    }


    if (l1)
        curr->next = l1;

    if (l2)
        curr->next = l2;


    return dummy.next;
}



ListNode* sortList(ListNode* head) {

    if (head == nullptr || head->next == nullptr)
        return head;


    ListNode* slow = head;
    ListNode* fast = head->next;


    while (fast && fast->next) {

        slow = slow->next;
        fast = fast->next->next;
    }


    ListNode* mid = slow->next;
    slow->next = nullptr;


    ListNode* left = sortList(head);
    ListNode* right = sortList(mid);


    return merge(left, right);
}



void printList(ListNode* head) {

    while (head) {

        cout << head->val << " ";

        head = head->next;
    }
}



int main() {

    // 4 -> 2 -> 1 -> 3

    ListNode* head = new ListNode(4);

    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);


    head = sortList(head);


    cout << "Sorted List: ";

    printList(head);


    return 0;
}