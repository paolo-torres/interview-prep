class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); i++) {
            m[s[i]]++;
        }
        vector<pair<char, int>> v;
        for (auto it = m.begin(); it != m.end(); ++it) {
            v.push_back(make_pair(it->first, it->second));
        }
        sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
            return a.second >= b.second;
        });
        string result = "";
        int i = 0;
        while (i < v.size()) {
            result.push_back(v[i].first);
            v[i].second--;
            if (v[i].second == 0) {
                i++;
            }
        }
        return result;
    }
};
