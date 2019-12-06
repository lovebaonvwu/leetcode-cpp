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
class Solution {
 public:
  Node* connect(Node* root) {
    Node* head = root;

    while (root && root->left) {
      Node* next = root->left;

      while (root) {
        root->left->next = root->right;

        if (root->next) {
          root->right->next = root->next->left;
        }

        root = root->next;
      }

      root = next;
    }

    return head;
  }
};
// Runtime: 24 ms, faster than 97.25%
// Memory Usage: 19.2 MB, less than 100.00%

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
class Solution {
 public:
  Node* connect(Node* root) {
    if (!root) {
      return root;
    }

    if (root->left) {
      root->left->next = root->right;
      root->right->next = root->next ? root->next->left : nullptr;

      connect(root->left);
      connect(root->right);
    }

    return root;
  }
};
// Runtime: 24 ms, faster than 97.25%
// Memory Usage: 19.4 MB, less than 100.00%

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
class Solution {
 public:
  Node* connect(Node* root) {
    if (!root) {
      return nullptr;
    }

    queue<Node*> q;

    q.push(root);

    while (!q.empty()) {
      int cnt = q.size();

      while (cnt > 0) {
        Node* node = q.front();
        q.pop();
        --cnt;

        if (cnt > 0) {
          node->next = q.front();
        } else {
          node->next = nullptr;
        }

        if (node->left) {
          q.push(node->left);
        }
        if (node->right) {
          q.push(node->right);
        }
      }
    }

    return root;
  }
};
// Runtime: 16 ms, faster than 99.19%
// Memory Usage: 19.6 MB, less than 100.00%