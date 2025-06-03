class Solution
{
public:
    int maxCandies(vector<int> &status, vector<int> &candies, vector<vector<int>> &keys, vector<vector<int>> &containedBoxes, vector<int> &initialBoxes)
    {
        int n = status.size();

        unordered_set<int> closedBoxes;
        unordered_set<int> unusedKeys;
        queue<int> openedBoxes;

        for (auto box : initialBoxes)
        {
            if (status[box])
            {
                openedBoxes.push(box);
            }
            else
            {
                closedBoxes.insert(box);
            }
        }

        int ans = 0;

        while (!openedBoxes.empty())
        {
            int cnt = openedBoxes.size();

            while (cnt-- > 0)
            {
                auto openedBox = openedBoxes.front();
                openedBoxes.pop();

                ans += candies[openedBox];
                for (auto key : keys[openedBox])
                {
                    if (closedBoxes.find(key) != closedBoxes.end())
                    {
                        openedBoxes.push(key);
                        closedBoxes.erase(key);
                        status[key] = 1;
                    }
                    else if (!status[key])
                    {
                        unusedKeys.insert(key);
                    }
                }

                for (auto containedBox : containedBoxes[openedBox])
                {
                    if (status[containedBox])
                    {
                        openedBoxes.push(containedBox);
                    }
                    else
                    {
                        if (unusedKeys.find(containedBox) != unusedKeys.end())
                        {
                            unusedKeys.erase(containedBox);
                            openedBoxes.push(containedBox);
                            status[containedBox] = 1;
                        }
                        else
                        {
                            closedBoxes.insert(containedBox);
                        }
                    }
                }
            }
        }

        return ans;
    }
};
// Time: O(n + m) where n is the number of boxes and m is the total number of keys and contained boxes.
// Space: O(n + m) for the sets and queue used in the algorithm.
