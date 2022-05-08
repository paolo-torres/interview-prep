/*
    Given perfect binary tree, populate each next ptr to its right
    Ex. root = [1,2,3,4,5,6,7] -> [1,#,2,3,#,4,5,6,7,#]

    Level order traversal -> optimize w/ prev established next ptrs

    Time: O(n)
    Space: O(n) -> optimize to O(1)
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// class Solution {
// public:
//     Node* connect(Node* root) {
//         if (root == NULL) {
//             return NULL;
//         }
//         queue<Node*> q;
//         q.push(root);
//         while (!q.empty()) {
//             int count = q.size();
//             Node* rightNode = NULL;
//             for (int i = count; i > 0; i--) {
//                 Node* node = q.front();
//                 q.pop();
//                 node->next = rightNode;
//                 rightNode = node;
//                 if (node->right != NULL) {
//                     q.push(node->right);
//                 }
//                 if (node->left != NULL) {
//                     q.push(node->left);
//                 }
//             }
//         }
//         return root;
//     }
// };

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return NULL;
        }
        
        Node* leftmost = root;
        while (leftmost->left != NULL) {
            // iterate "linked list", establish links for next level
            Node* head = leftmost;
            while (head != NULL) {
                // connection 1
                head->left->next = head->right;
                // connection 2
                if (head->next != NULL) {
                    head->right->next = head->next->left;
                }
                head = head->next;
            }
            leftmost = leftmost->left;
        }
        return root;
    }
};
