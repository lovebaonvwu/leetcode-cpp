class Solution {
  vector<string> v;
  string prefix = "http://tinyurl.com/";

 public:
  // Encodes a URL to a shortened URL.
  string encode(string longUrl) {
    v.push_back(longUrl);

    int i = v.size() - 1;

    return prefix + to_string(i);
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) {
    string s = shortUrl.substr(prefix.size(), shortUrl.size());

    return v[stoi(s)];
  }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
// Runtime: 8 ms, faster than 40.92%
// Memory Usage: 6.9 MB, less than 100.00%

class Solution {
  unordered_map<string, int> long2short;
  unordered_map<int, string> short2long;

  string prefix = "http://tinyurl.com/";

  int counter = 0;

 public:
  // Encodes a URL to a shortened URL.
  string encode(string longUrl) {
    if (long2short.find(longUrl) != long2short.end()) {
      return prefix + to_string(long2short[longUrl]);
    }

    long2short[longUrl] = counter;
    short2long[counter] = longUrl;

    return prefix + to_string(counter++);
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) {
    string s = shortUrl.substr(prefix.size(), shortUrl.size());

    return short2long[stoi(s)];
  }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
// Runtime: 8 ms, faster than 40.92%
// Memory Usage: 7.4 MB, less than 100.00%