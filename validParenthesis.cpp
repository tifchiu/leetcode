class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2 == 1) return false; 
        vector<char> seq;
        vector<char> open = {'(', '{', '['};
        
        for (int i = 0; i < s.length(); i++) {
            auto it = find(open.begin(), open.end(), s[i]);
            if (it != open.end()) {    // open bracket
                seq.push_back(s[i]);
            } else {                                // closed brack
                if (seq.size() == 0) return false;
                if (s[i] == ')') {
                    if (seq.back() == '(') {
                        seq.pop_back();
                    } else {
                        return false;
                    }
                } else if (s[i] == '}') {
                    if (seq.back() == '{') {
                        seq.pop_back();
                    } else {
                        return false;
                    }
                } else {
                    if (seq.back() == '[') {
                        seq.pop_back();
                    } else {
                        return false;
                    }
                }
            }
        }
        if (seq.size() != 0) {
            return false;
        }
        return true;
    }
};