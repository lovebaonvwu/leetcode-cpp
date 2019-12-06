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

    Node head{};

    for (Node *cur = root, *prev = &head; cur; cur = cur->next) {
      if (cur->left) {
        prev->next = cur->left;
        prev = prev->next;
      }

      if (cur->right) {
        prev->next = cur->right;
        prev = prev->next;
      }
    }

    connect(head.next);

    return root;
  }
};
// Runtime: 12 ms, faster than 99.40%
// Memory Usage: 19.6 MB, less than 100.00%

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

    Node head{};
    Node* cur = root;

    Node* prev = &head;

    while (cur) {
      if (cur->left) {
        prev->next = cur->left;
        prev = prev->next;
      }

      if (cur->right) {
        prev->next = cur->right;
        prev = prev->next;
      }

      cur = cur->next;

      if (!cur) {
        cur = head.next;
        prev->next = nullptr;
        prev = &head;
      }
    }

    return root;
  }
};
// Runtime: 16 ms, faster than 98.33%
// Memory Usage: 19.8 MB, less than 100.00%

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
// Runtime: 16 ms, faster than 98.33%
// Memory Usage: 20 MB, less than 100.00%