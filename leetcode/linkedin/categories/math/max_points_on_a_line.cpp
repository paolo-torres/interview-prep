// Given array of points, points[i] = [xi, yi], return max # of points that line on a line
// Ex. points = [[1,1],[2,2],[3,3]], output = 3

// Traverse all possible lines via slopes, get GCD to group common slopes, store max

// Time: O(n^2)
// Space: O(n)

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int result = 0;
        
        for (int i = 0; i < n; i++) {
            unordered_map<string, int> count;
            int duplicates = 1;
            
            for (int j = i + 1; j < n; j++) {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    duplicates++;
                } else {
                    int dx = points[j][0] - points[i][0];
                    int dy = points[j][1] - points[i][1];
                    
                    int g = gcd(dx, dy);
                    
                    string key = to_string(dy / g) + '/' + to_string(dx / g);
                    count[key]++;
                }
            }
            
            result = max(result, duplicates);
            for (auto it = count.begin(); it != count.end(); it++) {
                result = max(result, it->second + duplicates);
            }
        }
        
        return result;
    }
private:
    int gcd(int a, int b) {
        while (b != 0) {
            a = a % b;
            swap(a, b);
        }
        return a;
    }
};
