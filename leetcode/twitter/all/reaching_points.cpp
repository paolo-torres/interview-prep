/*
    Given sx, sy, tx, ty, return true if possible to convert point (sx, sy)
    to point (tx, ty) through some operations: (x, x + y) or (x + y, y)
    Ex. sx = 1, sy = 1, tx = 3, ty = 5 -> true, (1,1), (1,2), (3,2), (3,5)

    Work backwards naive -> work backwards modulo, t to s, visualize tree

    Time: O(max(tx, ty)) -> optimize to O(log(max(tx, ty)))
    Space: O(1)
*/

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
