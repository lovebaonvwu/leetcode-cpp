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
  int maxDepth(Node* root) {
    if (!root)
      return 0;

    int max = 0;
    int h = 0;

    for (Node* n : root->children) {
      h = maxDepth(n);
      max = h > max ? h : max;
    }

    return max + 1;
  }
};  // 136ms

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
  int maxDepth(Node* root) {
    int h = 0;

    maxH(root, h);

    return h;
  }

  void maxH(Node* root, int& h) {
    if (!root)
      return;

    int max = 0;
    int temp = 0;

    for (Node* n : root->children) {
      maxH(n, temp);
      max = temp > max ? temp : max;
    }

    h = max + 1;
  }
};  // 140ms