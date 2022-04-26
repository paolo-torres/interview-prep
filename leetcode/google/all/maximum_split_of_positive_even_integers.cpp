/*
    Given an int finalSum, split into a sum of max # of unique +'ve even ints
    Ex. finalSum = 12 -> [2,4,6], (12), (2 + 10), (2 + 4 + 6), (4 + 8)

    Greedy: try smallest numbers first, if last sum too large, exclude & add diff

    Time: O(sqrt(n))
    Space: O(n)
*/

class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        // odd sum cannot be represented w/ even numbers
        if (finalSum % 2 != 0) {
            return {};
        }
        
        long long currSum = 0;
        vector<long long> result;
        
        for (long long i = 2; i <= finalSum; i += 2) {
            if (currSum + i > finalSum) {
                break;
            }
            result.push_back(i);
            currSum += i;
        }
        
        result[result.size() - 1] += finalSum - currSum;
        return result;
    }
};
