class Solution {
public:
    int firstUniqChar(string s) {
        if (s.empty()) {
            return -1;
        }
        unordered_map<char, int> myMap;
        for (int i = 0; i < s.size(); i++) {
            auto it = myMap.find(s[i]);
            if (it != myMap.end()) {
                it->second++;
            } else {
                myMap.insert({s[i], 1});
            }
        }
        int result = -1;
        for (int i = 0; i < s.size(); i++) {
            auto it = myMap.find(s[i]);
            if (it != myMap.end() && it->second == 1) {
                result = i;
                break;
            }
        }
        return result;
    }
};
