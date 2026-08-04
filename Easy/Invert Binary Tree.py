from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def invertTree(self, root):
        if root is None:
            return None

        # Swap left and right children
        root.left, root.right = root.right, root.left

        # Recursively invert subtrees
        self.invertTree(root.left)
        self.invertTree(root.right)

        return root


# -----------------------
# Helper Functions
# -----------------------

def buildTree(values):
    """Build binary tree from level-order list (use None for missing nodes)."""
    if not values:
        return None

    root = TreeNode(values[0])
    queue = deque([root])
    i = 1

    while queue and i < len(values):
        node = queue.popleft()

        if i < len(values) and values[i] is not None:
            node.left = TreeNode(values[i])
            queue.append(node.left)
        i += 1

        if i < len(values) and values[i] is not None:
            node.right = TreeNode(values[i])
            queue.append(node.right)
        i += 1

    return root


def levelOrder(root):
    """Return tree as level-order list."""
    if not root:
        return []

    result = []
    queue = deque([root])

    while queue:
        node = queue.popleft()

        if node:
            result.append(node.val)
            queue.append(node.left)
            queue.append(node.right)
        else:
            result.append(None)

    while result and result[-1] is None:
        result.pop()

    return result


# -----------------------
# Driver Code
# -----------------------

if __name__ == "__main__":
    # Example input:
    # 4 2 7 1 3 6 9
    values = input("Enter tree in level order (use 'None' for nulls): ").split()

    arr = []
    for x in values:
        if x.lower() == "none":
            arr.append(None)
        else:
            arr.append(int(x))

    root = buildTree(arr)

    sol = Solution()
    inverted = sol.invertTree(root)

    print("Inverted Tree:", levelOrder(inverted))