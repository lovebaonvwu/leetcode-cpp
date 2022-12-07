class Solution {
 public:
  int maxNumberOfApples(vector<int>& weight) {
    sort(weight.begin(), weight.end());

    int sum = 0;
    int ans = 0;
    while (sum <= 5000 && ans < weight.size()) {
      sum += weight[ans++];
    }

    return sum > 5000 ? ans - 1 : ans;
  }
};
// Runtime 15 ms
// Memory 15 MB
// 2022.12.7 at 奥盛大厦