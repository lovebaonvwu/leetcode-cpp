class Solution 
{
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) 
    {
        vector<vector<int>> ans;

        for (auto& w : words)
        {
            int pos = -1;
            while ((pos = text.find(w, pos + 1)) != string::npos)
            {
                ans.push_back({pos, pos + (int)w.size() - 1});
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};
// Runtime 8 ms
// Memory 8.4 MB
// 2022.12.15 at 茗筑美嘉