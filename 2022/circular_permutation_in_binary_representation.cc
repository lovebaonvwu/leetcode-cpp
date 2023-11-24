class Solution {
 public:
  vector<int> circularPermutation(int n, int start) {
    vector<int> ans;

    ans.push_back(0);

    for (int i = 0; i < n; ++i) {
      for (int j = ans.size() - 1; j >= 0; --j) {
        ans.push_back(ans[j] + (1 << i));
      }
    }

    int i = 0;
    while (ans[i] != start) {
      ++i;
    }

    reverse(ans.begin() + i, ans.end());
    reverse(ans.begin(), ans.begin() + i);
    reverse(ans.begin(), ans.end());

    return ans;
  }
};
// Runtime: 24 ms, faster than 69.23%
// Memory Usage: 17.6 MB, less than 80.42%
// 2022.3.18 at 奥盛大厦

class Solution {
 public:
  vector<int> circularPermutation(int n, int start) {
    int size = pow(2, n);

    vector<int> ans(size, 0);

    for (int i = 0; i < size; ++i) {
      ans[i] = i ^ (i >> 1);
    }

    int i = 0;
    while (ans[i] != start) {
      ++i;
    }

    reverse(ans.begin() + i, ans.end());
    reverse(ans.begin(), ans.begin() + i);
    reverse(ans.begin(), ans.end());

    return ans;
  }
};
// Runtime: 16 ms, faster than 91.96%
// Memory Usage: 16.5 MB, less than 88.46%
// 2022.3.18 at 奥盛大厦