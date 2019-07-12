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
};