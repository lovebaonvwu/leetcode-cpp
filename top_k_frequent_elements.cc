class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    vector<int> ans;
    priority_queue<pair<int, int>> q;

    for (auto& n : nums) {
      mp[n]++;
    }

    for (auto it = mp.begin(); it != mp.end(); ++it) {
      q.push(make_pair(it->second, it->first));
      if (q.size() > mp.size() - k) {
        ans.push_back(q.top().second);
        q.pop();
      }
    }

    return ans;
  }
};  // 20ms

class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    vector<int> ans;
    priority_queue<pair<int, int>> q;

    for (auto& n : nums) {
      mp[n]++;
    }

    for (auto& p : mp) {
      q.push(make_pair(p.second, p.first));
      if (q.size() > mp.size() - k) {
        ans.push_back(q.top().second);
        q.pop();
      }
    }

    return ans;
  }
};  // 24ms

class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    s unordered_map<int, int> mp;
    vector<int> ans;
    priority_queue<pair<int, int>> q;

    for (auto& n : nums) {
      if (!mp[n]) {
        mp[n] = 1;
      } else {
        mp[n]++;
      }
    }

    for (auto& p : mp) {
      q.push(make_pair(p.second, p.first));
    }

    for (int i = 0; i < k; ++i) {
      ans.push_back(q.top().second);
      q.pop();
    }

    return ans;
  }
};  // 28m

class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    vector<int> ans;
    priority_queue<pair<int, int>> q;

    for (auto& n : nums) {
      if (!mp[n]) {
        mp[n] = 1;
      } else {
        mp[n]++;
      }
    }

    for (auto& p : mp) {
      q.push(make_pair(p.second, p.first));
      if (q.size() > mp.size() - k) {
        ans.push_back(q.top().second);
        q.pop();
      }
    }

    return ans;
  }
};  // 32ms

class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    vector<int> ans;

    for (auto& n : nums) {
      if (!mp[n]) {
        mp[n] = 1;
      } else {
        mp[n]++;
      }
    }

    auto cmp = [&mp](int a, int b) { return mp[b] - mp[a] > 0; };
    priority_queue<int, vector<int>, decltype(cmp)> q(cmp);

    for (auto& p : mp) {
      q.push(p.first);
    }

    for (int i = 0; i < k; ++i) {
      ans.push_back(q.top());
      q.pop();
    }

    return ans;
  }
};  // 32ms