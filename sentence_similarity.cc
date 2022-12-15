class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) 
    {
        if (sentence1.size() != sentence2.size())
        {
            return false;
        }

        unordered_map<string, unordered_set<string>> mp;
        for (auto& p : similarPairs)
        {
            mp[p[0]].insert(p[1]);
        }

        for (int i = 0; i < sentence1.size(); ++i)
        {
            if (sentence1[i] != sentence2[i] && !mp[sentence1[i]].count(sentence2[i]) && !mp[sentence2[i]].count(sentence1[i]))
            {
                return false;
            }
        }

        return true;
    }
};
// Runtime 7 ms
// Memory 11.2 MB
// 2022.12.15 at 奥盛大厦