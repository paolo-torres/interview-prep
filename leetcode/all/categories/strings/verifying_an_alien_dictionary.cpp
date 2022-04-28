/*
    Given a sequence of words written in alien language & order of their alphabet
    Return true if given words are sorted lexicographically in this alien language
    Ex. words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz" -> true

    Compare adjacent words, hash map {char -> index}

    Time: O(n) -> n = total number of characters in words
    Space: O(1)
*/

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> orderMap(26);
        for (int i = 0; i < order.size(); i++) {
            orderMap[order[i] - 'a'] = i;
        }
        
        for (int i = 0; i < words.size() - 1; i++) {
            for (int j = 0; j < words[i].size(); j++) {
                // Ex. ["apple", "app"] should return false
                if (j >= words[i + 1].size()) {
                    return false;
                }
                
                if (words[i][j] != words[i + 1][j]) {
                    int curr = words[i][j] - 'a';
                    int next = words[i + 1][j] - 'a';
                    if (orderMap[curr] > orderMap[next]) {
                        return false;
                    } else {
                        // if sorted, no need to check remaining
                        break;
                    }
                }
            }
        }
        
        return true;
    }
};
