class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        if (nums1.empty() || nums2.empty()) {
            return result;
        }
        vector<int> bigger;
        vector<int> smaller;
        if (nums1.size() >= nums2.size()) {
            bigger = nums1;
            smaller = nums2;
        } else {
            bigger = nums2;
            smaller = nums1;
        }
        sort(bigger.begin(), bigger.end());
        sort(smaller.begin(), smaller.end());
        int i = 0;
        int j = 0;
        while (i < bigger.size() && j < smaller.size()) {
            if (bigger[i] == smaller[j]) {
                result.push_back(bigger[i]);
                i++;
                j++;
            } else if (bigger[i] > smaller[j]) {
                j++;
            } else {
                i++;
            }
        }
        return result;
    }
};
