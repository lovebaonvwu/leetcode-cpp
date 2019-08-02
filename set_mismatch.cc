class Solution {
 public:
  vector<int> findErrorNums(vector<int>& nums) {
    int sum = 0, a = 0, b = 0;

    for (int i = 1; i <= nums.size(); ++i) {
      sum ^= nums[i - 1] ^ i;
    }

    sum &= -sum;

    for (int i = 1; i <= nums.size(); ++i) {
      sum& i ? a ^= i : b ^= i;
      sum& nums[i - 1] ? a ^= nums[i - 1] : b ^= nums[i - 1];
    }

    for (auto& n : nums) {
      if (a == n) {
        return {a, b};
      }
    }

    return {b, a};
  }
};  // 36ms

class Solution {
 public:
  vector<int> findErrorNums(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
      while (nums[i] != nums[nums[i] - 1]) {
        swap(nums[i], nums[nums[i] - 1]);
      }
    }

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != i + 1) {
        return {nums[i], i + 1};
      }
    }

    return {-1, -1};
  }
};  // 36ms

class Solution {
 public:
  vector<int> findErrorNums(vector<int>& nums) {
    vector<int> ans(2);

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 1; ++i) {
      if (nums[i] == nums[i + 1]) {
        ans[0] = nums[i];
        break;
      }
    }

    int sum = 0;
    for (int i = 1; i <= nums.size(); ++i) {
      nums[i - 1] ^= i;
      sum ^= nums[i - 1];
    }

    ans[1] = sum ^ ans[0];

    return ans;
  }
};  // 48ms