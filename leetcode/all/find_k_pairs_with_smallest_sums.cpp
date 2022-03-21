// Time: O(m x n log k)
// Space: O(k)

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                int sum = nums1[i] + nums2[j];
                vector<int> pair = {nums1[i], nums2[j]};
                auto entry = make_pair(sum, pair);
                
                if (pq.size() < k) {
                    pq.push(entry);
                } else if (pq.top().first > sum) {
                    pq.pop();
                    pq.push(entry);
                } else {
                    break;
                }
            }
        }
        
        vector<vector<int>> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};
