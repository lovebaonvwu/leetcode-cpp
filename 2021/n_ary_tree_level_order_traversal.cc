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
  vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> ans;

    if (!root) {
      return ans;
    }

    queue<Node*> q;
    q.push(root);
    int cnt = 1;
    vector<int> level;

    while (!q.empty()) {
      Node* node = q.front();
      q.pop();
      --cnt;

      level.push_back(node->val);

      for (auto& n : node->children) {
        q.push(n);
      }

      if (!cnt) {
        ans.push_back(level);
        level.clear();

        cnt = q.size();
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
  vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> ans;

    if (!root) {
      return ans;
    }

    queue<Node*> q;
    q.push(root);
    int cnt = 1;
    vector<int> level;

    while (!q.empty()) {
      while (cnt) {
        Node* node = q.front();
        q.pop();
        --cnt;

        level.push_back(node->val);

        for (auto& n : node->children) {
          q.push(n);
        }
      }

      ans.push_back(level);
      level.clear();

      cnt = q.size();
    }

    return ans;
  }
};  // 172ms