class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        vector<long long> ans;
        set<pair<long long, int>, greater<pair<long long, int>>> top, bot;
        unordered_map<int, long long> cnt;

        long long running_sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (cnt.find(nums[i]) != cnt.end()) {
                if (top.find({cnt[nums[i]], nums[i]}) != top.end()) {
                    running_sum -= nums[i] * cnt[nums[i]];
                    top.erase({cnt[nums[i]], nums[i]});
                } else {
                    bot.erase({cnt[nums[i]], nums[i]});
                }
            }

            ++cnt[nums[i]];
            top.insert({cnt[nums[i]], nums[i]});
            running_sum += cnt[nums[i]] * nums[i];

            if (top.size() > x) {
                auto it = prev(end(top));
                running_sum -= it->first * it->second;
                bot.insert({it->first, it->second});
                top.erase(it);
            }

            if (i >= k) {
                int sliding_out = nums[i - k];
                if (top.find({cnt[sliding_out], sliding_out}) != top.end()) {
                    running_sum -= sliding_out * cnt[sliding_out];
                    top.erase({cnt[sliding_out], sliding_out});
                } else {
                    bot.erase({cnt[sliding_out], sliding_out});
                }

                --cnt[sliding_out];

                if (cnt[sliding_out] > 0) {
                    bot.insert({cnt[sliding_out], sliding_out});
                }

                if (top.size() < x) {
                    if (!bot.empty()) {
                        auto it = begin(bot);
                        running_sum += it->first * it->second;
                        top.insert({it->first, it->second});
                        bot.erase(it);
                    }
                }
            }

            if (i >= k - 1) {
                ans.push_back(running_sum);
            }
        }

        return ans;
    }
};
// 878 ms
// 299.43 MB
