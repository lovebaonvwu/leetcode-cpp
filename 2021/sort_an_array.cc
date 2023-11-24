class Solution {
 public:
  vector<int> sortArray(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = i + 1; j < nums.size(); ++j) {
        if (nums[i] > nums[j]) {
          swap(nums[i], nums[j]);
        }
      }
    }

    return nums;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  vector<int> sortArray(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    return nums;
  }
};
// Runtime: 48 ms, faster than 76.39%
// Memory Usage: 15.8 MB, less than 22.22%

class Solution {
 public:
  vector<int> sortArray(vector<int>& nums) {
    return quick(nums, 0, nums.size() - 1);
  }

  vector<int> quick(vector<int>& nums, int begin, int end) {
    if (begin == end) {
      return {nums[begin]};
    }

    int mid = begin + ((end - begin) >> 1);
    return merge(quick(nums, begin, mid), quick(nums, mid + 1, end));
  }

  vector<int> merge(vector<int> a, vector<int> b) {
    vector<int> res;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
      if (a[i] < b[j]) {
        res.push_back(a[i++]);
      } else {
        res.push_back(b[j++]);
      }
    }

    while (i < a.size()) {
      res.push_back(a[i++]);
    }

    while (j < b.size()) {
      res.push_back(b[j++]);
    }

    return res;
  }
};
// Runtime: 204 ms, faster than 7.99%
// Memory Usage: 113.9 MB, less than 5.55%

class Solution {
 public:
  vector<int> sortArray(vector<int>& nums) {
    quick(nums, 0, nums.size() - 1);
    return nums;
  }

  void quick(vector<int>& nums, int l, int r) {
    if (l >= r) {
      return;
    }

    int i = l;
    for (int j = i; j < r; ++j) {
      if (nums[j] < nums[r]) {
        swap(nums[j], nums[i++]);
      }
    }

    swap(nums[i], nums[r]);

    quick(nums, l, i - 1);
    quick(nums, i + 1, r);
  }
};
// Runtime: 44 ms, faster than 84.90%
// Memory Usage: 15.9 MB, less than 22.22%