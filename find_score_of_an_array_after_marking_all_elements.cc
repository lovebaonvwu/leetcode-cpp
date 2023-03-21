class Solution {
 public:
  long long findScore(vector<int>& nums) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    unordered_set<int> visited;

    for (int i = 0; i < nums.size(); ++i) {
      pq.push({nums[i], i});
    }

    long long ans = 0;
    while (!pq.empty()) {
      auto [value, index] = pq.top();
      pq.pop();

      if (visited.find(index) == visited.end()) {
        ans += value;
        visited.insert({index - 1, index, index + 1});
      }
    }

    return ans;
  }
};
// Runtime 561 ms
// Memory 145 MB