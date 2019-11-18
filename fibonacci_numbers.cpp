#include <stdio.h>

#include <iostream>

using namespace std;

int fib(int n) {
    int arr[n+2];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= n; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[n];
}

int main()
{
    for (int i = 0; i < 47; i++) {
        cout << "index: "<< i << " value: " << fib(i) << endl;
    }
    return 0;
}
