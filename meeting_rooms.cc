class Solution 
{
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end());

        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i][0] < intervals[i - 1][1])
            {
                return false;
            }
        }

        return true;
    }
};
// Runtime 26 ms
// Memory 11.8 MB
// 2022.12.15 at 奥盛大厦