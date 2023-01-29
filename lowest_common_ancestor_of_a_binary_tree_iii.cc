/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
  unordered_set<Node*> parent;

 public:
  Node* lowestCommonAncestor(Node* p, Node* q) {
    parent.insert(p);
    parent.insert(q);

    Node* ans = dfs(p);

    return ans ? ans : dfs(q);
  }

  Node* dfs(Node* root) {
    if (!root) {
      return nullptr;
    }

    if (parent.find(root->parent) != parent.end()) {
      return root->parent;
    }

    parent.insert(root->parent);
    return dfs(root->parent);
  }
};
// Runtime 18 ms
// Memory 14.2 MB
// 2023.1.29 at 奥盛大厦