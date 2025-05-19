class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        function<int(int)> calc = [](int x) -> int
        {
            int sum = 0;

            while (x > 0)
            {
                sum += x % 10;
                x /= 10;
            }

            return sum;
        };

        vector<int> tmp = nums;
        sort(begin(tmp), end(tmp), [calc](auto a, auto b)
             {
            int valA = calc(a);
            int valB = calc(b);

            if (valA == valB) {
                return a < b;
            }

            return valA < valB; });

        int n = nums.size();

        int ans = 0;
        vector<bool> visited(n);

        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i)
        {
            mp[nums[i]] = i;
        }

        for (int i = 0; i < n; ++i)
        {
            if (visited[i] || tmp[i] == nums[i])
            {
                continue;
            }

            int j = i;
            int cnt = 0;
            while (!visited[j])
            {
                visited[j] = true;
                j = mp[tmp[j]];
                ++cnt;
            }

            if (cnt > 1)
            {
                ans += cnt - 1;
            }
        }

        return ans;
    }
};
// Time: O(NlogN)
// Space: O(N)