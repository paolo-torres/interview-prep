class Solution {
private:
    void permutations(int n, int k, string& s, int pos, int& count, string& path, string& result) {
        if (count >= k || pos == n) {
            count++;
            if (count == k) {
                result = path;
            }
            return;
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                continue;
            }
            path[pos] = s[i];
            s[i] = '0';
            permutations(n, k, s, pos + 1, count, path, result);
            s[i] = path[pos];
        }
    }
public:
    string getPermutation(int n, int k) {
        string s;
        for (int i = 1; i <= n; i++) {
            s.push_back(i + '0');
        }
        string path = s;
        int count = 0;
        string result;
        permutations(n, k, s, 0, count, path, result);
        return result;
    }
};
