class Solution {
 public:
  vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    if (nums.empty()) {
      vector<string> ans;
      if (lower == upper) {
        ans.push_back(to_string(lower));
      } else {
        ans.push_back(to_string(lower) + "->" + to_string(upper));
      }

      return ans;
    }

    int prev = lower - 1;
    nums.push_back(upper + 1);

    vector<string> ans;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > prev + 1) {
        int a = prev + 1;
        int b = nums[i] - 1;

        if (a == b) {
          ans.push_back(to_string(a));
        } else {
          ans.push_back(to_string(a) + "->" + to_string(b));
        }
      }

      prev = nums[i];
    }

    return ans;
  }
};
// Runtime 0 ms
// Memory 7.1 MB
// 2023.2.2 at 聊城月季西路长江路

class Solution {
 public:
  vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    int prev = lower - 1;
    nums.push_back(upper + 1);

    vector<string> ans;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > prev + 1) {
        int a = prev + 1;
        int b = nums[i] - 1;

        if (a == b) {
          ans.push_back(to_string(a));
        } else {
          ans.push_back(to_string(a) + "->" + to_string(b));
        }
      }

      prev = nums[i];
    }

    return ans;
  }
};
// Runtime 0 ms
// Memory 7 MB
// 2023.2.2 at 聊城月季西路长江路