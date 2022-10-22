class Solution {
 public:
  int findMaxK(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    unordered_set<int> st;
    int ans = -1;
    for (auto n : nums) {
      if (n > 0) {
        if (st.find(-n) != st.end()) {
          ans = max(ans, n);
        }
      } else {
        st.insert(n);
      }
    }

    return ans;
  }
};
// Runtime: 53 ms, faster than 64.61%
// Memory Usage: 21.3 MB, less than 66.78%
// 2022.10.22 at 茗筑美嘉

class Solution {
 public:
  int findMaxK(vector<int>& nums) {
    unordered_set<int> st(nums.begin(), nums.end());

    int ans = -1;
    for (auto n : nums) {
      if (n > 0) {
        if (st.find(-n) != st.end()) {
          ans = max(ans, n);
        }
      } else {
        st.insert(n);
      }
    }

    return ans;
  }
};
// Runtime: 80 ms, faster than 25.87%
// Memory Usage: 22.8 MB, less than 55.14%
// 2022.10.22 at 茗筑美嘉

class Solution {
 public:
  int findMaxK(vector<int>& nums) {
    unordered_set<int> st(nums.begin(), nums.end());

    int ans = -1;
    for (auto n : nums) {
      if (n > 0) {
        if (st.find(-n) != st.end()) {
          ans = max(ans, n);
        }
      }
    }

    return ans;
  }
};
// Runtime: 42 ms, faster than 80.14%
// Memory Usage: 22.8 MB, less than 50.78%
// 2022.10.22 at 茗筑美嘉
