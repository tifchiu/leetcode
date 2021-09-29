class Solution {
public:
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
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        int left = 0;
        int right = intervals.size()-1;
        int prev = intervals.size();
        
        // run a binary search for where to put newInterval
    
        while (left <= right) {
            int mid = (left+right)/2;
            if (intervals[mid][0] < newInterval[0]) {
                left = mid+1;
            } else if (intervals[mid][0] > newInterval[0]) {
                prev = mid;
                right = mid-1;
            } else {
                prev = mid;
                break;
            }
        }
        
        intervals.insert(intervals.begin()+prev, newInterval);
        
        intervals = merge(intervals);
        return intervals;
    }
};