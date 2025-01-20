class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        long long ret1 = 0;
        for (int i = 0; i < arr.size(); ++i) {
            ret1 += abs(arr[i] - brr[i]);
        }

        long long ret2 = 0;
        sort(begin(arr), end(arr));
        sort(begin(brr), end(brr));
        for (int i = 0; i < arr.size(); ++i) {
            ret2 += abs(arr[i] - brr[i]);
        }

        return min(ret1, ret2 + k);
    }
};
// 95 ms
// 189.38 MB
