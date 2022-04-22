/*
    'A': position += speed, speed *= 2
    'R': if speed > 0: speed = -1, else speed = 1
    Starting at position 0 and speed +1, given target:
    Return length of shortest sequence of instructions to get there
    Ex. target = 3 -> 2, "AA", 0, 1, 3

    Keep track of all possible positions after n = 0, 1, 2, 3, ...
    Return smallest n such that the target position is reached

    Time: O(2^n)
    Space: O(n)
*/

class Solution {
public:
    int racecar(int target) {
        queue<pair<int, int>> q;
        // start at position 0 with speed 1
        q.push({0, 1});
        
        unordered_set<string> visited;
        visited.insert("0,1");
        
        int result = 0;
        
        while (!q.empty()) {
            int count = q.size();
            
            for (int i = 0; i < count; i++) {
                pair<int, int> curr = q.front();
                int position = curr.first;
                int speed = curr.second;
                q.pop();
                
                if (position == target) {
                    return result;
                }
                
                // accelerate instruction
                pair<int, int> next = {position + speed, speed * 2};
                string key = to_string(next.first) + "," + to_string(next.second);
                
                if (visited.find(key) == visited.end()) {
                    if (next.first > 0 && next.first < target * 2) {
                        q.push(next);
                        visited.insert(key);
                    }
                }
                
                // reverse instruction
                next = {position, speed > 0 ? -1 : 1};
                key = to_string(next.first) + "," + to_string(next.second);
                
                if (visited.find(key) == visited.end()) {
                    if (next.first > 0 && next.first < target * 2) {
                        q.push(next);
                        visited.insert(key);
                    }
                }
            }
            
            result++;
        }
        
        return -1;
    }
};
