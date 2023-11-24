/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
 public:
  vector<int> preorder(Node* root) {
    vector<int> ans;

    if (!root) {
      return ans;
    }

    stack<Node*> stk;
    stk.push(root);

    while (!stk.empty()) {
      Node* node = stk.top();
      stk.pop();

      ans.push_back(node->val);

      for (int i = node->children.size() - 1; i >= 0; --i) {
        stk.push(node->children[i]);
      }
    }

    return ans;
  }
};  // 156ms

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
 public:
  vector<int> preorder(Node* root) {
    vector<int> ans;

    dfs(root, ans);

    return ans;
  }

  void dfs(Node* root, vector<int>& ans) {
    if (!root) {
      return;
    }

    ans.push_back(root->val);

    for (auto& node : root->children) {
      dfs(node, ans);
    }
  }
};  // 144ms