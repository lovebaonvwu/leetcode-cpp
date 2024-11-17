class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        long long sum = 0;
        int n = nums.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; ++i) {
            sum += nums[i];

            if (sum >= k) {
                ans = min(ans, i + 1);
            }

            while (!pq.empty() && sum - pq.top().first >= k) {
                auto [presum, index] = pq.top();
                pq.pop();

                ans = min(ans, i - index);
            }

            pq.push({sum, i});
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
// 94 ms
// 119.76 MB

