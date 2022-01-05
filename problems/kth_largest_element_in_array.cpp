class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.empty()) {
            return 0;
        }
        priority_queue<int> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        for (int i = 0; i < k - 1; i++) {
            pq.pop();
        }
        return pq.top();
    }
};
