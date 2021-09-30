class Solution {
public:
    
    int binSearchLeft(int left, int right, vector<int> & nums, int target) {
        if (left == right && nums[left] == target) return left;
        while (left < right) {
            int mid = (left + right)/2;
            if (nums[mid] < target) {
                return binSearchLeft(mid+1, right, nums, target);
            } else {
                return binSearchLeft(left, mid, nums, target);
            }
        }
        return -1;
    }
    
    int binSearchRight(int left, int right, vector<int> & nums, int target) {
        if (left == right && nums[left] == target) return left;
        while (left < right) {
            int mid = (left+right+1)/2;
            if (nums[mid] > target) {
                return binSearchRight(left, mid-1, nums, target);
            } else {
                return binSearchRight(mid, right, nums, target);
            }     
        }
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> none = {-1,-1};
        
        if (nums.size() == 1) {
            if (nums[0] != target) return none;
            vector<int> temp = {0,0};
            return temp;
        }
        
        int left = binSearchLeft(0, nums.size()-1, nums, target);
        int right = binSearchRight(0, nums.size()-1, nums, target);
        
        if (left > right) return none;
        
        vector<int> ret = {left, right};
        
        return ret;
    }
};