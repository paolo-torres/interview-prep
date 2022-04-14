// Take turns adding, given maxChooseable & desiredTotal, return true if 1st player wins

// Need to know at each turn, "what is the state of the game?", so need to know:
// (1) The unchosen numbers, and (2) remaining desiredTotal to reach
// (1) Hash map of unique used bool key to state, (2) desiredTotal - curr chosen

// Time: O(2^n)
// Space: O(n)

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= 0) {
            return true;
        }
        
        // ex. mci = 5, dt = 50 -> no matter what, 2nd player will win
        int sum = (maxChoosableInteger + 1) * maxChoosableInteger / 2;
        if (sum < desiredTotal) {
            return false;
        }
        
        unordered_map<int, bool> m;
        vector<bool> used(maxChoosableInteger + 1);
        
        return helper(desiredTotal, m, used);
    }
private:
    bool helper(int desiredTotal, unordered_map<int, bool>& m, vector<bool>& used) {
        if (desiredTotal <= 0) {
            return false;
        }
        
        int key = format(used);
        if (m.find(key) != m.end()) {
            return m[key];
        }
        
        // try every unchosen number as the next step
        for (int i = 1; i < used.size(); i++) {
            if (!used[i]) {
                used[i] = true;
                // check if this leads to a win (other player loses)
                if (!helper(desiredTotal - i, m, used)) {
                    m[key] = true;
                    used[i] = false;
                    return true;
                }
                used[i] = false;
            }
        }
        
        m[key] = false;
        return m[key];
    }
    
    // convert bool vector to a unique int key describing state
    int format(vector<bool>& used) {
        int num = 0;
        for (int i = 0; i < used.size(); i++) {
            num <<= 1;
            if (used[i]) {
                num |= 1;
            }
        }
        return num;
    }
};
