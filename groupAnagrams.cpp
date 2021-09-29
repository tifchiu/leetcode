class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> result;
        vector<string> unsorted(strs.begin(), strs.end());
        vector<vector<string>> ret;
        
        //sort all strings alphabetically
        for (int i = 0; i < strs.size(); i++) {
            sort(strs[i].begin(), strs[i].end());
            if (result.find(strs[i]) != result.end()) {
                // found
                result[strs[i]].push_back(unsorted[i]);
            } else {
                vector<string> temp = {unsorted[i]};
                result[strs[i]] = temp;
            }
        }
        
        for (auto v: result) {
            ret.push_back(v.second);
        }
        return ret;
    }
};