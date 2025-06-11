class Solution
{
public:
    int maxDifference(string s, int k)
    {
        int n = s.size();

        auto getStatus = [](int cnt_a, int cnt_b) -> int
        {
            return ((cnt_a & 1) << 1) | (cnt_b & 1);
        };

        int ans = INT_MIN;

        for (char a = '0'; a <= '4'; ++a)
        {
            for (char b = '0'; b <= '4'; ++b)
            {
                if (a == b)
                {
                    continue;
                }

                int cnt_a = 0;
                int cnt_b = 0;
                int prev_a = 0;
                int prev_b = 0;

                int left = -1;

                int best[4] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};

                for (int right = 0; right < n; ++right)
                {
                    cnt_a += (s[right] == a);
                    cnt_b += (s[right] == b);

                    while (right - left >= k && cnt_b - prev_b >= 2)
                    {
                        int left_status = getStatus(prev_a, prev_b);

                        best[left_status] = min(best[left_status], prev_a - prev_b);

                        ++left;

                        prev_a += (s[left] == a);
                        prev_b += (s[left] == b);
                    }

                    int right_status = getStatus(cnt_a, cnt_b);

                    if (best[right_status ^ 0b10] != INT_MAX)
                    {
                        ans = max(ans, cnt_a - cnt_b - best[right_status ^ 0b10]);
                    }
                }
            }
        }

        return ans;
    }
};
// Time: O(n * 25)
// Space: O(1)