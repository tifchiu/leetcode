# Algorithms practice!
Tracking my progress on the [LeetCode Top Interview Questions](https://leetcode.com/problem-list/wpwgkgt/)

## Problems done:
### [Pow(x,n)](https://leetcode.com/problems/powx-n)
Implement `x^n`.
- Use the [fast modular exponentiation](https://www.khanacademy.org/computing/computer-science/cryptography/modarithmetic/a/fast-modular-exponentiation) algorithm
- Runtime: `O(log n)`
### [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)
Given the `root` of a binary tree, determine if it is a valid binary search tree.
- Store node values in a list via an inorder, depth-first traversal of the binary tree.
- Determime whether the resulting list is sorted in strictly increasing order. If so, it is a valid BST.
- Runtime: `O(n)` where `n` is the number of nodes in the tree rooted at `root`.
