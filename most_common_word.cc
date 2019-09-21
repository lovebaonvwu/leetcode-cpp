class Solution {
 public:
  string mostCommonWord(string paragraph, vector<string>& banned) {
    unordered_map<string, bool> bm;

    for (const auto& b : banned) {
      bm[b] = true;
    }

    paragraph += ' ';
    string w;

    priority_queue<pair<int, string>> pq;
    unordered_map<string, int> mp;

    for (const auto& ch : paragraph) {
      if (isspace(ch) || ch == '\'' || ch == '!' || ch == '?' || ch == ',' ||
          ch == ';' || ch == '.') {
        if (w.empty()) {
          continue;
        }

        if (bm[w]) {
          w = "";
          continue;
        }

        mp[w]++;
        pq.push({mp[w], w});

        w = "";
        continue;
      }

      w += tolower(ch);
    }

    return pq.empty() ? "" : pq.top().second;
  }
};
// Runtime: 4 ms, faster than 96.57%
// Memory Usage: 9.8 MB, less than 7.69%

class Solution {
 public:
  string mostCommonWord(string paragraph, vector<string>& banned) {
    unordered_set<string> ust(banned.begin(), banned.end());

    for (auto& ch : paragraph) {
      ch = isalpha(ch) ? tolower(ch) : ' ';
    }

    istringstream iss(paragraph);

    string w;

    unordered_map<string, int> mp;
    pair<string, int> p{"", 0};
    while (iss >> w) {
      if (!ust.count(w) && ++mp[w] > p.second) {
        p = {w, mp[w]};
      }
    }

    return p.first;
  }
};
// Runtime: 8 ms, faster than 59.33%
// Memory Usage: 9 MB, less than 92.31%