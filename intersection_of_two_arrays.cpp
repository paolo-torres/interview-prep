class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1;
        for (int i = 0; i < nums1.size(); i++) {
            s1.insert(nums1[i]);
        }
        unordered_set<int> s2;
        for (int i = 0; i < nums2.size(); i++) {
            s2.insert(nums2[i]);
        }
        bool s1Shorter = false;
        if (s1.size() <= s2.size()) {
            s1Shorter = true;
        }
        vector<int> result;
        if (s1Shorter) {
            for (auto it = s1.begin(); it != s1.end(); ++it) {
                if (s2.find(*it) != s2.end()) {
                    result.push_back(*it);
                }
            }
        } else {
            for (auto it = s2.begin(); it != s2.end(); ++it) {
                if (s1.find(*it) != s1.end()) {
                    result.push_back(*it);
                }
            }
        }
        return result;
    }
};
