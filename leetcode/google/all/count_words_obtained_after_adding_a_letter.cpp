/*
    Given startWords & targetWords, check if possible to perform 2-step conversion:
        1) Append any lowercase letter not present in the string to its end
        2) Rearrange the letters of the new string in any arbitrary order
    Ex. startWords = ["ant","act","tack"], targetWords = ["tack","act","acti"] -> 2
    "act" -> "actk" -> "tack" targetWords[0], "act" -> "acti" targetWords[2]

    Add all target words into hash map, for each start word, try add a char + sort

    Time: O(n log n)
    Space: O(n)
*/

class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_map<string, int> m;
        for (int i = 0; i < targetWords.size(); i++) {
            string word = targetWords[i];
            sort(word.begin(), word.end());
            m[word]++;
        }
        
        int result = 0;
        for (int i = 0; i < startWords.size(); i++) {
            string word = startWords[i];
            for (char c = 'a'; c <= 'z'; c++) {
                if (count(word.begin(), word.end(), c)) {
                    continue;
                }
                string newWord = word + c;
                sort(newWord.begin(), newWord.end());
                
                if (m.find(newWord) != m.end()) {
                    result += m[newWord];
                    m.erase(newWord);
                }
            }
        }
        return result;
    }
};
