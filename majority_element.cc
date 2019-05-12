class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int ans, cnt = 0;

    for (int n : nums) {
      if (!cnt) {
        ans = n;
        ++cnt;
      } else if (ans == n) {
        ++cnt;
      } else {
        --cnt;
      }
    }

    return ans;
  }
};  // 16ms

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    map<int, int> m;

    int times = nums.size() >> 1;

    for (int i : nums) {
      if (!m[i]) {
        m[i] = 1;
      } else {
        m[i] = ++m[i];
      }

      if (m[i] > times)
        return i;
    }

    return -1;
  }
};  // 28ms