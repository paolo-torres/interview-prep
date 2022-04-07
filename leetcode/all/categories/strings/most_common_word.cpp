class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        for (int i = 0; i < paragraph.size(); i++) {
            if (isalpha(paragraph[i])) {
                paragraph[i] = tolower(paragraph[i]);
            } else {
                paragraph[i] = ' ';
            }
        }
        string temp;
        stringstream str(paragraph);
        unordered_set<string> s(banned.begin(), banned.end());
        unordered_map<string, int> m;
        while (str >> temp) {
            if (s.find(temp) == s.end()) {
                auto it = m.find(temp);
                if (it != m.end()) {
                    it->second++;
                } else {
                    m.insert({temp, 1});
                }
            }
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>> pq;
        for (auto it = m.begin(); it != m.end(); it++) {
            pq.push({it->second, it->first});
        }
        return pq.top().second;
    }
};
