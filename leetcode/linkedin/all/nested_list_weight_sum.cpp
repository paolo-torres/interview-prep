// Each element either int or list of elements, return sum of each int multiplied by depth
// Ex. nestedList = [[1,1],2,[1,1]] -> output = 10, 1x2 + 1x2 + 2x1 + 1x2 + 1x2 = 10

// DFS traversal, if integer add to result, if list DFS and add depth

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
    int depthSum(vector<NestedInteger>& nestedList) {
        int result = 0;
        for (int i = 0; i < nestedList.size(); i++) {
            dfs(nestedList[i], 1, result);
        }
        return result;
    }
private:
    void dfs(NestedInteger& nestedList, int depth, int& result) {
        if (nestedList.isInteger()) {
            result += nestedList.getInteger() * depth;
            return;
        }
        
        for (int i = 0; i < nestedList.getList().size(); i++) {
            dfs(nestedList.getList()[i], depth + 1, result);
        }
    }
};
