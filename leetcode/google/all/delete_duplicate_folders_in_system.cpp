/*
    Many duplicate folders in file system, given 2D array of absolute paths:
    For example, ["one","two","three"] represents the path "/one/two/three"
    2 folders are identical if they contain the same subfolders/structure
    Return 2D array containing path of remaining folders after deleting dupes

    Build folder tree based on paths, visit all nodes, if seen before mark delete
    Generate paths and DFS to generate output, skip nodes that were deleted

    Time: O(n x d x w x log c + n^2 x w) -> n = # of folder, d = deepest folder
        w = max length of folder name, c = max # of child folders
    Space: O(n^2 x w)
*/

struct Node {
    string name;
    // {folder name -> corresponding child node}
    map<string, Node*> next;
    bool isDeleted = false;
    Node(string n = "") : name(n) {}
};

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node root;
        for (int i = 0; i < paths.size(); i++) {
            addPath(&root, paths[i]);
        }
        dedupe(&root);
        for (auto &[name, next] : root.next) {
            getPath(next);
        }
        return result;
    }
private:
    // map subfolder structure string to first occurrence node
    unordered_map<string, Node*> seen;
    vector<string> path;
    vector<vector<string>> result;
    
    // given path, add nodes to folder tree
    void addPath(Node* node, vector<string>& path) {
        for (int i = 0; i < path.size(); i++) {
            if (node->next.find(path[i]) == node->next.end()) {
                node->next[path[i]] = new Node(path[i]);
            }
            node = node->next[path[i]];
        }
    }
    
    // if seen subfolder structure before, mark it as deleted
    string dedupe(Node* node) {
        string subfolder = "";
        for (auto &[name, next] : node->next) {
            subfolder += dedupe(next);
        }
        // to ignore leaf nodes
        if (!subfolder.empty()) {
            if (seen.find(subfolder) != seen.end()) {
                seen[subfolder]->isDeleted = true;
                node->isDeleted = true;
            } else {
                seen[subfolder] = node;
            }
        }
        return "(" + node->name + subfolder + ")";
    }
    
    void getPath(Node* node) {
        // if node is deleted, skip
        if (node->isDeleted) {
            return;
        }
        path.push_back(node->name);
        result.push_back(path);
        for (auto &[name, next] : node->next) {
            getPath(next);
        }
        path.pop_back();
    }
};
