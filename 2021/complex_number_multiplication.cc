class Solution {
 public:
  string complexNumberMultiply(string a, string b) {
    size_t pos = a.find('+');

    string r = a.substr(0, pos);
    string i = a.substr(pos + 1, a.size() - 1 - (pos + 1));

    int ar = std::stoi(r);
    int ai = std::stoi(i);

    pos = b.find('+');

    r = b.substr(0, pos);
    i = b.substr(pos + 1, b.size() - 1 - (pos + 1));

    int br = std::stoi(r);
    int bi = std::stoi(i);

    int cr = ar * br + (-1) * ai * bi;
    int ci = ar * bi + ai * br;

    string ans = std::to_string(cr) + '+' + std::to_string(ci) + 'i';

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 5.9 MB, less than 84.57%

class Solution {
 public:
  string complexNumberMultiply(string a, string b) {
    int ar, ai, br, bi;
    char c;

    stringstream ssa(a), ssb(b), ans;

    ssa >> ar >> c >> ai >> c;
    ssb >> br >> c >> bi >> c;

    ans << ar * br - ai * bi << "+" << ar * bi + ai * br << "i";

    return ans.str();
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 5.9 MB, less than 59.05%