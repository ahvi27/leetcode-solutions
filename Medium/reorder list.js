var reorderList = function(head) {
    if (!head || !head.next) return;

    // Step 1: Find middle
    let slow = head;
    let fast = head;

    while (fast.next && fast.next.next) {
        slow = slow.next;
        fast = fast.next.next;
    }

    // Step 2: Reverse second half
    let second = slow.next;
    slow.next = null;

    let prev = null;

    while (second) {
        let next = second.next;
        second.next = prev;
        prev = second;
        second = next;
    }

    // prev is the head of reversed second half
    let first = head;
    second = prev;

    // Step 3: Merge two halves
    while (second) {
        let firstNext = first.next;
        let secondNext = second.next;

        first.next = second;
        second.next = firstNext;

        first = firstNext;
        second = secondNext;
    }
};