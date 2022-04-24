/*
    Given a string s & an array of strings, return # of words that's a subsequence of s
    Ex. s = "abcde", words = ["a","bb","acd","ace"] -> 3, "a", "acd", "ace"

    Naive: brute force iterate each word & check if each word is a subseq of the string
    Optimal: group words into buckets by start char, process by trimming start char

    Time: O(n + s) -> n = length of string, s = sum length of all words
    Space: O(m) -> m = size of words array
*/

struct Node {
    const string& word;
    int index;
    Node(const string& word, int index) : word(word), index(index) {};
};

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<Node> buckets[26];
        for (int i = 0; i < words.size(); i++) {
            char firstLetter = words[i][0];
            buckets[firstLetter - 'a'].push_back(Node(words[i], 0));
        }
        
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            vector<Node> currBucket = buckets[s[i] - 'a'];
            buckets[s[i] - 'a'].clear();
            for (Node& node : currBucket) {
                node.index++;
                // if empty after trim, then it's a subsequence
                if (node.index == node.word.size()) {
                    result++;
                // if not, group word after trim into its new bucket
                } else {
                    int newIndex = node.word[node.index] - 'a';
                    buckets[newIndex].push_back(node);
                }
            }
        }
        return result;
    }
};
