class Solution {
 public:
  int getMaxLen(vector<int>& nums) {
    int ans = 0;

    int n = nums.size();

    for (int i = 0; i < n; ++i) {
      if (nums[i] == 0) {
        continue;
      }

      int neg = nums[i] < 0 ? 1 : 0;
      int pos = 1 - neg;

      ans = max(ans, pos);

      for (int j = i + 1; j < n; ++j) {
        if (nums[j] == 0) {
          break;
        } else if (nums[j] > 0) {
          ++pos;
        } else {
          ++neg;
        }

        if (neg % 2 == 0) {
          ans = max(ans, j - i + 1);
        }
      }
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int getMaxLen(vector<int>& nums) {
    int ans = 0;

    for (int i = 0, neg_cnt = 0, neg_idx = -1, pos_idx = -1, n = nums.size();
         i < n; ++i) {
      if (nums[i] == 0) {
        neg_idx = -1;
        neg_cnt = 0;
        pos_idx = i;

        continue;
      }

      if (nums[i] < 0) {
        ++neg_cnt;
      }

      if (neg_cnt == 1 && neg_idx == -1) {
        neg_idx = i;
      }

      if (neg_cnt % 2 == 0) {
        ans = max(ans, i - pos_idx);
      } else {
        ans = max(ans, i - neg_idx);
      }
    }

    return ans;
  }
};
// Runtime: 252 ms, faster than 90.04%
// Memory Usage: 57.9 MB, less than 98.24%

class Solution {
 public:
  int getMaxLen(vector<int>& nums) {
    int n = nums.size();

    vector<int> pos(n);
    vector<int> neg(n);

    pos[0] = nums[0] > 0;
    neg[0] = nums[0] < 0;

    int ans = pos[0];

    for (int i = 1; i < n; ++i) {
      if (nums[i] > 0) {
        pos[i] = pos[i - 1] + 1;
        neg[i] = neg[i - 1] > 0 ? neg[i - 1] + 1 : 0;
      } else if (nums[i] < 0) {
        pos[i] = neg[i - 1] > 0 ? neg[i - 1] + 1 : 0;
        neg[i] = pos[i - 1] + 1;
      }

      ans = max(ans, pos[i]);
    }

    return ans;
  }
};
// Runtime: 268 ms, faster than 62.96%
// Memory Usage: 62.9 MB, less than 11.11%

class Solution {
 public:
  int getMaxLen(vector<int>& nums) {
    int n = nums.size();

    int pos = nums[0] > 0;
    int neg = nums[0] < 0;

    int ans = pos;

    for (int i = 1; i < n; ++i) {
      if (nums[i] > 0) {
        pos = pos + 1;
        neg = neg > 0 ? neg + 1 : 0;
      } else if (nums[i] < 0) {
        int tmp = pos;
        pos = neg > 0 ? neg + 1 : 0;

        neg = tmp + 1;
      } else {
        pos = 0;
        neg = 0;
      }

      ans = max(ans, pos);
    }

    return ans;
  }
};
// Runtime: 244 ms, faster than 96.55%
// Memory Usage: 58.1 MB, less than 53.24%