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
        stringstream stream(paragraph);
        unordered_set<string> s(banned.begin(), banned.end());
        unordered_map<string, int> m;
        int max = 0;
        string result;
        while (stream >> temp) {
            if (s.find(temp) == s.end()) {
                auto it = m.find(temp);
                if (it != m.end()) {
                    it->second++;
                    if (it->second > max) {
                        result = it->first;
                        max = it->second;
                    }
                } else {
                    m.insert({temp, 1});
                    if (m.size() == 1) {
                        it = m.find(temp);
                        result = it->first;
                        max = it->second;
                    }
                }
            }
        }
        return result;
    }
};
