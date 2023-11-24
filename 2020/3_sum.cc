class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i) {
      int target = -nums[i];

      int front = i + 1;
      int back = nums.size() - 1;

      while (front < back) {
        int sum = nums[front] + nums[back];

        if (sum < target) {
          ++front;
        } else if (sum > target) {
          --back;
        } else {
          vector<int> triplet(3);
          triplet[0] = nums[i];
          triplet[1] = nums[front];
          triplet[2] = nums[back];

          ans.push_back(triplet);

          while (front < back && nums[front] == triplet[1]) {
            ++front;
          }

          while (front < back && nums[back] == triplet[2]) {
            --back;
          }
        }
      }

      while (i + 1 < nums.size() && nums[i + 1] == nums[i]) {
        ++i;
      }
    }

    return ans;
  }
};  // 104ms

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;

    unordered_map<int, int> mp;

    for (auto n : nums) {
      ++mp[n];
    }

    sort(nums.begin(), nums.end());

    int n = nums.size();

    int* previ = nullptr;
    for (int i = 0; i < n; ++i) {
      if (previ && *previ == nums[i]) {
        continue;
      }

      previ = &nums[i];

      --mp[nums[i]];

      int* prevj = nullptr;
      for (int j = i + 1; j < n; ++j) {
        if (prevj && *prevj == nums[j]) {
          continue;
        }

        prevj = &nums[j];

        --mp[nums[j]];

        if (mp[-(nums[i] + nums[j])] > 0 && -(nums[i] + nums[j]) >= nums[j]) {
          ans.push_back({nums[i], nums[j], -(nums[i] + nums[j])});
        }

        ++mp[nums[j]];
      }
      ++mp[nums[i]];
    }

    return ans;
  }
};
// Runtime: 2488 ms, faster than 6.23%
// Memory Usage: 46.6 MB, less than 15.75%