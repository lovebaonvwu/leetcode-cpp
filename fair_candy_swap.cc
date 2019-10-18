class Solution {
 public:
  vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
    int diff = (accumulate(A.begin(), A.end(), 0) -
                accumulate(B.begin(), B.end(), 0)) /
               2;

    unordered_set<int> st(A.begin(), A.end());

    for (const auto& b : B) {
      if (st.count(b + diff)) {
        return {b + diff, b};
      }
    }

    return {0, 0};
  }
};
// Runtime: 112 ms, faster than 83.92%
// Memory Usage: 21.2 MB, less than 40.00%

class Solution {
 public:
  vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
    unordered_map<int, int> mp;

    for (const auto& n : B) {
      mp[n]++;
    }

    int sum_a = 0;
    for (const auto& n : A) {
      sum_a += n;
    }

    int sum_b = 0;
    for (const auto& n : B) {
      sum_b += n;
    }

    int diff = sum_a - sum_b;

    vector<int> ans(2);

    for (const auto& a : A) {
      int target = (sum_b - sum_a + 2 * a) / 2;
      if (target > 0 && mp.find(target) != mp.end()) {
        ans[0] = a;
        ans[1] = target;
        break;
      }
    }

    return ans;
  }
};
// Runtime: 120 ms, faster than 62.17%
// Memory Usage: 22 MB, less than 10.00%

class Solution {
 public:
  vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
    int sum_a = 0;
    for (const auto& n : A) {
      sum_a += n;
    }

    int sum_b = 0;
    for (const auto& n : B) {
      sum_b += n;
    }

    vector<int> ans(2);
    for (int i = 0; i < A.size(); ++i) {
      for (int j = 0; j < B.size(); ++j) {
        if (sum_a - A[i] + B[j] == sum_b + A[i] - B[j]) {
          ans[0] = A[i];
          ans[1] = B[j];

          return ans;
        }
      }
    }

    return ans;
  }
};
// Runtime: 988 ms, faster than 9.37%
// Memory Usage: 12.2 MB, less than 80.00%