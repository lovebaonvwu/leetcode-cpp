class Solution {
 public:
  vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> mp;

    for (const string& w : words) {
      mp[w]++;
    }

    auto cmp = [](const pair<string, int> a, const pair<string, int> b) {
      if (b.second > a.second) {
        return true;
      } else if (b.second < a.second) {
        return false;
      } else {
        return a.first > b.first;
      }
    };
    priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)>
        pq(mp.begin(), mp.end(), cmp);

    vector<string> ans;
    while (!pq.empty() && k > 0) {
      ans.push_back(pq.top().first);
      pq.pop();

      --k;
    }

    return ans;
  }
};  // 16ms

class Solution {
 public:
  vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> mp;

    for (const string& w : words) {
      mp[w]++;
    }

    priority_queue<pair<int, string>> pq;

    for (const auto& m : mp) {
      pq.push({-m.second, m.first});
      if (pq.size() > k) {
        pq.pop();
      }
    }

    vector<string> ans(k);
    for (int i = k - 1; i >= 0; --i) {
      ans[i] = pq.top().second;
      pq.pop();
    }

    return ans;
  }
};  // 20ms