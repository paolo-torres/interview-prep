// https://leetcode.com/problems/task-scheduler/discuss/104500/Java-O(n)-time-O(1)-space-1-pass-no-sorting-solution-with-detailed-explanation

// Time: O(n)
// Space: O(26)

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> counter(26);
        
        int maxValue = 0;
        int maxCount = 0;
        
        for (int i = 0; i < tasks.size(); i++) {
            counter[tasks[i] - 'A']++;
            int currValue = counter[tasks[i] - 'A'];
            
            if (maxValue == currValue) {
                maxCount++;
            } else if (maxValue < currValue) {
                maxValue = currValue;
                maxCount = 1;
            }
        }
        
        int partCount = maxValue - 1;
        int partLength = n - (maxCount - 1);
        int emptySlots = partCount * partLength;
        int availableTasks = tasks.size() - maxValue * maxCount;
        int idles = max(0, emptySlots - availableTasks);
        
        return tasks.size() + idles;
    }
};
