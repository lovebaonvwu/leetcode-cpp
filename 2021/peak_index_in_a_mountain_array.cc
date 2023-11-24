class Solution {
 public:
  int peakIndexInMountainArray(vector<int>& A) {
    int lo = 0;
    int hi = A.size() - 1;

    while (lo < hi) {
      int md = lo + (hi - lo) / 2;

      if (A[md] > A[md + 1]) {
        hi = md;
      } else {
        lo = md + 1;
      }
    }

    return lo;
  }
};  // 16ms

class Solution {
 public:
  int peakIndexInMountainArray(vector<int>& A) {
    return max_element(A.begin(), A.end()) - A.begin();
  }
};  // 20ms

class Solution {
 public:
  int peakIndexInMountainArray(vector<int>& A) {
    int idx = -1;
    int top = INT_MIN;

    for (int i = 0; i < A.size(); ++i) {
      if (A[i] > top) {
        idx = i;
        top = A[i];
      }
    }

    return idx;
  }
};  // 28ms