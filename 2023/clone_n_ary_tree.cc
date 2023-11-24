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
  Node* cloneTree(Node* root) {
    if (!root) {
      return nullptr;
    }

    Node* clonedNode = new Node(root->val);
    for (auto child : root->children) {
      clonedNode->children.push_back(cloneTree(child));
    }

    return clonedNode;
  }
};
// Runtime 60 ms
// Memory 175.3 MB
// 2023.1.29 at 奥盛大厦