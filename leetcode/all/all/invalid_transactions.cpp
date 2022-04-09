// Split into separate arrays, have add array to determine need to add

// Time: O(n^2)
// Space: O(n)

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        int n = transactions.size();
        if (n == 0) {
            return {};
        }
        
        vector<string> names(n);
        vector<int> times(n);
        vector<int> amounts(n);
        vector<string> cities(n);
        
        vector<bool> shouldAdd(n);
        vector<string> result;
        
        for (int i = 0; i < n; i++) {
            string value = transactions[i];
            stringstream ss(value);
            
            getline(ss, value, ',');
            names[i] = value;
            getline(ss, value, ',');
            times[i] = stoi(value);
            getline(ss, value, ',');
            amounts[i] = stoi(value);
            getline(ss, value, ',');
            cities[i] = value;
        }
        
        for (int i = 0; i < n; i++) {
            if (amounts[i] > 1000) {
                shouldAdd[i] = true;
            }
            for (int j = i + 1; j < n; j++) {
                if (names[i] == names[j] && abs(times[i] - times[j]) <= 60 && cities[i] != cities[j]) {
                    shouldAdd[i] = true;
                    shouldAdd[j] = true;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (shouldAdd[i]) {
                result.push_back(transactions[i]);
            }
        }
        
        return result;
    }
};
