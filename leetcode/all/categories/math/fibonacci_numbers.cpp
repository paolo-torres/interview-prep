class Solution {
public:
    int fib(int N) {
        if (N == 0) {
            return 0;
        }
        int first = 0;
        int second = 1;
        int result = first + second;
        for (int i = 2; i <= N; i++) {
            result = first + second;
            first = second;
            second = result;
        }
        return result;
    }
};
