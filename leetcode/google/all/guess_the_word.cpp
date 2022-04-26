/*
    Given wordlist, one is "secret", can call guess() which returns # of exact matches, have 10 tries
    Ex. secret = "acckzz", wordlist = ["acckzz","ccbazz","eoiwzz","abcczz"], numguesses = 10
    Output: You guessed the secret word correctly.

    Since exact matches needs to be wordlist[i].size(), discard any below that each time

    Time: O(n)
    Space: O(n)
*/

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        srand(time(NULL));
        
        int matches = 0;
        for (int i = 0; i < 10; i++) {
            // found word
            if (matches == 6) {
                break;
            }
            
            int n = wordlist.size();
            int randIndex = rand() % n;
            string word = wordlist[randIndex];
            matches = master.guess(word);
            
            for (int j = 0; j < n; j++) {
                if (matches == getMatches(word, wordlist[j])) {
                    wordlist.push_back(wordlist[j]);
                }
            }
            
            // remove original list and keep only matched words
            wordlist.erase(wordlist.begin(), wordlist.begin() + n);
        }
    }
private:
    int getMatches(string& word1, string& word2) {
        int matchCount = 0;
        for (int i = 0; i < word1.size(); i++) {
            if (word1[i] == word2[i]) {
                matchCount++;
            }
        }
        return matchCount;
    }
};
