// Time: O(log n)
// Space: O(1)

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0;
        int high = letters.size() - 1;
        
        if (letters[high] <= target) {
            return letters[low];
        }
        
        int mid = 0;
        while (low < high) {
            mid = low + (high - low) / 2;
            if (letters[mid] <= target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        
        return letters[low];
    }
};
