/*
    Given a string, reverse the order of the words
    Ex. s = "the sky is blue" -> "blue is sky the"

    Reverse whole string and then reverse each word

    Time: O(n)
    Space: O(1)
*/

class Solution {
public:
    string reverseWords(string s) {
        // reverse whole string
        reverse(s.begin(), s.end());
        
        int n = s.size();
        int index = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                continue;
            }
            
            // go to beginning of word
            if (index != 0) {
                s[index] = ' ';
                index++;
            }
            
            // go to end of word
            int j = i;
            while (j < n && s[j] != ' ') {
                s[index] = s[j];
                index++;
                j++;
            }
            
            // reverse the word
            reverse(s.begin() + index - (j - i), s.begin() + index);
            
            // move to next word
            i = j;
        }
        
        s.erase(s.begin() + index, s.end());
        return s;
    }
};
