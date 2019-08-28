class Solution {
 public:
  string frequencySort(string s) {
    vector<int> vec(128, 0);

    for (const char& ch : s) {
      vec[ch]++;
    }

    priority_queue<pair<int, char>> pq;

    for (int i = 0; i < vec.size(); ++i) {
      if (vec[i] > 0) {
        pq.push({vec[i], i});
      }
    }

    string ans = "";
    while (!pq.empty()) {
      pair<int, char> p = pq.top();
      pq.pop();

      ans.append(p.first, p.second);
    }

    return ans;
  }
};  // 8ms

class Solution {
 public:
  string frequencySort(string s) {
    vector<int> vec(128, 0);

    for (const char& ch : s) {
      vec[ch]++;
    }

    vector<pair<int, char>> p;

    for (int i = 0; i < vec.size(); ++i) {
      if (vec[i] > 0) {
        p.push_back({vec[i], i});
      }
    }

    sort(p.rbegin(), p.rend());

    string ans = "";
    for (const pair<int, char>& i : p) {
      ans.append(i.first, i.second);
    }

    return ans;
  }
};  // 12ms

class Solution {
 public:
  string frequencySort(string s) {
    unordered_map<char, int> mp;

    for (const char& ch : s) {
      mp[ch]++;
    }

    auto cmp = [](const pair<char, int>& a, const pair<char, int>& b) {
      return a.second < b.second;
    };

    priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(
        mp.begin(), mp.end(), cmp);

    string ans = "";

    while (!pq.empty()) {
      pair<char, int> p = pq.top();
      pq.pop();

      for (int i = 0; i < p.second; ++i) {
        ans += p.first;
      }
    }

    return ans;
  }
};  // 16ms