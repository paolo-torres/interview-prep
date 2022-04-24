/*
    Given array of strings & a max width, format text such that each line is fully justified
    Ex. words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
    Output:
        "This    is   an",
        "example of text",
        "justification. "

    Start w/ left as 1st word, findRight: greedily right as possible until max
    Then justify one line at a time: in all cases we pad right side w/ spaces
    (1) if 1 word then result is just that word
    (2) if last line then result is all words separated by single space
    (3) else calculate size of each space evenly, if remainder distribute

    Time: O(n)
    Space: O(n)
*/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        
        int left = 0;
        while (left < words.size()) {
            int right = findRight(words, maxWidth, left);
            result.push_back(justify(words, maxWidth, left, right));
            left = right + 1;
        }
        
        return result;
    }
private:
    int findRight(vector<string>& words, int maxWidth, int left) {
        int right = left;
        int sum = words[right].size();
        right++;
        
        while (right < words.size() && (sum + 1 + words[right].size()) <= maxWidth) {
            sum += 1 + words[right].size();
            right++;
        }
        
        return right - 1;
    }
    
    string justify(vector<string>& words, int maxWidth, int left, int right) {
        if (right - left == 0) {
            return padResult(maxWidth, words[left]);
        }
        
        bool isLastLine = right == words.size() - 1;
        int numSpaces = right - left;
        int totalSpace = maxWidth - wordsLength(words, left, right);
        
        string space = isLastLine ? " " : blank(totalSpace / numSpaces);
        int remainder = isLastLine ? 0 : totalSpace % numSpaces;
        
        string result = "";
        for (int i = left; i <= right; i++) {
            result.append(words[i]);
            result.append(space);
            if (remainder > 0) {
                result.append(" ");
            } else {
                result.append("");
            }
            remainder--;
        }
        
        result.erase(result.find_last_not_of(" \n\r\t")+1);
        return padResult(maxWidth, result);
    }
    
    string padResult(int maxWidth, string result) {
        return result + blank(maxWidth - result.size());
    }
    
    int wordsLength(vector<string>& words, int left, int right) {
        int length = 0;
        for (int i = left; i <= right; i++) {
            length += words[i].size();
        }
        return length;
    }
    
    string blank(int length) {
        string str(length, ' ');
        return str;
    }
};
