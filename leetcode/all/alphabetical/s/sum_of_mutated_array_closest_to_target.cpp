class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int max = arr[arr.size() - 1];
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
        }
        if (sum <= target) {
            return max;
        }
        int removed = 0;
        int i = arr.size() - 1;
        while (i >= 0 && sum + arr[i] * removed > target) {
            removed++;
            sum -= arr[i];
            i--;
        }
        int result = (target - sum) / removed;
        if (abs(target - sum - result * removed) <= abs(target - sum - (result + 1) * removed)) {
            return result;
        }
        return result + 1;
    }
};
