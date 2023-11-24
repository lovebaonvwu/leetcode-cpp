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
  vector<int> postorder(Node* root) {
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

      for (auto& n : node->children) {
        stk.push(n);
      }
    }

    int i = 0;
    int j = ans.size() - 1;

    while (i < j) {
      swap(ans[i++], ans[j--]);
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
  vector<int> postorder(Node* root) {
    vector<int> ans;
    dfs(root, ans);

    return ans;
  }

  void dfs(Node* root, vector<int>& ans) {
    if (!root) {
      return;
    }

    for (auto& n : root->children) {
      dfs(n, ans);
    }

    ans.push_back(root->val);
  }
};  // 152ms