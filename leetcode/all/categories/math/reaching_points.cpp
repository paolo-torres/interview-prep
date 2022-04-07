// // Recursive exhaustive -> work backwards, t to s, visualize tree

// // Time: O(max(tx, ty))
// // Space: O(1)

// class Solution {
// public:
//     bool reachingPoints(int sx, int sy, int tx, int ty) {
//         while (sx <= tx && sy <= ty) {
//             if (sx == tx && sy == ty) {
//                 return true;
//             }
//             if (tx > ty) {
//                 tx -= ty;
//             } else {
//                 ty -= tx;
//             }
//         }
//         return false;
//     }
// };

// O(log(max(tx, ty)))
// Space: O(1)

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (sx <= tx && sy <= ty) {
            if (tx == ty) {
                break;
            } else if (tx > ty) {
                if (sy < ty) {
                    tx %= ty;
                } else {
                    return (tx - sx) % ty == 0;
                }
            } else {
                if (sx < tx) {
                    ty %= tx;
                } else {
                    return (ty - sy) % tx == 0;
                }
            }
        }
        return sx == tx && sy == ty;
    }
};
