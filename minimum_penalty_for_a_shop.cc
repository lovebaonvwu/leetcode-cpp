class Solution {
 public:
  int bestClosingTime(string customers) {
    int n = customers.size();

    vector<int> N(n + 1);
    N[1] = customers[0] == 'N';

    vector<int> Y(n + 1);
    Y[n - 1] = customers[n - 1] == 'Y';

    for (int i = 2, j = n - 2; i < n + 1; ++i, --j) {
      N[i] = N[i - 1] + (customers[i - 1] == 'N');
      Y[j] = Y[j + 1] + (customers[j] == 'Y');
    }

    int pen = n;
    int ans = 0;
    for (int i = 0; i < n + 1; ++i) {
      if (N[i] + Y[i] < pen) {
        ans = i;
        pen = N[i] + Y[i];
      }
    }

    return ans;
  }
};
// Runtime 44 ms
// Memory 18.8 MB
// 2023.2.24 at 奥盛大厦