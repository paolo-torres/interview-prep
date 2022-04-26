/*
    Design the basic function of Excel & implement the sum formula
    Format of numbers[i]: "ColRow" or "ColRow1:ColRow2"

    When a cell changes, all related sums have to update (forward link)
    When a cell resets/reassigns, cells contributing to its sum change (backward link)
*/

class Excel {
public:
    Excel(int height, char width) {
        // since row starts from 1, use height + 1
        exl = vector<vector<int>>(height + 1, vector<int>(width - 'A' + 1));
        forward.clear();
        backward.clear();
    }
    
    void set(int row, char column, int val) {
        int col = column - 'A';
        // 26 since height constraint
        int key = row * 26 + col;
        // update value and all related sums
        update(row, col, val);
        // reset, break all forward links if exists
        if (backward.find(key) != backward.end()) {
            unordered_set<int> links = backward[key];
            for (auto it = links.begin(); it != links.end(); it++) {
                forward[*it].erase(key);
            }
            backward[key].clear();
        }
    }
    
    int get(int row, char column) {
        return exl[row][column - 'A'];
    }
    
    int sum(int row, char column, vector<string> numbers) {
        int col = column - 'A';
        int key = row * 26 + col;
        int result = 0;
        
        // another reset, break all forward links if exists
        if (backward.find(key) != backward.end()) {
            unordered_set<int> links = backward[key];
            for (auto it = links.begin(); it != links.end(); it++) {
                forward[*it].erase(key);
            }
            backward[key].clear();
        }
        // get sum over multiple ranges
        for (int i = 0; i < numbers.size(); i++) {
            string s = numbers[i];
            int colon = s.find(':');
            
            int top = 0;
            int bottom = 0;
            int left = s[0] - 'A';
            int right = s[colon + 1] - 'A';
            
            if (colon == -1) {
                top = stoi(s.substr(1));
            } else {
                top = stoi(s.substr(1, colon - 1));
            }
            bottom = stoi(s.substr(colon + 2));
            
            for (int i = top; i <= bottom; i++) {
                for (int j = left; j <= right; j++) {
                    result += exl[i][j];
                    forward[i * 26 + j][key]++;
                    backward[key].insert(i * 26 + j);
                }
            }
        }
        
        // update cell and all related sums
        update(row, col, result);
        return result;
    }
private:
    // key of a cell is row * 26 + col
    vector<vector<int>> exl;
    // links cell to all cells it uses for sum, another map for weight
    unordered_map<int, unordered_map<int, int>> forward;
    // links cell to all cells that contribute to sum
    unordered_map<int, unordered_set<int>> backward;
    
    // update cell and all related sums with BFS
    // weights used for overlapping ranges
    void update(int row, int col, int val) {
        int prev = exl[row][col];
        exl[row][col] = val;
        
        // q is keys for cells in next level, update is increment for each cell
        queue<int> q;
        queue<int> update;
        q.push(row * 26 + col);
        update.push(val - prev);
        while (!q.empty()) {
            int key = q.front();
            int diff = update.front();
            q.pop();
            update.pop();
            
            if (forward.find(key) == forward.end()) {
                continue;
            }
            
            for (auto it = forward[key].begin(); it != forward[key].end(); it++) {
                int k = it->first;
                q.push(k);
                update.push(diff * it->second);
                exl[k / 26][k % 26] += diff * it->second;
            }
        }
    }
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel* obj = new Excel(height, width);
 * obj->set(row,column,val);
 * int param_2 = obj->get(row,column);
 * int param_3 = obj->sum(row,column,numbers);
 */
