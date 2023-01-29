/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left),
 * right(right), random(random) {}
 * };
 */

class Solution {
  unordered_map<Node*, NodeCopy*> mp;

 public:
  NodeCopy* copyRandomBinaryTree(Node* root) {
    NodeCopy* cloned = clone(root);
    dfs(root, cloned);

    return cloned;
  }

  NodeCopy* clone(Node* root) {
    if (!root) {
      return nullptr;
    }

    NodeCopy* cloned = new NodeCopy(root->val);
    mp[root] = cloned;
    cloned->left = clone(root->left);
    cloned->right = clone(root->right);

    return cloned;
  }

  void dfs(Node* p, NodeCopy* q) {
    if (!p) {
      return;
    }

    dfs(p->left, q->left);
    dfs(p->right, q->right);

    q->random = mp[p->random];
  }
};
// Runtime 272 ms
// Memory 76 MB
// 2023.1.29 at 奥盛大厦