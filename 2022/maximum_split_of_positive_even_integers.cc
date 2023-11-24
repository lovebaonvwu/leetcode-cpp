class Solution {
 public:
  vector<long long> maximumEvenSplit(long long finalSum) {
    vector<long long> ans;

    if (finalSum & 1) {
      return ans;
    }

    long long sum = 2;

    while (finalSum > 0) {
      if (finalSum - sum <= sum) {
        ans.push_back(finalSum);
        break;
      } else {
        ans.push_back(sum);

        finalSum -= sum;
        sum += 2;
      }
    }

    return ans;
  }
};
// Runtime: 193 ms, faster than 73.08%
// Memory Usage: 40.6 MB, less than 15.94%