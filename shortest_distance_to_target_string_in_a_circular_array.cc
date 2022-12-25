class Solution 
{
public:
    int closetTarget(vector<string>& words, string target, int startIndex) 
    {
        unordered_map<string, vector<int>> mp;
        int n = words.size();
        for (int i = 0; i < n; ++i)
        {
            mp[words[i]].push_back(i);
        }

        if (mp.find(target) == mp.end())
        {
            return -1;
        }

        int ans = INT_MAX / 2;
        for (auto p : mp[target])
        {
            if (p >= startIndex)
            {
                ans = min(ans, (p - startIndex));
                ans = min(ans, (startIndex + n - p) % n);
            }
            else
            {
                ans = min(ans, (startIndex - p));
                ans = min(ans, (p + n - startIndex) % n);
            }
        }

        return ans;
    }
};
// Runtime 53 ms
// Memory 18 MB
// 2022.12.25 at 茗筑美嘉

class Solution 
{
public:
    int closetTarget(vector<string>& words, string target, int startIndex) 
    {
        unordered_map<string, vector<int>> mp;
        int n = words.size();
        for (int i = 0; i < n; ++i)
        {
            mp[words[i]].push_back(i);
        }

        if (mp.find(target) == mp.end())
        {
            return -1;
        }

        int ans = INT_MAX / 2;
        for (auto p : mp[target])
        {
            ans = min({ans, abs(p - startIndex), n - abs(p - startIndex)});
        }

        return ans;
    }
};
// Runtime 49 ms
// Memory 17.7 MB
// 2022.12.25 at 茗筑美嘉