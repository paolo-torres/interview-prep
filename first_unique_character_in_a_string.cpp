class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); i++) {
            auto it = m.find(s[i]);
            if (it != m.end()) {
                it->second++;
            } else {
                m.insert({s[i], 1});
            }
        }
        for (int i = 0; i < s.size(); i++) {
            auto it = m.find(s[i]);
            if (it->second == 1) {
                return i;
            }
        }
        return -1;
    }
};
