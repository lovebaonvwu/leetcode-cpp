class Solution {
 public:
  long long minimumCost(string source,
                        string target,
                        vector<char>& original,
                        vector<char>& changed,
                        vector<int>& cost) {
    unordered_map<char, vector<int>> g;

    for (int i = 0; i < original.size(); ++i)
      g[original[i]].push_back(i);

    long long ans = 0LL;

    for (int i = 0; i < source.size(); ++i) {
      if (source[i] == target[i])
        continue;

      priority_queue<pair<int, char>, vector<pair<int, char>>,
                     greater<pair<int, char>>>
          pq;
      pq.push({0, source[i]});

      unordered_set<char> visited;
      visited.insert(source[i]);

      long long change_cost = -1LL;
      while (!pq.empty()) {
        auto [cur_cost, cur_node] = pq.top();
        pq.pop();

        if (cur_node == target[i]) {
          change_cost = cur_cost;
          break;
        }

        for (auto neighbor_index : g[cur_node]) {
          if (visited.find(changed[neighbor_index]) == visited.end()) {
            visited.insert(original[neighbor_index]);

            int new_cost = cur_cost + cost[neighbor_index];
            pq.push({new_cost, changed[neighbor_index]});
          }
        }
      }

      if (change_cost < 0) {
        ans = change_cost;
        break;
      }

      ans += change_cost;
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  long long minimumCost(string source,
                        string target,
                        vector<char>& original,
                        vector<char>& changed,
                        vector<int>& cost) {
    unordered_map<char, vector<int>> g;

    for (int i = 0; i < original.size(); ++i)
      g[original[i]].push_back(i);

    long long ans = 0LL;

    vector<vector<long long>> cached(26, vector<long long>(26, -1));

    for (int i = 0; i < source.size(); ++i) {
      if (source[i] == target[i])
        continue;

      if (cached[source[i] - 'a'][target[i] - 'a'] != -1) {
        ans += cached[source[i] - 'a'][target[i] - 'a'];
        continue;
      }

      priority_queue<pair<int, char>, vector<pair<int, char>>,
                     greater<pair<int, char>>>
          pq;
      pq.push({0, source[i]});

      unordered_set<char> visited;
      visited.insert(source[i]);

      long long change_cost = -1LL;
      while (!pq.empty()) {
        auto [cur_cost, cur_node] = pq.top();
        pq.pop();

        if (cur_node == target[i]) {
          change_cost = cur_cost;
          cached[source[i] - 'a'][target[i] - 'a'] = cur_cost;
          break;
        }

        for (auto neighbor_index : g[cur_node]) {
          if (visited.find(changed[neighbor_index]) == visited.end()) {
            visited.insert(original[neighbor_index]);

            int new_cost = cur_cost + cost[neighbor_index];
            pq.push({new_cost, changed[neighbor_index]});
          }
        }
      }

      if (change_cost < 0) {
        ans = change_cost;
        break;
      }

      ans += change_cost;
    }

    return ans;
  }
};
// 2324ms
// 405.35MB

class Solution {
 public:
  long long minimumCost(string source,
                        string target,
                        vector<char>& original,
                        vector<char>& changed,
                        vector<int>& cost) {
    unordered_map<char, vector<int>> g;

    for (int i = 0; i < original.size(); ++i)
      g[original[i]].push_back(i);

    long long ans = 0LL;

    vector<vector<long long>> cached(26, vector<long long>(26, -1));

    for (int i = 0; i < source.size(); ++i) {
      if (source[i] == target[i])
        continue;

      if (cached[source[i] - 'a'][target[i] - 'a'] != -1) {
        ans += cached[source[i] - 'a'][target[i] - 'a'];
        continue;
      }

      priority_queue<pair<int, char>, vector<pair<int, char>>,
                     greater<pair<int, char>>>
          pq;
      pq.push({0, source[i]});

      vector<long long> dist(26, INT_MAX);

      long long change_cost = -1LL;
      while (!pq.empty()) {
        auto [cur_cost, cur_node] = pq.top();
        pq.pop();

        if (cur_node == target[i]) {
          change_cost = cur_cost;
          cached[source[i] - 'a'][target[i] - 'a'] = cur_cost;
          break;
        }

        for (auto neighbor_index : g[cur_node]) {
          int new_cost = cur_cost + cost[neighbor_index];
          if (new_cost <= dist[changed[neighbor_index] - 'a']) {
            dist[changed[neighbor_index] - 'a'] = new_cost;
            pq.push({new_cost, changed[neighbor_index]});
          }
        }
      }

      if (change_cost < 0) {
        ans = change_cost;
        break;
      }

      ans += change_cost;
    }

    return ans;
  }
};
// 608ms
// 177.10MB