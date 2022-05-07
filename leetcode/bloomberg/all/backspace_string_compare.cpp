/*
    Given 2 strings, return true if equal after backspaces
    Ex. s = "ab#c", t = "ad#c" -> true

    Build strings w/ stack & compare -> 2 pointer & track skips

    Time: O(m + n)
    Space: O(1)
*/

// class Solution {
// public:
//     bool backspaceCompare(string s, string t) {
//         return build(s) == build(t);
//     }
// private:
//     string build(string str) {
//         stack<char> s;
//         for (int i = 0; i < str.size(); i++) {
//             if (str[i] != '#') {
//                 s.push(str[i]);
//             } else if (!s.empty()) {
//                 s.pop();
//             }
//         }
//         string result = "";
//         while (!s.empty()) {
//             result += s.top();
//             s.pop();
//         }
//         return result;
//     }
// };

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1;
        int iSkip = 0;
        
        int j = t.size() - 1;
        int jSkip = 0;
        
        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                if (s[i] == '#') {
                    iSkip++;
                    i--;
                } else if (iSkip > 0) {
                    iSkip--;
                    i--;
                } else {
                    break;
                }
            }
            while (j >= 0) {
                if (t[j] == '#') {
                    jSkip++;
                    j--;
                } else if (jSkip > 0) {
                    jSkip--;
                    j--;
                } else {
                    break;
                }
            }
            if (i >= 0 && j >= 0) {
                if (s[i] != t[j]) {
                    return false;
                }
            }
            if ((i >= 0 && j < 0) || (i < 0 && j >= 0)) {
                return false;
            }
            i--;
            j--;
        }
        
        return true;
    }
};
