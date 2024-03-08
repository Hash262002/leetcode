# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    node1 = None
    node2 = None
    prev = TreeNode(-10000000000000)

    def inorder(self, root):
        if root == None:
            return
        self.inorder(root.left)
        if self.node1 == None and root.val < self.prev.val:
            self.node1 = self.prev
        if self.node1 != None and root.val < self.prev.val:
            self.node2 = root
        self.prev = root
        self.inorder(root.right)

    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        self.inorder(root)
        self.node1.val, self.node2.val = self.node2.val, self.node1.val
