/*
    Given a pizza, how many pieces can you get by making n straight
    cuts? The pieces need not be of equal size. Write an algorithm
    that, given a list of n lines representing cuts that divide the
    plane into R n regions, will provide an equation for a line which
    divides the plane into R (n + 1) regions.
    An alternate easier coding problem is to, given n, produce a list
    of n lines that divide the plane into R n regions.

    Determining the maximum number of pieces in which it is possible
    to divide a circle for a given number of cuts is called the circle
    cutting problem.

    The minimum number is always (n + 1), where n is the number of
    cuts, and it is always possible to obtain any number of pieces
    between the minimum and maximum. The first cut creates 2 regions,
    and the nth cut creates n new regions, so:

    f(1) = 2
    f(2) = 2 + f(1)
    f(n) = n + f(n - 1)

    Therefore:

    f(n) = n + [(n - 1) + f(n - 2)]

    Evaluating for n = 1, 2, ... gives 2, 4, 7, 11, 16, 22

    = n + (n - 1) + ... + 2 + f(1)
    = f(1) + sum_(k = 2)^(n)k
    = 2 + (1/2)(n + 2)(n - 1)
    = (1/2)(n^2 + n + 2)

    Time: O(1)
    Space: O(1)
*/

class Solution {
public:
    int pizzaCut(int n) {
        return (1 / 2) * (pow(n, 2) + n + 2);
    }
};
