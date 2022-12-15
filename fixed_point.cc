class Solution 
{
public:
    int fixedPoint(vector<int>& arr) 
    {
        int lo = 0, hi = arr.size() - 1;

        while (lo < hi)
        {
            int mid = (lo + hi) / 2;
            if (arr[mid] >= mid)
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return arr[lo] == lo ? lo : -1;
    }
};
// Runtime 24 ms
// Memory 10.5 MB
// 2022.12.15 at 奥盛大厦