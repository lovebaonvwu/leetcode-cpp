class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    size_t n = nums.size();

    vector<int> ans(n, 1);

    for (int i = 1; i < n; ++i) {
      ans[i] = ans[i - 1] * nums[i - 1];
    }

    int tmp = 1;
    for (int i = n - 1; i >= 0; --i) {
      ans[i] = ans[i] * tmp;
      tmp *= nums[i];
    }

    return ans;
  }
};  // 36ms

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();

    vector<int> head(n);
    vector<int> tail(n);

    head[0] = 1;
    tail[n - 1] = 1;

    for (int i = 1; i < n; ++i) {
      head[i] = head[i - 1] * nums[i - 1];
    }

    for (int i = n - 2; i >= 0; --i) {
      tail[i] = tail[i + 1] * nums[i + 1];
    }

    vector<int> ans(n);

    for (int i = 0; i < n; ++i) {
      ans[i] = head[i] * tail[i];
    }

    return ans;
  }
};  // 44ms