class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n = nums.size();

        map<int, int> mp;
        mp[0] = n - 1;

        vector<long long> presum(n + 1);
        for (int i = 1; i <= n; ++i) {
            presum[i] = nums[i - 1] + presum [i - 1];
        }

        priority_queue<array<long long, 3>> pq;

        vector<long long> ans;

        for (auto remove : removeQueries) {
            auto it = prev(mp.upper_bound(remove));
            int curStart = it->first;
            int curEnd = it->second;
            int leftSegmentStart = curStart;
            int leftSegmentEnd = remove - 1;
            if (leftSegmentStart > leftSegmentEnd) {
                mp.erase(curStart);
            } else {
                mp[leftSegmentStart] = leftSegmentEnd;

                long long leftSegmentSum = presum[leftSegmentEnd + 1] - presum[leftSegmentStart];
                pq.push({leftSegmentSum, leftSegmentStart, leftSegmentEnd});
            }
            
            int rightSegmentStart = remove + 1;
            int rightSegmentEnd = curEnd;
            if (rightSegmentStart <= rightSegmentEnd) {
                mp[rightSegmentStart] = rightSegmentEnd;

                long long rightSegmentSum = presum[rightSegmentEnd + 1] - presum[rightSegmentStart];
                pq.push({rightSegmentSum, rightSegmentStart, rightSegmentEnd});
            }

            while (!pq.empty()) {
                auto [sum, start, end] = pq.top();
                if (mp.find(start) == mp.end() || mp[start] != end) {
                    pq.pop();
                    continue;
                }

                ans.push_back(sum);
                break;
            }
        }

        ans.push_back(0);

        return ans;
    }
};
// 313 ms
// 147.19 MB

