// Given array of strings & 2 diff strings in array, return shortest dist b/w them
// Ex. words = ["practice", "makes", "perfect", "coding", "makes"], word1 = "coding", word2 = "practice"
// Output = 3 (min dist b/w "coding" & "practice" is index 0 to index 2)

// Maintain 2 indices, store most recent word1/word2 locations, naturally close together

// Time: O(m x n) -> m = total length of input words, n = number of words in wordsDict
// Space: O(1)

class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int index1 = -1;
        int index2 = -1;
        
        int n = wordsDict.size();
        int result = n;
        
        for (int i = 0; i < n; i++) {
            if (wordsDict[i] == word1) {
                index1 = i;
            } else if (wordsDict[i] == word2) {
                index2 = i;
            }
            
            if (index1 != -1 && index2 != -1) {
                result = min(result, abs(index1 - index2));
            }
        }
        
        return result;
    }
};
