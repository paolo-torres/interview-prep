class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        map<int, string> m;
        m.insert({3, "Fizz"});
        m.insert({5, "Buzz"});
        for (int i = 1; i <= n; i++) {
            string temp;
            for (auto it = m.begin(); it != m.end(); ++it) {
                if (i % it->first == 0) {
                    temp.append(it->second);
                }
            }
            if (temp.empty()) {
                temp.append(to_string(i));
            }
            result.push_back(temp);
        }
        return result;
    }
};
