class Solution {
public:
    string removeDuplicates(string S) {
        string result = "";
        for (int i = 0; i < S.size(); i++) {
            if (!result.empty() && result.back() == S[i]) {
                result.pop_back();
            } else {
                result.push_back(S[i]);
            }
        }
        return result;
    }
};
