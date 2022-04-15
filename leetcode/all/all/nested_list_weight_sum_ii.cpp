// Each element either int or list of elements, return sum of each int multiplied by weight
// Ex. nestedList = [[1,1],2,[1,1]] -> output = 8, 1x1 + 1x1 + 2x2 + 1x1 + 1x1 = 8

// BFS traversal, if integer add to result, if list add to queue for next level

// Time: O(n)
// Space: O(n)

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        queue<NestedInteger> q;
        for (int i = 0; i < nestedList.size(); i++) {
            q.push(nestedList[i]);
        }
        
        int depth = 1;
        int maxDepth = 0;
        
        int sumOfElements = 0;
        int sumOfProducts = 0;
        
        while (!q.empty()) {
            int count = q.size();
            maxDepth = max(maxDepth, depth);
            
            for (int i = 0; i < count; i++) {
                NestedInteger nested = q.front();
                q.pop();
                
                /*
                    sum(a x weight)
                    = sum(a x (maxDepth - depth + 1))
                    = sum(a x maxDepth - a x depth + a)
                    = sum(a x maxDepth) - sum(a x depth) + sum(a)
                    = maxDepth x sum(a) - sum(a x depth) + sum(a)
                    = (maxDepth + 1) x sum(a) - sum(a x depth)
                    = (maxDepth + 1) x sumOfElements - sumOfProducts
                */
                if (nested.isInteger()) {
                    sumOfElements += nested.getInteger();
                    sumOfProducts += nested.getInteger() * depth;
                } else {
                    for (int j = 0; j < nested.getList().size(); j++) {
                        q.push(nested.getList()[j]);
                    }
                }
            }
            
            depth++;
        }
        
        return (maxDepth + 1) * sumOfElements - sumOfProducts;
    }
};
