class Solution {
 public:
  vector<int> majorityElement(vector<int>& nums) {
    int cnt1 = 0;
    int cnt2 = 0;
    int n1;
    int n2;
    vector<int> ans;

    for (auto& n : nums) {
      if (cnt1 && n == n1) {
        ++cnt1;

        continue;
      }
      if (cnt2 && n == n2) {
        ++cnt2;

        continue;
      }
      if (!cnt1) {
        n1 = n;
        ++cnt1;

        continue;
      }
      if (!cnt2) {
        n2 = n;
        ++cnt2;

        continue;
      }

      --cnt1;
      --cnt2;
    }

    cnt1 = 0;
    cnt2 = 0;
    for (auto& n : nums) {
      if (n == n1) {
        ++cnt1;

        continue;
      }

      if (n == n2) {
        ++cnt2;
      }
    }

    if (cnt1 > nums.size() / 3) {
      ans.push_back(n1);
    }

    if (cnt2 > nums.size() / 3) {
      ans.push_back(n2);
    }

    return ans;
  }
};