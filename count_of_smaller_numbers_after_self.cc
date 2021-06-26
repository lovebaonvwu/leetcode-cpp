struct BSTNode {
  int val;
  int count;
  int left_count;
  BSTNode* left;
  BSTNode* right;

  BSTNode(int val)
      : val(val), count(1), left_count(0), left(nullptr), right(nullptr) {}

  ~BSTNode() {
    delete left;
    delete right;
  }

  int less_or_equal() { return count + left_count; }
};

class Solution {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    vector<int> ans;

    if (nums.empty()) {
      return ans;
    }

    unique_ptr<BSTNode> root(new BSTNode(nums[nums.size() - 1]));
    ans.push_back(0);

    for (int i = nums.size() - 2; i >= 0; --i) {
      ans.push_back(insert(root.get(), nums[i]));
    }

    reverse(ans.begin(), ans.end());

    return ans;
  }

 private:
  int insert(BSTNode* root, int val) {
    if (val == root->val) {
      ++root->count;
      return root->left_count;
    } else if (val < root->val) {
      ++root->left_count;
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

      return root->less_or_equal() + insert(root->right, val);
    }
  }
};
// Runtime: 28 ms, faster than 92.85%
// Memory Usage: 20.5 MB, less than 50.00%

class Solution {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    set<int> sorted(nums.begin(), nums.end());

    size_t n = sorted.size();

    unordered_map<int, int> ranks;

    int i = 1;
    for (auto it : sorted) {
      ranks[it] = i++;
    }

    vector<int> freq(n + 1);

    vector<int> ans;
    for (int i = nums.size() - 1; i >= 0; --i) {
      int p = ranks[nums[i]];
      ans.push_back(accumulate(freq.begin(), freq.begin() + p, 0));
      ++freq[ranks[nums[i]]];
    }

    reverse(ans.begin(), ans.end());

    return ans;
  }
};
// Runtime: 184 ms, faster than 16.37%
// Memory Usage: 11 MB, less than 58.33%

class Solution {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    set<int> sorted(nums.begin(), nums.end());

    size_t n = sorted.size();

    unordered_map<int, int> ranks;

    int rank = 0;
    for (auto it : sorted) {
      ranks[it] = rank++;
    }

    vector<int> freq(n);

    vector<int> ans;
    for (int i = nums.size() - 1; i >= 0; --i) {
      int p = ranks[nums[i]];
      ans.push_back(accumulate(freq.begin(), freq.begin() + p, 0));
      ++freq[ranks[nums[i]]];
    }

    reverse(ans.begin(), ans.end());

    return ans;
  }
};
// Runtime: 192 ms, faster than 16.03%
// Memory Usage: 11.3 MB, less than 58.33%

class Solution {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    size_t n = nums.size();

    vector<int> ans(n);

    for (int i = n - 2; i >= 0; --i) {
      int cnt = 0;
      for (int j = i + 1; j < n; ++j) {
        if (nums[j] < nums[i]) {
          ++cnt;
        }
      }

      ans[i] = cnt;
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
  vector<int> ans;

 public:
  vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();

    ans.resize(n);

    vector<int> sorted = nums;

    dfs(nums, sorted, 0, n - 1);

    return ans;
  }

  void dfs(vector<int>& nums, vector<int>& sorted, int start, int end) {
    if (start == end) {
      return;
    }

    int mid = (start + end) / 2;

    dfs(nums, sorted, start, mid);
    dfs(nums, sorted, mid + 1, end);

    for (int i = start; i <= mid; ++i) {
      auto iter = lower_bound(sorted.begin() + mid + 1,
                              sorted.begin() + end + 1, nums[i]);

      ans[i] += iter - (sorted.begin() + mid + 1);
    }

    sort(sorted.begin() + start, sorted.begin() + end + 1);
  }
};
// Runtime: 652 ms, faster than 37.38%
// Memory Usage: 74.5 MB, less than 89.70%