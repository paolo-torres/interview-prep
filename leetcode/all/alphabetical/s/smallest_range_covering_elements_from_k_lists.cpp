// Time: O(n x k log k)
// Space: O(k)

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        
        int maxNum = INT_MIN;
        int minDiff = INT_MAX;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < n; i++) {
            maxNum = max(maxNum, nums[i][0]);
            pq.push({nums[i][0], i});
        }
        
        vector<int> indices(n, 0);
        vector<int> result(2, 0);
        
        while (pq.size() == n) {
            int currNum = pq.top().first;
            int currIndex = pq.top().second;
            pq.pop();
            
            if (minDiff > maxNum - currNum) {
                minDiff = maxNum - currNum;
                result[0] = currNum;
                result[1] = maxNum;
            }
            
            if (indices[currIndex] < nums[currIndex].size()) {
                pq.push({nums[currIndex][indices[currIndex]], currIndex});
                maxNum = max(maxNum, nums[currIndex][indices[currIndex]]);
                indices[currIndex]++;
            }
        }
        
        return result;
    }
};
