class Solution {
 public:
  long long minimumCost(vector<int>& nums) {
    sort(begin(nums), end(nums));

    int n = nums.size();
    int median = n & 1 ? nums[n / 2] : ((nums[n / 2] + nums[(n - 1) / 2]) / 2);

    long long nextGreater = nextGreaterOrEqual(median);
    long long nextSmaller = nextSmallerOrEqual(median);

    long long maxsum = 0L;
    long long minsum = 0L;

    for (int i = 0; i < nums.size(); ++i) {
      maxsum += abs(nums[i] - nextGreater);
      minsum += abs(nums[i] - nextSmaller);
    }

    return min(maxsum, minsum);
  }

  long long nextSmallerOrEqual(int m) {
    int t = m;
    vector<int> tmp;
    while (t > 0) {
      tmp.push_back(t % 10);
      t /= 10;
    }

    reverse(tmp.begin(), tmp.end());

    vector<int> tmp2 = tmp;

    int n = tmp.size();
    for (int i = 0, j = n - 1; i <= j;)
      tmp[j--] = tmp[i++];

    long long result = 0L;
    for (int i = 0; i < n; ++i) {
      result = result * 10 + tmp[i];
    }

    if (result <= m)
      return result;

    tmp = tmp2;
    int carry = -1;
    for (int i = (n - 1) / 2; i >= 0; --i) {
      int cur = tmp[i] + carry;
      if (cur >= 0) {
        tmp[i] = cur;
        carry = 0;
      } else {
        tmp[i] = 9;
      }

      tmp[n - 1 - i] = tmp[i];
    }

    if (n > 1 && tmp[0] == 0) {
      for (int i = 1; i < n; ++i) {
        tmp[i] = 9;
      }
    }

    result = 0L;
    for (int i = 0; i < n; ++i) {
      result = result * 10 + tmp[i];
    }

    return result;
  }

  long long nextGreaterOrEqual(int m) {
    int t = m;
    vector<int> tmp;
    while (t > 0) {
      tmp.push_back(t % 10);
      t /= 10;
    }

    reverse(tmp.begin(), tmp.end());

    vector<int> tmp2 = tmp;

    int n = tmp.size();
    for (int i = 0, j = n - 1; i <= j;)
      tmp[j--] = tmp[i++];

    long long result = 0L;
    for (int i = 0; i < n; ++i) {
      result = result * 10 + tmp[i];
    }

    if (result >= m)
      return result;

    tmp = tmp2;
    int carry = 1;
    for (int i = (n - 1) / 2; i >= 0; --i) {
      int cur = tmp[i] + carry;
      if (cur <= 9) {
        tmp[i] = cur;
        carry = 0;
      } else {
        tmp[i] = 0;
      }

      tmp[n - 1 - i] = tmp[i];
    }

    result = 0L;
    for (int i = 0; i < n; ++i) {
      result = result * 10 + tmp[i];
    }

    if (carry)
      result = 1 * pow(10, n) + result;

    return result;
  }
};
// 72ms
// 51.35MB