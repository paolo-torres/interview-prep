// Stream split by '/', ignore "//" and "/./", pop if "/../", push names

// Time: O(n)
// Space: O(n)

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        
        stringstream ss(path);
        string s = "";
        
        while (getline(ss, s, '/')) {
            if (s == "" || s == ".") {
                continue;
            }
            if (s == ".." && !stk.empty()) {
                stk.pop();
            } else if (s != "..") {
                stk.push(s);
            }
        }
        
        string result = "";
        
        while (!stk.empty()) {
            result = "/" + stk.top() + result;
            stk.pop();
        }
        
        if (result == "") {
            return "/";
        }
        return result;
    }
};
