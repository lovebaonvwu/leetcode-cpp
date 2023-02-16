class Solution {
 public:
  long long maxKelements(vector<int>& nums, int k) {
    priority_queue<int> pq(nums.begin(), nums.end());

    long long ans = 0;
    while (k-- > 0) {
      int num = pq.top();
      pq.pop();

      ans += num;
      pq.push((num + 3 - 1) / 3);
    }

    return ans;
  }
};
// Runtime 276 ms
// Memory 72.2 MB
// 2023.2.16 at 奥盛大厦