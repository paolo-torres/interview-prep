// Time: O(n^2)
// Space: O(1)

class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        if (arr.size() <= 2) {
            return arr;
        }
        
        bool hasChanged = true;
        while (hasChanged) {
            hasChanged = false;
            
            int prev = arr[0];
            int curr = arr[1];
            int next = arr[2];
            
            for (int i = 1; i < arr.size() - 1; i++) {
                if (prev > curr && curr < next) {
                    arr[i]++;
                    hasChanged = true;
                } else if (prev < curr && curr > next) {
                    arr[i]--;
                    hasChanged = true;
                }
                
                prev = curr;
                curr = next;
                next = arr[i + 2];
            }
        }
        
        return arr;
    }
};
