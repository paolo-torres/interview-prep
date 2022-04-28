/*
    Given a sorted char array & a char target, return smallest char > target
    Ex. letters = ["c","f","j"], target = "a" -> "c"

    Linear scan -> optimize w/ binary search, find rightmost pos for target

    Time: O(log n)
    Space: O(1)
*/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0;
        int high = letters.size() - 1;
        
        if (letters[high] <= target) {
            return letters[low];
        }
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (letters[mid] <= target) {
                // know for sure mid not the ans, do mid + 1
                low = mid + 1;
            } else {
                // since high could be the ans, don't do mid - 1
                high = mid;
            }
        }
        
        return letters[low];
    }
};
