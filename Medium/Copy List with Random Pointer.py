class Node:
    def __init__(self, x, next=None, random=None):
        self.val = x
        self.next = next
        self.random = random



class Solution:

    def copyRandomList(self, head):

        if head is None:
            return None


        mp = {}


        # Step 1: Create cloned nodes
        current = head

        while current:

            mp[current] = Node(current.val)

            current = current.next



        # Step 2: Connect pointers
        current = head

        while current:

            clone = mp[current]

            clone.next = mp.get(current.next)

            clone.random = mp.get(current.random)

            current = current.next



        return mp[head]



# Testing

if __name__ == "__main__":

    node1 = Node(7)
    node2 = Node(13)
    node3 = Node(11)

    node1.next = node2
    node2.next = node3

    node1.random = None
    node2.random = node1
    node3.random = node1


    sol = Solution()

    copied = sol.copyRandomList(node1)


    while copied:
        print(
            "Value:",
            copied.val,
            "Random:",
            copied.random.val if copied.random else None
        )

        copied = copied.next