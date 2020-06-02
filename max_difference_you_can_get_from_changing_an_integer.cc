class Solution {
 public:
  int maxDiff(int num) {
    vector<int> nums;

    while (num > 0) {
      nums.push_back(num % 10);

      num /= 10;
    }

    reverse(nums.begin(), nums.end());

    int a = 0;
    bool mod = false;
    for (int i = 0, from = -1; i < nums.size(); ++i) {
      if (nums[i] == from || (!mod && nums[i] < 9)) {
        a = a * 10 + 9;
        from = nums[i];
        mod = true;
      } else {
        a = a * 10 + nums[i];
      }
    }

    int b = 0;
    mod = false;
    for (int i = 0, from = -1, to = -1; i < nums.size(); ++i) {
      if (from == nums[i] || (!mod && nums[i] > 1)) {
        if (i == 0) {
          b = b * 10 + 1;
          if (to < 0) {
            to = 1;
          }
        } else {
          if (to < 0) {
            to = 0;
          }
          b = b * 10 + to;
        }
        from = nums[i];
        mod = true;
      } else {
        b = b * 10 + nums[i];
      }
    }

    return a - b;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.2 MB, less than 100.00%

class Solution {
 public:
  int maxDiff(int num) {
    vector<int> nums;

    while (num > 0) {
      nums.push_back(num % 10);

      num /= 10;
    }

    reverse(nums.begin(), nums.end());

    int a = 0;
    bool mod = false;
    for (int i = 0, from = -1, cur = 0; i < nums.size(); ++i) {
      cur = nums[i];

      if (nums[i] == from || (!mod && nums[i] < 9)) {
        from = nums[i];
        mod = true;
        cur = 9;
      }

      a = a * 10 + cur;
    }

    int b = 0;
    mod = false;
    for (int i = 0, from = -1, to = -1, cur = 0; i < nums.size(); ++i) {
      cur = nums[i];

      if (from == nums[i] || (!mod && nums[i] > 1)) {
        if (i == 0 && to < 0) {
          to = 1;
        } else if (to < 0) {
          to = 0;
        }
        from = nums[i];
        mod = true;
        cur = to;
      }

      b = b * 10 + cur;
    }

    return a - b;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.2 MB, less than 100.00%

class Solution {
  string replace(const string& s, char src, char dst) {
    string res;

    for (auto c : s) {
      if (c == src) {
        res += dst;
      } else {
        res += c;
      }
    }

    return res;
  }

 public:
  int maxDiff(int num) {
    int minNum = INT_MAX;
    int maxNum = INT_MIN;

    string nums = "0123456789";

    for (auto i : nums) {
      for (auto j : nums) {
        string nextNum = replace(to_string(num), i, j);

        if (nextNum[0] == '0') {
          continue;
        }

        minNum = min(minNum, stoi(nextNum));
        maxNum = max(maxNum, stoi(nextNum));
      }
    }

    return maxNum - minNum;
  }
};
// Runtime: 16 ms, faster than 6.72%
// Memory Usage: 5.9 MB, less than 100.00%