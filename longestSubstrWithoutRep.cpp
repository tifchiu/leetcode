class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;
        map<char, int> hashtable;
        hashtable[s[0]] = 0;
        int max_len = 1;
        int begin = 0;
        int cur_len = 1;
    
        for (int i = 1; i < s.length(); i++) {
            if ((s.length()-begin) <= max_len) break;
            try {
                int index = hashtable.at(s[i]);
                if (index >= begin) {
                    if (cur_len > max_len) max_len = cur_len;
                    begin= index+1;
                    cur_len = i-begin+1;
                } else {
                    cur_len++;
                }
                hashtable[s[i]] = i;
            
            } catch (const std::out_of_range& oor) {
                cur_len++;
                hashtable[s[i]] = i;
            }
        }
        if (cur_len >= max_len) return cur_len;
        return max_len;
    }
};