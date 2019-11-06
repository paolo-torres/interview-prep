class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() == 2) {
            return min(height[0], height[1]);
        }
        int current = 0;
        int maximum = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right) {
            int distance = right - left;
            current = min(height[left], height[right]) * distance;
            if (current > maximum) {
                maximum = current;
            }
            if (height[left] > height[right]) {
                right--;
            } else {
                left++;
            }
        }
        return maximum;
    }
};
