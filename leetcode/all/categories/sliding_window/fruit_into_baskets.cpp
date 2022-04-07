// Time: O(n)
// Space: O(1)

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i = 0;
        int j = 0;
        
        unordered_map<int, int> m;
        int result = 0;
        
        while (j < fruits.size()) {
            m[fruits[j]]++;
            j++;
            while (m.size() > 2) {
                m[fruits[i]]--;
                if (m[fruits[i]] == 0) {
                    m.erase(fruits[i]);
                }
                i++;
            }
            result = max(result, j - i);
        }
        
        return result;
    }
};
