#include <stdio.h>

#include <iostream>

using namespace std;

int maximumDifference(int arr[], int length) {
    int minNum = arr[0];
    int maxDiff = arr[1] - arr[0];
    for (int i = 1; i < length; i++) {
        if (arr[i] < minNum) {
            minNum = arr[i];
        }
        if (arr[i] - minNum > maxDiff) {
            maxDiff = arr[i] - minNum;
        }
    }
    return maxDiff;
}

int main()
{
    int arr1[] = {2, 3, 10, 6, 4, 8, 1};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {7, 9, 5, 6, 3, 2};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << maximumDifference(arr1, size1) << endl;
    cout << maximumDifference(arr2, size2) << endl;
    
    return 0;
}
