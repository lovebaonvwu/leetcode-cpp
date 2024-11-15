class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int ans = n - 1;
        int j = n - 1;
        while (j > 0 && arr[j] >= arr[j - 1]) {
            --j;
        }

        ans = min(ans, j);

        if (ans == 0) {
            return ans;
        }

        for (int i = 0; i < n; ++i) {
            if (i > 0 && arr[i] < arr[i - 1]) {
                break;
            }
            while (j < n && arr[j] < arr[i]) {
                ++j;
            }

            ans = min(ans, j - i - 1);
        }

        return ans;
    }
};
// 0 ms
// 69.52 MB
