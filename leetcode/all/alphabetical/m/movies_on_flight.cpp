#include <stdio.h>

#include <iostream>
#include <iterator>
#include <map>
#include <vector>

using namespace std;

vector<int> moviesOnFlight(vector<int>& movieDurations, int d) {
    map<int, int> m;
    for (int i = 0; i < movieDurations.size(); i++) {
        m.insert({movieDurations[i], i});
    }
    auto low = m.begin();
    auto high = prev(m.end());
    int resultDuration = 0;
    vector<int> result(2, 0);
    while (low->first <= high->first) {
        int tempDuration = low->first + high->first;
        resultDuration = result[0] + result[1];
        if (tempDuration == resultDuration) {
            result.push_back(low->first);
            result.push_back(high->first);
        } else if (tempDuration > resultDuration && tempDuration < d - 30) {
            result.clear();
            result.push_back(low->first);
            result.push_back(high->first);
        }
        if (tempDuration < d - 30) {
            low++;
        } else {
            high--;
        }
    }
    vector<int> ans(2, 0);
    for (int i = 1; i < result.size(); i++) {
        if (result[i] > ans[i]) {
            ans[i-1] = result[i-1];
            ans[i] = result[i];
        }
    }
    low = m.find(ans[0]);
    high = m.find(ans[1]);
    ans[0] = low->second;
    ans[1] = high->second;
    return ans;
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
