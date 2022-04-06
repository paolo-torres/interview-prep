// Record max idx/value, if curr < max best swap so far

// Time: O(n)
// Space: O(n)

class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
              
        int maxIndex = -1;
        int maxValue = -1;
        
        int leftIndex = -1;
        int rightIndex = -1;
        
        for (int i = str.size() - 1; i >= 0; i--) {
            if (maxValue < str[i]) {
                maxIndex = i;
                maxValue = str[i];
                continue;
            }
            
            if (str[i] < maxValue) {
                leftIndex = i;
                rightIndex = maxIndex;
            }
        }
        
        if (leftIndex == -1) {
            return num;
        }
        
        swap(str[leftIndex], str[rightIndex]);
        return stoi(str);
    }
};
