class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int result = 0;
        vector<int> v(A.size() + 1);
	int count = 0;
	int prefix = 0;
        for (int i = 0, j = 0; i < A.size(); i++) {
            if (v[A[i]]++ == 0) {
                count++;
            }
            if (count > K) {
                v[A[j++]]--;
                count--;
                prefix = 0;
            }
            while (v[A[j]] > 1) {
                prefix++;
                v[A[j++]]--;
            }
            if (count == K) {
                result += prefix + 1;
            }
        }
        return result;
    }
};
