class MyCalendar {
  vector<pair<int, int>> v;

 public:
  MyCalendar() {}

  bool book(int start, int end) {
    for (auto& [s, e] : v) {
      if (max(start, s) < min(end, e)) {
        return false;
      }
    }

    v.push_back({start, end});

    return true;
  }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// Runtime: 612 ms, faster than 5.54%
// Memory Usage: 37.7 MB, less than 16.67%

struct Node {
  int start;
  int end;
  Node* left;
  Node* right;

  Node(int s, int e) : start(s), end(e), left(nullptr), right(nullptr) {}
};

class MyCalendar {
  Node* root = nullptr;

  bool dfs(Node* root, int start, int end) {
    if (start >= root->end) {
      if (!root->right) {
        root->right = new Node(start, end);
        return true;
      }

      return dfs(root->right, start, end);
    } else if (end <= root->start) {
      if (!root->left) {
        root->left = new Node(start, end);
        return true;
      }

      return dfs(root->left, start, end);
    }

    return false;
  }

 public:
  MyCalendar() {}

  bool book(int start, int end) {
    if (!root) {
      root = new Node(start, end);
      return true;
    }

    return dfs(root, start, end);
  }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// Runtime: 200 ms, faster than 44.23%
// Memory Usage: 38.3 MB, less than 16.67%