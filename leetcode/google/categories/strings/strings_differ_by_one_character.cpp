/*
    Given an array of strings where all the strings are same length:
    Return true if there's 2 strings that only differ by 1 char in same index
    Ex. dict = ["abcd","acbd","aacd"] -> true, "abcd" & "aacd" at index 1

    Get hash for each string, for each char, get hash w/o that char (differ 1)
    Track in a hash map, if there's another string w/ same hash, return true

    Time: O(m x n) -> m = # of strings, n = length of longest string
    Space: O(m)
*/

class Solution {
public:
    bool differByOne(vector<string>& dict) {
        int m = dict.size();
        int n = dict[0].size();
        int mod = pow(10, 9) + 7;
        
        vector<int> hash(m);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                hash[i] = (26l * hash[i] + (dict[i][j] - 'a')) % mod;
            }
        }
        
        int base = 1;
        for (int j = n - 1; j >= 0; j--) {
            unordered_map<int, vector<int>> hashes;
            
            for (int i = 0; i < m; i++) {
                string word1 = dict[i];
                int newHash = (mod + hash[i] - (long)base * (word1[j] - 'a') % mod) % mod;
                
                auto it = hashes.find(newHash);
                if (it != hashes.end()) {
                    vector<int> collisions = it->second;
                    
                    for (int k = 0; k < collisions.size(); k++) {
                        string word2 = dict[collisions[k]];
                        
                        if (equal(begin(word1), begin(word1) + j, begin(word2))
                            && equal(begin(word1) + j + 1, end(word1), begin(word2) + j + 1))
                            return true;
                    }
                }
                
                hashes[newHash].push_back(i);
            }
            
            base = 26l * base % mod;
        }
        return false;
    }
};
