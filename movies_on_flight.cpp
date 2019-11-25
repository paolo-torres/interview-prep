#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> moviesOnFlight(vector<int>& movieDurations, int d) {
    sort(movieDurations.begin(), movieDurations.end());
    int low = 0;
    int high = movieDurations.size() - 1;
    vector<int> result(2, 0);
    int resultDuration = 0;
    while (low <= high) {
        int tempDuration = movieDurations[low] + movieDurations[high];
        resultDuration = result[0] + result[1];
        if (tempDuration == resultDuration) {
            result.push_back(movieDurations[low]);
            result.push_back(movieDurations[high]);
        } else if (tempDuration > resultDuration && tempDuration <= d - 30) {
            result.clear();
            result.push_back(movieDurations[low]);
            result.push_back(movieDurations[high]);
        }
        if (tempDuration < d - 30) {
            low++;
        } else {
            high--;
        }
    }
    vector<int> final(2, 0);
    for (int i = 1; i < result.size(); i++) {
        if (result[i] > final[i]) {
            final[0] = result[0];
            final[1] = result[1];
        }
    }
    return final;
}

int main()
{
    vector<int> movieDurations = {90, 85, 75, 60, 120, 150, 125};
    int d = 250;
    vector<int> test = moviesOnFlight(movieDurations, d);
    for (int i = 0; i < test.size(); i++) {
        cout << test[i] << " ";
    }

    return 0;
}
