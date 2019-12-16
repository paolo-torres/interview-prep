class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            auto it = m.find(nums[i]);
            if (it != m.end()) {
                it->second++;
            } else {
                m.insert({nums[i], 1});
            }
        }
        priority_queue<pair<int, int>> pq;
        vector<int> result;
        for (auto it = m.begin(); it != m.end(); it++) {
            pq.push(make_pair(it->second, it->first));
        }
        for (int i = 0; i < k; i++) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};
