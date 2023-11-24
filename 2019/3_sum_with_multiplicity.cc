class Solution {
 public:
  int threeSumMulti(vector<int>& A, int target) {
    unordered_map<int, long> mp;

    for (const auto& a : A) {
      ++mp[a];
    }

    long res = 0;
    for (auto it1 : mp) {
      for (auto it2 : mp) {
        int i = it1.first, j = it2.first, k = target - i - j;

        if (mp.count(k)) {
          if (i == j && j == k) {
            res += mp[i] * (mp[i] - 1) * (mp[i] - 2) / 6;
          } else if (i == j && i != k) {
            res += mp[i] * (mp[i] - 1) / 2 * mp[k];
          } else if (i < j && j < k) {
            res += mp[i] * mp[j] * mp[k];
          }
        }
      }
    }

    return res % int(1e9 + 7);
  }
};
// Runtime: 16 ms, faster than 67.79%
// Memory Usage: 9.1 MB, less than 100.00%

class Solution {
 public:
  int threeSumMulti(vector<int>& A, int target) {
    int i = 0;
    int j = A.size() - 1;

    long ans = 0;

    for (int i = 0; i < A.size() - 2; ++i) {
      for (int j = A.size() - 1; j > i + 1; --j) {
        for (int k = i + 1; k < j; ++k) {
          if (A[i] + A[k] + A[j] == target) {
            ++ans;
          }
        }
      }
    }

    return (int)(ans % ((int)pow(10, 2) + 7));
  }
};
//	Time Limit Exceeded