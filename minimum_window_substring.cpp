class Solution {
public:
    string minWindow(string s, string t) {
        string result;
        if (s.empty() || t.empty()) {
            return result;
        }
        unordered_map<char, int> m;
        unordered_map<char, int> window;
        for (int i = 0; i < t.size(); i++) {
            m[t[i]]++;
        }
        int count = 0;
        int minLength = INT_MAX;
        for (int left = 0, right = 0; right < s.size(); right++) {
            char c = s[right];
            if (m.find(c) != m.end()) {
                window[c]++;
                if (window[c] <= m[c]) {
                    count++;
                }
            }
            if (count >= t.size()) {
                while (m.find(s[left]) == m.end() || window[s[left]] > m[s[left]]) {
                    window[s[left]]--;
                    left++;
                }
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    result = s.substr(left, minLength);
                }
            }
        }
        return result;
    }
};
