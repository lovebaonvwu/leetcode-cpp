class Solution {
  class SegmentTree {
   public:
    SegmentTree(int a, int b)
        : left(nullptr),
          right(nullptr),
          start(a),
          end(b),
          info(0),
          tag(false) {}

    SegmentTree* left;
    SegmentTree* right;
    int start;
    int end;
    int info;
    bool tag;
  };

  void init(SegmentTree* node, int a, int b) {
    if (a == b) {
      node->info = 0;
      return;
    }

    int mid = (a + b) / 2;

    if (node->left == nullptr) {
      node->left = new SegmentTree(a, mid);
      node->right = new SegmentTree(mid + 1, b);
    }

    init(node->left, a, mid);
    init(node->right, mid + 1, b);

    node->info = 0;
  }

  int queryRange(SegmentTree* node, int a, int b) {
    if (a > node->end || b < node->start) {
      return 0;
    }

    if (a <= node->start && b >= node->end) {
      return node->info;
    }

    pushdown(node);

    node->info =
        max(queryRange(node->left, a, b), queryRange(node->right, a, b));
    return node->info;
  }

  void updateRange(SegmentTree* node, int a, int b, int val) {
    if (a > node->end || b < node->start) {
      return;
    }

    if (a <= node->start && b >= node->end) {
      node->info = val;
      node->tag = true;
      return;
    }

    pushdown(node);
    updateRange(node->left, a, b, val);
    updateRange(node->right, a, b, val);

    node->info = max(node->left->info, node->right->info);
  }

  void pushdown(SegmentTree* node) {
    if (node->tag) {
      node->left->info = node->info;
      node->right->info = node->info;
      node->left->tag = true;
      ;
      node->right->tag = true;
      ;
      node->tag = false;
      ;
    }
  }

 public:
  vector<int> fallingSquares(vector<vector<int>>& positions) {
    set<int> st;
    for (auto& p : positions) {
      st.insert(p[0]);
      st.insert(p[0] + p[1]);
    }

    unordered_map<int, int> mp;
    int id = 0;
    for (auto p : st) {
      mp[p] = id;
      id++;
    }

    vector<int> ans;
    int maxh = 0;

    int n = mp.size();

    SegmentTree* root = new SegmentTree(0, n - 1);
    init(root, 0, n - 1);

    for (auto& p : positions) {
      int a = mp[p[0]];
      int b = mp[p[0] + p[1]];
      int h = queryRange(root, a, b - 1);
      updateRange(root, a, b - 1, h + p[1]);
      maxh = max(maxh, h + p[1]);

      ans.push_back(maxh);
    }

    return ans;
  }
};
// Runtime: 113 ms, faster than 35.42%
// Memory Usage: 23.1 MB, less than 10.00%
// 2022.8.19 at 奥盛大厦