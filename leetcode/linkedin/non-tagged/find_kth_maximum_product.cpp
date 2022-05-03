/*
    Given 2 unsorted arrays A1 and A2 containing negative and positive
    integers of different lengths, find the kth maximum product of
    A1[i] * A2[j] (a number from A1 times a number of A2).
    
    Ex. A1 = [7,-20,3,0,10,-70], A2 = [0,1,-12,100,-30], k = 3

    1st max = -70 x -30 = 2100
    2nd max = 100 * 10 = 1000
    k = 3rd max = -70 * -12 = 840 -> answer = 840

    Time: O(m log m + n log n)
    Space: O(m + n)
*/

class Solution {
public:
    int kthMaxProduct(vector<int>& A1, vector<int>& A2, int k) {
        // separate out positive and negative nums into 4 lists
        vector<int> A1pos;
        vector<int> A1neg;
        vector<int> A2pos;
        vector<int> A2neg;

        for (int i = 0; i < A1.size(); i++) {
            if (A1[i] >= 0) {
                A1pos.push_back(A1[i]);
            } else {
                A1neg.push_back(A1[i]);
            }
        }
        for (int i = 0; i < A2.size(); i++) {
            if (A2[i] >= 0) {
                A2pos.push_back(A2[i]);
            } else {
                A2neg.push_back(A2[i]);
            }
        }

        /*
            4 combos: (A1pos, A2pos), (A1neg, A2neg),
                      (A1pos, A2neg), (A1neg, A2pos)
            2 will give positive product, other 2 negative product.

            If k > len(A1pos) * len(A2pos) + len(A1neg) * len(A2neg),
            then kth maximum product is negative, else positive.

            Say kth max product is positive, so pick the 2 buckets:
            (A1pos, A2pos), (A1neg, A2neg).
        */

        sort(A1pos.begin(), A1pos.end());
        sort(A1neg.begin(), A1neg.end());
        sort(A2pos.begin(), A2pos.end());
        sort(A2neg.begin(), A2neg.end());

        int a = A1pos.size();
        int b = A1neg.size();
        int c = A2pos.size();
        int d = A2neg.size();

        priority_queue<vector<int>> pq;

        if (k <= a * b + c * d) {
            // kth max product is positive

            int product1 = A1pos[a - 1] * A2pos[c - 1];
            int product2 = A1neg[b - 1] * A2neg[d - 1];

            pq.push({product1, a - 1, c - 1});
            pq.push({product2, b - 1, d - 1});

            while (k > 1) {
                int curr = pq.top()[0];
                int i = pq.top()[1];
                int j = pq.top()[2];
                // pop current maximum
                pq.pop();

                if (i < a && j < c && curr == A1pos[i] * A2pos[j]) {
                    product1 = A1pos[i - 1] * A2pos[j];
                    product2 = A1pos[i] * A2pos[j - 1]; 
                } else {
                    product1 = A1neg[i - 1] * A2neg[j];
                    product2 = A1neg[i] * A2neg[j - 1];
                }

                // insert next 2 possible max elements
                pq.push({product1, i - 1, j});
                pq.push({product2, i, j - 1});

                k--;
            }
        } else {
            // kth max product is negative

            int product1 = A1pos[a - 1] * A1neg[b - 1];
            int product2 = A2pos[c - 1] * A2neg[d - 1];

            pq.push({product1, a - 1, b - 1});
            pq.push({product2, c - 1, d - 1});

            while (k > 1) {
                int curr = pq.top()[0];
                int i = pq.top()[1];
                int j = pq.top()[2];
                // pop current maximum
                pq.pop();

                if (i < a && j < b && curr == A1pos[i] * A1neg[j]) {
                    product1 = A1pos[i - 1] * A1neg[j];
                    product2 = A1pos[i] * A1neg[j - 1]; 
                } else {
                    product1 = A2pos[i - 1] * A2neg[j];
                    product2 = A2pos[i] * A2neg[j - 1];
                }

                // insert next 2 possible max elements
                pq.push({product1, i - 1, j});
                pq.push({product2, i, j - 1});

                k--;
            }
        }

        // kth element is the answer
        return pq.top();
    }
};
