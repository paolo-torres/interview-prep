/*
    Given a rows x cols screen & a sentence list of strings:
    Return # of times sentence can be fitted on the screen
    Ex. sentence = ["hello","world"], rows = 2, cols = 8 -> 1

    Track per line how many words can fit, use hash map to cache seen lines

    Time: O(rows x cols)
    Space: O(n) -> number of words in the sentence
*/

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        // {line -> # of words that can fit with this starting word}
        unordered_map<int, int> m;
        
        int num = 0;
        int n = sentence.size();
        
        for (int i = 0; i < rows; i++) {
            int start = num % n;
            
            if (m.find(start) != m.end()) {
                num += m[start];
                continue;
            }
            
            int count = 0;
            int length = 0;
            
            for (int i = start; length < cols; i = (i + 1) % n) {
                if (length + sentence[i].size() > cols) {
                    break;
                }
                length += sentence[i].size() + 1;
                count++;
            }
            
            num += count;
            m[start] = count;
        }
        
        return num / n;
    }
};
