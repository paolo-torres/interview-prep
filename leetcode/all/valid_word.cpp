#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool validWord(vector<string> words, string word) {
    sort(words.begin(), words.end());
    int low = 0;
    int high = words.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (words[mid] < word) {
            low = mid + 1;
        } else if (words[mid] > word) {
            high = mid - 1;
        } else {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<string> words = {"alpha", "beta", "charlie", "delta", "echo"};
    string word = "delta";
    cout << validWord(words, word) << endl;

    return 0;
}
