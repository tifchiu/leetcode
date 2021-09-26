/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool inorder_traverse(TreeNode* root, vector<int> & nums) {
        bool left = true;
        bool right = true;
        if (root == nullptr) return true;
        if (root->left != nullptr) left = inorder_traverse(root->left, nums);
        nums.push_back(root->val);
        // check for repeated elements
        if (nums.size() > 1) {
            if (nums[nums.size()-1] == nums[nums.size()-2]) return false;
        }
        if (root->right != nullptr) right = inorder_traverse(root->right, nums);
        return (left && right);
    }
    
    bool isValidBST(TreeNode* root) {
      // want to do inorder, depth first traversal
        vector<int> nums;
        bool result = inorder_traverse(root, nums);
        return (is_sorted(nums.begin(), nums.end()) && result);
    }
};