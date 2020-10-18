class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<int, char>> v;
        for (int i = 0; i < s.size(); i++) {
            if (v.empty() || v.back().second != s[i]) {
                v.push_back(make_pair(1, s[i]));
            } else {
                v.back().first++;
                if (v.back().first == k) {
                    v.pop_back();
                }
            }
        }
        string result;
        for (int i = 0; i < v.size(); i++) {
            result.append(v[i].first, v[i].second);
        }
        return result;
    }
};
