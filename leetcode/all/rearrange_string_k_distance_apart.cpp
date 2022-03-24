// Greedily remove most freq, queue to simulate k dist

// Time: O(n)
// Space: O(26)

class Solution {
public:
    string rearrangeString(string s, int k) {
        vector<int> count(26);
        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
        }
        
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                pq.push({count[i], i});
            }
        }
        
        queue<pair<int, int>> q;
        string result = "";
        
        while (!pq.empty()) {
            int count = pq.top().first;
            int index = pq.top().second;
            pq.pop();
            
            result += index + 'a';
            
            q.push({count - 1, index});
            if (q.size() >= k) {
                int seenCount = q.front().first;
                int seenIndex = q.front().second;
                q.pop();
                if (seenCount > 0) {
                    pq.push({seenCount, seenIndex});
                }
            }
        }
        
        if (result.size() == s.size()) {
            return result;
        }
        return "";
    }
};
