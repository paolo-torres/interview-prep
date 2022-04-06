// Time: O(n x wordVectorSize x wordSize)
// Space: O(wordVectorSize + wordSize)

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> counts;
        for (int i = 0; i < words.size(); i++) {
            counts[words[i]]++;
        }
        
        int n = s.size();
        int wordVectorSize = words.size();
        int wordSize = words[0].size();
        
        vector<int> result;
        
        int i = 0;
        while (i < n - wordVectorSize * wordSize + 1) {
            unordered_map<string, int> seen;
            
            int j = 0;
            while (j < wordVectorSize) {
                string word = s.substr(i + j * wordSize, wordSize);
                
                if (counts.find(word) != counts.end()) {
                    seen[word]++;
                    if (seen[word] > counts[word]) {
                        break;
                    }
                } else {
                    break;
                }
                
                j++;
            }
            
            if (j == wordVectorSize) {
                result.push_back(i);
            }
            
            i++;
        }
        
        return result;
    }
};
