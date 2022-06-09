class Solution {
 public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1,
                                     vector<int>& nums2,
                                     int k) {
    auto comp = [&](pair<int, int> a, pair<int, int> b) {
      return a.first + a.second < b.first + b.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(
        comp);

    for (int i = 0; i < nums1.size(); ++i) {
      for (int j = 0; j < nums2.size(); ++j) {
        pq.push({nums1[i], nums2[j]});

        if (pq.size() > k) {
          pq.pop();
        }
      }
    }

    vector<vector<int>> ans;
    while (!pq.empty()) {
      auto p = pq.top();
      ans.push_back({p.first, p.second});
      pq.pop();
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1,
                                     vector<int>& nums2,
                                     int k) {
    auto comp = [&](pair<int, int>& a, pair<int, int>& b) {
      return a.first + a.second < b.first + b.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(
        comp);

    for (int i = 0; i < min((int)nums1.size(), k); ++i) {
      for (int j = 0; j < min((int)nums2.size(), k); ++j) {
        if (pq.size() < k) {
          pq.push({nums1[i], nums2[j]});
        } else if (nums1[i] + nums2[j] < pq.top().first + pq.top().second) {
          pq.pop();
          pq.push({nums1[i], nums2[j]});
        }
      }
    }

    vector<vector<int>> ans;
    while (!pq.empty()) {
      auto p = pq.top();
      ans.push_back({p.first, p.second});
      pq.pop();
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
  long long countLessThanOrEqual(int x,
                                 vector<int>& nums1,
                                 vector<int>& nums2) {
    long long cnt = 0;
    for (int i = 0, j = nums2.size() - 1; i < nums1.size(); ++i) {
      while (j < nums2.size() && nums1[i] + nums2[j] > x) {
        --j;
      }

      cnt += j + 1;
    }

    return cnt;
  }

 public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1,
                                     vector<int>& nums2,
                                     int k) {
    int lo = nums1[0] + nums2[0];
    int hi = nums1.back() + nums2.back();

    while (lo < hi) {
      long long md = lo + (hi - lo) / 2;

      if (countLessThanOrEqual(md, nums1, nums2) < k) {
        lo = md + 1;
      } else {
        hi = md;
      }
    }

    int target = lo;

    vector<vector<int>> ans, eq;
    for (int i = 0; i < nums1.size(); ++i) {
      for (int j = 0; j < nums2.size() && nums1[i] + nums2[j] <= target; ++j) {
        if (nums1[i] + nums2[j] < target) {
          ans.push_back({nums1[i], nums2[j]});
        } else {
          eq.push_back({nums1[i], nums2[j]});
        }
      }
    }

    k -= ans.size();

    for (int i = 0; i < k && i < eq.size(); ++i) {
      ans.push_back(eq[i]);
    }

    return ans;
  }
};
// Runtime: 421 ms, faster than 53.09%
// Memory Usage: 114.7 MB, less than 48.64%
// 2022.6.9 at 奥盛大厦