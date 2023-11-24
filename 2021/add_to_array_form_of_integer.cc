class Solution {
 public:
  vector<int> addToArrayForm(vector<int>& A, int K) {
    int& k = K;

    reverse(A.begin(), A.end());

    int r = 0;
    int carry = 0;

    for (int i = 0; i < A.size() || k > 0 || carry; ++i) {
      r = k % 10;
      k /= 10;

      if (i >= A.size()) {
        int sum = r + carry;
        if (sum > 9) {
          A.push_back(sum % 10);
          carry = 1;
        } else {
          A.push_back(sum);
          carry = 0;
        }
      } else {
        A[i] = A[i] + r + carry;
        if (A[i] > 9) {
          A[i] %= 10;
          carry = 1;
        } else {
          carry = 0;
        }
      }
    }

    reverse(A.begin(), A.end());

    return A;
  }
};