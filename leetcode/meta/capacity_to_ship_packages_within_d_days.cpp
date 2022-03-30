// Low/high are min/max possible capacities of ship
// Binary search to find min capacity b/w low & high
// For each mid capacity, determine # days, then iterate

// Time: O(n log n)
// Space: O(1)

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0;
        int high = 0;
        for (int i = 0; i < weights.size(); i++) {
            low = max(low, weights[i]);
            high += weights[i];
        }
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int requiredDays = getRequiredDays(weights, mid);
            
            if (requiredDays > days) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return low;
    }
private:
    int getRequiredDays(vector<int>& weights, int maxCapacity) {
        int requiredDays = 1;
        int capacity = 0;
        
        for (int i = 0; i < weights.size(); i++) {
            capacity += weights[i];
            if (capacity > maxCapacity) {
                requiredDays++;
                capacity = weights[i];
            }
        }
        
        return requiredDays;
    }
};
