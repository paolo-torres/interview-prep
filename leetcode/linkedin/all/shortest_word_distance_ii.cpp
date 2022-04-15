// Given string array, answer queries of shortest dist b/w 2 diff strings
// Ex. words = ["practice", "makes", "perfect", "coding", "makes"], ["coding", "practice"]
// Output = 3 (min dist b/w "coding" & "practice" is index 0 to index 3)

// Maintain 2 indices, store most recent word1/word2 locations, naturally close together

// Since words can appear multiple times, need 2 pointers, each to track word1/word2 indices
// Goal is to find the pair of indices (i, j) such that absolute difference is minimized
// Since "seen" indices will be in "sorted" order, can control which pointer to move next

// Time: O(n)
// Space: O(n)

class WordDistance {
public:
    WordDistance(vector<string>& wordsDict) {
        // create mapping from word to all its indices
        for (int i = 0; i < wordsDict.size(); i++) {
            locations[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        // indices will be in sorted order (indices in order of when they've been seen)
        vector<int> word1Locations = locations[word1];
        vector<int> word2Locations = locations[word2];
        
        int i = 0;
        int j = 0;
        
        int result = INT_MAX;
        
        while (i < word1Locations.size() && j < word2Locations.size()) {
            result = min(result, abs(word1Locations[i] - word2Locations[j]));
            if (word1Locations[i] < word2Locations[j]) {
                i++;
            } else {
                j++;
            }
        }
        
        return result;
    }
private:
    // hash map {word -> all it's locations (indices)}
    unordered_map<string, vector<int>> locations;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
