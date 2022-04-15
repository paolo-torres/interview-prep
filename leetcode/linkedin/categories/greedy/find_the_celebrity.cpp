// Celebrity: everyone knows them, they don't know anyone
// Ex. graph = [[1,1,0],[0,1,0],[1,1,1]] -> output = index 1

// Logical deduction, for each person if they know x, x "could be" celebrity
// At the end have a potential candidate, check if they're a celebrity

// Time: O(n)
// Space: O(1)

/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (knows(result, i)) {
                result = i;
            }
        }
        if (isCelebrity(n, result)) {
            return result;
        }
        return -1;
    }
private:
    bool isCelebrity(int n, int i) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            // if they know someone or someone doesn't know them
            if (knows(i, j) || !knows(j, i)) {
                return false;
            }
        }
        return true;
    }
};
