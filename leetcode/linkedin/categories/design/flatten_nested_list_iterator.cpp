// Given a nested list of ints, each element is either an int or list of elements, flatten it
// Ex. input = [[1,1],2,[1,1]] -> output = [1,1,2,1,1]

// Stack of iterators, hasNext finds next int, next returns it and moves on
// Call hasNext in next because hasNext is "optional", user might only call next

// Time: O(n)
// Space: O(n)

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        begins.push(nestedList.begin());
        ends.push(nestedList.end());
    }
    
    int next() {
        hasNext();
        int result = begins.top()->getInteger();
        begins.top()++;
        return result;
    }
    
    bool hasNext() {
        while (!begins.empty()) {
            if (begins.top() == ends.top()) {
                begins.pop();
                ends.pop();
            } else {
                auto curr = begins.top();
                if (curr->isInteger()) {
                    return true;
                }
                begins.top()++;
                begins.push(curr->getList().begin());
                ends.push(curr->getList().end());
            }
        }
        return false;
    }
private:
    stack<vector<NestedInteger>::iterator> begins, ends;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
