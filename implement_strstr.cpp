class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        int result = -1;
        for (int i = 0; i < haystack.size(); i++) {
            if (haystack[i] == needle[0]) {
                if (haystack.substr(i, needle.size()) == needle) {
                    result = i;
                    break;
                }
            }
        }
        return result;
    }
};
