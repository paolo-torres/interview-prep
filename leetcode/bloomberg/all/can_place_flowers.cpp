/*
    Given int array w/ 0's empty & 1's non-empty, and int n
    Return if n flowers can be planted w/o adjacent flowers
    Ex. [1,0,0,0,1] n = 1 -> true, [1,0,0,0,1] n = 2 -> false

    Scan in 3-sized window, if all empty can plant flower, if n planted return early

    Time: O(n)
    Space: O(1)
*/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int length = flowerbed.size();
        
        for (int i = 0; i < length; i++) {
            int prev = i == 0 ? 0 : i - 1;
            int next = i == length - 1 ? length - 1 : i + 1;
            
            if (flowerbed[prev] == 0 && flowerbed[i] == 0 && flowerbed[next] == 0) {
                flowerbed[i] = 1;
                n--;
                if (n <= 0) {
                    return true;
                }
            }
        }
        
        if (n <= 0) {
            return true;
        }
        return false;
    }
};
