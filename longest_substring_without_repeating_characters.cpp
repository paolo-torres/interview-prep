class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }
        if (s.size() == 1) {
            return 1;
        }
        unordered_set <char> mySet;
        int curLength = 0;
        int maxLength = 0;
        auto it_temp = s.begin();
        for (auto it_str = s.begin(); it_str != s.end(); ++it_str) {
            auto it_set = mySet.find(*it_str);
            if (curLength == 1) {
                it_temp = it_str;
            }
            if (it_set != mySet.end()) {
                curLength = 1;
                mySet.clear();
                it_str = it_temp;
            } else {
                curLength++;
                if (curLength > maxLength) {
                    maxLength = curLength;
                }
            }
            mySet.insert(*it_str);
        }
        return maxLength;
    }
};
