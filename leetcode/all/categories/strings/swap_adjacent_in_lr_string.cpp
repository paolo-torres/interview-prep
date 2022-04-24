/*
    Given start & end string, return true if transform exists:
    strings composed of 'L', 'R', & 'X', move consists of either:
    replacing 1 occurrence "XL" w/ "LX" or 1 occurrence "RX" w/ "XR"
    Ex. start = "RXXLRXRXL", end = "XRLXXRRLX" -> true

    Get non-X chars & compare positions (if remove all X, should be same)

    Time: O(n)
    Space: O(1)
*/

class Solution {
public:
    bool canTransform(string start, string end) {
        string startCopy = start;
        string endCopy = end;
        startCopy.erase(remove(startCopy.begin(), startCopy.end(), 'X'), startCopy.end());
        endCopy.erase(remove(endCopy.begin(), endCopy.end(), 'X'), endCopy.end());
        cout << startCopy << endl << endCopy;
        if (startCopy != endCopy) {
            return false;
        }
        
        int m = start.size();
        int n = end.size();
        
        int i = 0;
        int j = 0;
        
        while (i < m && j < n) {
            // get non-X positions of 2 strings
            while (i < m && start[i] == 'X') {
                i++;
            }
            while (j < n && end[j] == 'X') {
                j++;
            }
            
            // if they both reach the end return true
            if (i == m && j == n) {
                return true;
            }
            // if only 1 reaches the end return false
            if (i == m || j == n) {
                return false;
            } 
            
            if (start[i] != end[j]) {
                return false;
            }
            
            // if char 'L' can only move left, i should be >= j
            if (start[i] == 'L' && i < j) {
                return false;
            }
            // if char 'L' can only move right, i should be < j
            if (start[i] == 'R' && i > j) {
                return false;
            }
            
            i++;
            j++;
        }
        
        return true;
    }
};
