#include <stdio.h>

#include <iostream>

using namespace std;

int maxSum(int arr[], int n, int k) {
    int max = 0;
    for (int i = 0; i < k; i++) {
        max += arr[i];
    }
    int cur = max;
    for (int i = k; i < n; i++) {
        cur += arr[i] - arr[i-k];
        if (cur > max) {
            max = cur;
        }
    }
    return max;
}

int main()
{
    int arr[5] = {5, 2, -1, 0, 3};
    int n = 5;
    int k = 3;
    
    cout << maxSum(arr, n, k) << endl;

    return 0;
}
