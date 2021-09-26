class Solution {
public:
    
    vector<vector<int>> MSmerge(vector<vector<int>> left, vector<vector<int>> right) {
        vector<vector<int>> result;
        int left_index = 0;
        int right_index = 0;
        
        while (left_index < left.size() && right_index < right.size()) {
            if (left[left_index] < right[right_index]) {
                result.push_back(left[left_index]);
                left_index++;
            } else {
                result.push_back(right[right_index]);
                right_index++;
            }
        }
        while (left_index < left.size()) {
            result.push_back(left[left_index]);
            left_index++;
        }
        while (right_index < right.size()) {
            result.push_back(right[right_index]);
            right_index++;
        }
        return result;
    }
    
    vector<vector<int>> mergesort(vector<vector<int>>& intervals) {
        
        //base case
        if (intervals.size() == 1) return intervals;
        int mid = intervals.size()/2;
        
        auto left = vector<vector<int>>(intervals.begin(), intervals.begin() + mid);
        auto right = vector<vector<int>>(intervals.begin() + mid, intervals.end());
        
        left = mergesort(left);
        right = mergesort(right);
        
        
        return MSmerge(left,right);
    }
    
    pair<int,int> greedy(int start, vector<vector<int>>& intervals) {
        int index = start;
        int upper = intervals[index][1];
        
        while (index <= intervals.size()-2 && (intervals[index+1][0] <= upper)) {
            upper = max(upper,max(intervals[index][1], intervals[index+1][1]));
            index++;
        }
        return pair<int,int>(index,upper);
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        intervals = mergesort(intervals);
        vector<vector<int>> result;
        
        if (intervals.size() == 1) return intervals;
        
        for (int i = 0; i < intervals.size(); i++) {
            pair<int,int> temp = greedy(i,intervals);
            vector<int> interval = {intervals[i][0], temp.second};
            result.push_back(interval);
            if (i != temp.first) i = temp.first;
        }
        return result;
    }
};