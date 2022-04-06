// Monotonic increasing stack, process right to left

// Time: O(n)
// Space: O(n)

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        
        vector<int> result(n);
        
        for (int i = n - 1; i >= 0; i--) {
            // i'th person will block shorter ppl on right side
            while (!s.empty() && heights[i] > s.top()) {
                // pop b/c these ppl can't be seen anymore
                s.pop();
                // i'th person can see these shorter ppl
                result[i]++;
            }
            
            // i'th person can see 1 more person taller
            if (!s.empty()) {
                result[i]++;
            }
            
            s.push(heights[i]);
        }
        
        return result;
    }
};
