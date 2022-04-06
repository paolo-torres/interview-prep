// DFS, calculate height of each node
// 2 longest paths in subtree = diameter

// Time: O(n)
// Space: O(n)

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int diameter(Node* root) {
        int result = 0;
        getHeight(root, result);
        return result;
    }
private:
    int getHeight(Node* root, int& result) {
        if (root == NULL) {
            return 0;
        }
        
        vector<Node*> children = root->children;
        // top 2 largest heights
        int max1 = 0;
        int max2 = 0;
        
        for (int i = 0; i < children.size(); i++) {
            // height(node) = max(height(children)) + 1
            int height = getHeight(children[i], result) + 1;
            if (height > max1) {
                max2 = max1;
                max1 = height;
            } else if (height > max2) {
                max2 = height;
            }
        }
        
        // calculate distance between 2 farthest leaf nodes
        result = max(result, max1 + max2);
        return max1;
    }
};
