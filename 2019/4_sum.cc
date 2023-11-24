class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    int n = nums.size();

    for (int i = 0; i < n - 3; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
        break;
      }

      if (nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target) {
        continue;
      }

      for (int j = i + 1; j < n - 2; ++j) {
        if (j > i + 1 && nums[j] == nums[j - 1]) {
          continue;
        }

        if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
          break;
        }

        if (nums[i] + nums[j] + nums[n - 1] + nums[n - 2] < target) {
          continue;
        }

        int head = j + 1;
        int tail = n - 1;

        while (head < tail) {
          int sum = nums[i] + nums[j] + nums[head] + nums[tail];

          if (sum > target) {
            --tail;
          } else if (sum < target) {
            ++head;
          } else {
            vector<int> quadruplet;
            quadruplet.push_back(nums[i]);
            quadruplet.push_back(nums[j]);
            quadruplet.push_back(nums[head]);
            quadruplet.push_back(nums[tail]);

            ans.push_back(quadruplet);

            while (head < tail && nums[head] == quadruplet[2]) {
              ++head;
            }

            while (head < tail && nums[tail] == quadruplet[3]) {
              --tail;
            }
          }
        }
      }
    }

    return ans;
  }
};  // 8ms

class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    if (nums.size() < 4) {
      return {};
    }

    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 3; ++i) {
      int j = nums.size() - 1;

      while ((i + 2) < j) {
        int new_target = target - (nums[i] + nums[j]);
        int head = i + 1;
        int tail = j - 1;

        while (head < tail) {
          int sum = nums[head] + nums[tail];

          if (sum < new_target) {
            ++head;
          } else if (sum > new_target) {
            --tail;
          } else {
            vector<int> quadruplet;
            quadruplet.push_back(nums[i]);
            quadruplet.push_back(nums[head]);
            quadruplet.push_back(nums[tail]);
            quadruplet.push_back(nums[j]);

            ans.push_back(quadruplet);

            while (head < tail && nums[head] == quadruplet[1]) {
              ++head;
            }

            while (head < tail && nums[tail] == quadruplet[2]) {
              --tail;
            }
          }
        }

        --j;
        while ((i + 2) < j && nums[j] == nums[j + 1]) {
          --j;
        }
      }

      while (i < nums.size() - 1 && nums[i + 1] == nums[i]) {
        ++i;
      }
    }

    return ans;
  }
};  // 32ms