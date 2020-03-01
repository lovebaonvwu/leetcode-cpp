class Solution {
 public:
  vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> sorted(nums);

    sort(sorted.begin(), sorted.end());

    vector<int> ans;

    for (int i = 0; i < nums.size(); ++i) {
      auto it = lower_bound(sorted.begin(), sorted.end(), nums[i]);
      ans.push_back(it - sorted.begin());
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 100.00%
// Memory Usage: 8.3 MB, less than 100.00%

struct BSTNode {
  int val;
  int cnt;
  int left_cnt;
  BSTNode* left;
  BSTNode* right;
  ~BSTNode() {
    delete left;
    delete right;
  }

  BSTNode(int val)
      : val(val), cnt(1), left_cnt(0), left(nullptr), right(nullptr) {}

  int less_or_equal() { return cnt + left_cnt; }
};

class Solution {
 public:
  vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    unique_ptr<BSTNode> root(new BSTNode(nums[0]));

    for (int i = 1; i < nums.size(); ++i) {
      insert(root.get(), nums[i]);
    }

    vector<int> ans;
    for (int i = 0; i < nums.size(); ++i) {
      ans.push_back(count(root.get(), nums[i]));
    }

    return ans;
  }

  int count(BSTNode* root, int val) {
    int cnt = 0;

    if (val == root->val) {
      cnt = root->left_cnt;
    } else if (val < root->val) {
      cnt = count(root->left, val);
    } else if (val > root->val) {
      cnt = root->less_or_equal() + count(root->right, val);
    }

    return cnt;
  }

  int insert(BSTNode* root, int val) {
    if (val == root->val) {
      ++root->cnt;
      return root->left_cnt;
    } else if (val < root->val) {
      ++root->left_cnt;

      if (!root->left) {
        root->left = new BSTNode(val);
        return 0;
      }

      return insert(root->left, val);
    } else {
      if (!root->right) {
        root->right = new BSTNode(val);
        return root->less_or_equal();
      }

      return insert(root->right, val) + root->less_or_equal();
    }
  }
};
// Runtime: 16 ms, faster than 93.75%
// Memory Usage: 13.9 MB, less than 100.00%

class Solution {
 public:
  vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    set<int> sorted(nums.begin(), nums.end());

    unordered_map<int, int> ranks;

    int rank = 0;
    for (auto n : sorted) {
      ranks[n] = rank++;
    }

    size_t n = nums.size();
    vector<int> cnt(n);

    for (auto a : nums) {
      ++cnt[ranks[a]];
    }

    vector<int> ans;
    for (int i = 0; i < n; ++i) {
      ans.push_back(accumulate(cnt.begin(), cnt.begin() + ranks[nums[i]], 0));
    }

    return ans;
  }
};
// Runtime: 20 ms, faster than 68.75%
// Memory Usage: 9.2 MB, less than 100.00%

class Solution {
 public:
  vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> ans;

    size_t n = nums.size();
    for (int i = 0; i < n; ++i) {
      int cnt = 0;
      for (int j = 0; j < n; ++j) {
        if (j != i && nums[j] < nums[i]) {
          ++cnt;
        }
      }

      ans.push_back(cnt);
    }

    return ans;
  }
};
// Runtime: 32 ms, faster than 62.50%
// Memory Usage: 8.1 MB, less than 100.00%