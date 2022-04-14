// Given 2 strings s and t, determine if isomorphic
// Chars in s can be replaced to get t, preserve order

// 2-way mapping, return false if mapping doesn't match, or only 1 mapping exists

// Time: O(n)
// Space: O(n)

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> sMap;
        unordered_map<char, char> tMap;
        
        for (int i = 0; i < s.size(); i++) {
            // no mapping exists in either
            if (sMap.find(s[i]) == sMap.end() && tMap.find(t[i]) == tMap.end()) {
                sMap[s[i]] = t[i];
                tMap[t[i]] = s[i];
            // either mapping doesn't exist or doesn't match
            } else if (sMap[s[i]] != t[i] || tMap[t[i]] != s[i]) {
                return false;
            }
        }
        
        return true;
    }
};
