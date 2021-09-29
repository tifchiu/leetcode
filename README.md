# Algorithms practice!
Tracking my progress on the [LeetCode Top Interview Questions](https://leetcode.com/problem-list/wpwgkgt/)

## Problems done:
### [Rotate Image](https://leetcode.com/problems/rotate-image/)
Given an `n x n` `matrix` representing an image, rotate the image by 90 degrees (clockwise).
- Perform a matrix transpose on `matrix` (i.e. flipping it along its diagonal)
- Reverse every row in the transposed matrix.
- Runtime: `O(n^2)` (or linear in the number of cells in `matrix`).
### [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
Given a string `s`, find the length of the longest substring without repeating characters.
- Utilize a sliding window algorithm and hashtable.
- Iterate through `s` exactly once. Start with a pointer `start` at the beginning of the string, and a `max_length` and `current_length` both initialized as 1.
- For each character `c` in `s`, if `c` has not yet occurred in our traversal of `s`, add `c` to the`c` hashtable with value equal to its index in `s`. Increment `current_length`.
- If `c` exists in the hashtable, we now have a repeated element. Compare `current_length` with `max_length` and take the larger to be the new `max_length`. Move `begin` past `hashtable[c]`, and update `hashtable[c]` to be the current index.
- Runtime: `O(n)` where `n` is the length of the string `s`.
### [Merge Intervals](https://leetcode.com/problems/merge-intervals/)
Given an array of `intervals` where `intervals[i] = [starti, endi]`, merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
- Preprocessing: sort `intervals` by `starti` using merge sort.
- Using a greedy algorithm, iterate through the array to find the largest `y` such that `intervals[i]` to `intervals[y]` are all in the same overlapping interval.
- Runtime: `O(n log n)`
### [Remove N-th Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)
Given the `head` of a linked list, remove the `n`-th node from the end of the list and return its head.
- Keep two pointers, `p1`, `p2` with `p2` at `n` nodes ahead of `p1`.
- When `p2` is at the end of the linked list, `p1->next` will be the `n`-th node from the end. Set `p1->next` to be `p1->next->next`.
- Runtime: `O(m)` where `m` is the size of the linked list.
### [Group Anagrams](https://leetcode.com/problems/group-anagrams/submissions/)
Given an array of strings `strs`, group the anagrams together.
- iterate through `strs` and sort each string. Store the sorted string in a map mapping to a vector of the strings in `strs` that are anagrams.
- Runtime: `O(n*k*log k)` where `k` is the length of the longest string. 
### [Pow(x,n)](https://leetcode.com/problems/powx-n)
Implement `x^n`.
- Use the [fast modular exponentiation](https://www.khanacademy.org/computing/computer-science/cryptography/modarithmetic/a/fast-modular-exponentiation) algorithm
- Runtime: `O(log n)`
### [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)
Given the `root` of a binary tree, determine if it is a valid binary search tree.
- Store node values in a list via an inorder, depth-first traversal of the binary tree.
- Determime whether the resulting list is sorted in strictly increasing order. If so, it is a valid BST.
- Runtime: `O(n)` where `n` is the number of nodes in the tree rooted at `root`.
### [Valid Parenthesis](https://leetcode.com/problems/valid-parentheses/)
Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid; that is, open brackets are closed by the same type of bracket, and open brackets are closed in the correct order.
- Iterate through `s` character by character. We will be utilizing a stack data structure.
- If we encounter an open bracket, push it onto the stack.
- If we encounter a closed bracket and the top of the stack is its corresponding opening bracket, then pop the stack. Otherwise, return `false` as `s` is already invalid.
- If we iterate fully through `s` and the stack is non-empty, return `false`. Otherwise, return `true`.
- Runtime: `O(n)` where `n` is the length of `s`.
### [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)
Given two non-empty linked lists `LL1` and `LL2` representing two non-negative integers - where the digits are stored in reverse order, and each node contains a single digit - add the two numbers and return the sum as a linked list. We can assume that there are no leading zeros except for the number `0` itself.
- In regular addition we start adding from the least significant digit and the carry-over moves on to the next digit. Since the linked list stores digits from most to least significant, we flip this logic.
- While both linked lists are non-empty, we construct the `next` node for the resulting linked list as `LL1->val + LL2->val + carry_over`, and compute the next `carry_over`.
- WLOG, if `LL1` is empty and `LL2` is non-empty, we construct the `next` node as `LL2->val + carry_over` and compute the next `carry_over`.
- Runtime: `O(max{LL1.size(), LL2.size()})`

