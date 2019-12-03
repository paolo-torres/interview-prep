class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int result = 0;
        for (auto cur = s.begin(); cur != s.end(); ++cur) {
            auto nxt = next(cur);
            if (cur == prev(s.end())) {
                result += m[*cur];
            } else if (*cur == 'I' && (*nxt == 'V' || *nxt == 'X')) {
                result += m[*nxt] - m[*cur];
                ++cur;
            } else if (*cur == 'X' && (*nxt == 'L' || *nxt == 'C')) {
                result += m[*nxt] - m[*cur];
                ++cur;
            } else if (*cur == 'C' && (*nxt == 'D' || *nxt == 'M')) {
                result += m[*nxt] - m[*cur];
                ++cur;
            } else {
                result += m[*cur];
            }
        }
        return result;
    }
};
