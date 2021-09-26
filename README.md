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
### [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)
Given two non-empty linked lists `LL1` and `LL2` representing two non-negative integers - where the digits are stored in reverse order, and each node contains a single digit - add the two numbers and return the sum as a linked list. We can assume that there are no leading zeros except for the number `0` itself.
- In regular addition we start adding from the least significant digit and the carry-over moves on to the next digit. Since the linked list stores digits from most to least significant, we flip this logic.
- While both linked lists are non-empty, we construct the `next` node for the resulting linked list as `LL1->val + LL2->val + carry_over`, and compute the next `carry_over`.
- WLOG, if `LL1` is empty and `LL2` is non-empty, we construct the `next` node as `LL2->val + carry_over` and compute the next `carry_over`.
- Runtime: `O(max{LL1.size(), LL2.size()})`
