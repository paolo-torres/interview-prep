class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_multiset<char> mySet;
        for (int i = 0; i < s.size(); i++) {
            mySet.insert(s[i]);
        }
        for (int i = 0; i < t.size(); i++) {
            auto it = mySet.find(t[i]);
            if (it == mySet.end()) {
                return false;
            } else {
                mySet.erase(it);
            }
        }
        return true;
    }
};
