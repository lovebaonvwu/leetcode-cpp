class Solution {
 public:
  int partitionDisjoint(vector<int>& A) {
    vector<int> right_min(A.size());

    for (int i = A.size() - 1, cur_min = INT_MAX; i >= 0; --i) {
      cur_min = min(A[i], cur_min);

      right_min[i] = cur_min;
    }

    int ans = 0;
    for (int i = 0, cur_max = INT_MIN; i < A.size() - 1; ++i) {
      cur_max = max(A[i], cur_max);

      if (cur_max <= right_min[i + 1]) {
        ans = i + 1;
        break;
      }
    }

    return ans;
  }
};
// Runtime: 44 ms, faster than 65.71%
// Memory Usage: 11.5 MB, less than 100.00%

class Solution {
 public:
  int partitionDisjoint(vector<int>& A) {
    int slow = 0;
    int fast = 0;
    int cur_max = A[slow];
    int tmp_max = A[slow];

    for (; fast < A.size(); ++fast) {
      tmp_max = max(tmp_max, A[fast]);

      if (A[fast] < cur_max) {
        cur_max = tmp_max;
        slow = fast;
      }
    }

    return slow + 1;
  }
};
// Runtime: 44 ms, faster than 65.71%
// Memory Usage: 10.9 MB, less than 100.00%

class Solution {
 public:
  int partitionDisjoint(vector<int>& A) {
    int slow = 0;
    int fast = 0;
    int max = A[slow];

    for (; fast < A.size(); ++fast) {
      if (A[fast] < max) {
        max = *max_element(A.begin(), A.begin() + fast);
        slow = fast;
      }
    }

    return slow + 1;
  }
};
// Runtime: 1720 ms, faster than 5.13%
// Memory Usage: 10.9 MB, less than 100.00%