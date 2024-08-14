class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        priority_queue<int> pq;

        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                pq.push(abs(nums[i] - nums[j]));

                if (pq.size() > k) {
                    pq.pop();
                }
            }
        }

        return pq.top();
    }
};// Time Limit Exceeded

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));

        int n = nums.size();

        int lo = 0;
        int hi = nums.back() - nums[0];

        function<int(int)> countPairsWithMaxDistance = [&](int target) -> int {
            int count = 0;
            for (int i = 0, j = 0; j < n; ++j) {
                while (nums[j] - nums[i] > target) {
                    ++i;
                }

                count += j - i;
            }

            return count;
        };

        while (lo < hi) {
            int md = (lo + hi) / 2;

            if (countPairsWithMaxDistance(md) < k) {
                lo = md + 1;
            } else {
                hi = md;
            }
        }

        return lo;
    }
};
// 7 ms
// 12.78 MB
