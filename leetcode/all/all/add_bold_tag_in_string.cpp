// Bool array to mark if char at each pos is bold or not

// Time: O(n x m x l) -> len(s) x len(words) x avg len(word)
// Space: O(n)

class Solution {
public:
    string addBoldTag(string s, vector<string>& words) {
        int n = s.size();
        vector<bool> bold(n);
        
        for (int i = 0; i < words.size(); i++) {
            int wordIndex = -1;
            while (true) {
                wordIndex = s.find(words[i], wordIndex + 1);
                if (wordIndex == -1) {
                    break;
                }
                for (int j = wordIndex; j < wordIndex + words[i].size(); j++) {
                    bold[j] = true;
                }
            }
        }
        
        string result = "";
        
        for (int i = 0; i < n; i++) {
            if (!bold[i]) {
                result += s[i];
                continue;
            }
            
            int j = i;
            while (j < n && bold[j]) {
                j++;
            }
            
            result += "<b>" + s.substr(i, j - i) + "</b>";
            i = j - 1;
        }
        
        return result;
    }
};
