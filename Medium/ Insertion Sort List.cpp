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


ListNode* insertionSortList(ListNode* head) {

    ListNode* dummy = new ListNode(0);

    ListNode* current = head;


    while (current != nullptr) {

        ListNode* next = current->next;

        ListNode* prev = dummy;


        while (prev->next != nullptr &&
               prev->next->val < current->val) {

            prev = prev->next;
        }


        current->next = prev->next;

        prev->next = current;


        current = next;
    }


    return dummy->next;
}


void printList(ListNode* head) {

    while (head != nullptr) {

        cout << head->val << " ";

        head = head->next;
    }
}


int main() {

    // Input: 4 -> 2 -> 1 -> 3

    ListNode* head = new ListNode(4);

    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);


    head = insertionSortList(head);


    cout << "Sorted List: ";

    printList(head);


    return 0;
}