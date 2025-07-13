class Solution
{
public:
    vector<string> validateCoupons(vector<string> &code, vector<string> &businessLine, vector<bool> &isActive)
    {
        vector<int> valid_idx;

        int n = code.size();

        for (int i = 0; i < n; ++i)
        {
            bool valid = true;
            if (code[i].empty())
            {
                valid = false;
            }
            for (auto ch : code[i])
            {
                if (!((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_'))
                {
                    valid = false;
                    break;
                }
            }

            if (valid &&
                (businessLine[i] == "electronics" ||
                 businessLine[i] == "grocery" ||
                 businessLine[i] == "pharmacy" ||
                 businessLine[i] == "restaurant") &&
                isActive[i])
            {
                valid_idx.push_back(i);
            }
        }

        sort(valid_idx.begin(), valid_idx.end(), [&](auto &a, auto &b)
             {
            if (businessLine[a] == businessLine[b]) {
                return code[a] < code[b];
            } else {
                return businessLine[a] < businessLine[b];
            } });

        vector<string> ans;

        for (auto i : valid_idx)
        {
            ans.push_back(code[i]);
        }

        return ans;
    }
};
// Time: O(n log n)
// Space: O(n)