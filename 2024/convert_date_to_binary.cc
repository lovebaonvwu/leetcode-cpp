class Solution {
public:
    string convertDateToBinary(string date) {
        function<string(const string&)> convert = [](const string& s) -> string {
            int n = stoi(s);

            string ret = "";
            while (n > 0) {
                ret += (n % 2) + '0';
                n /= 2;
            }

            reverse(begin(ret), end(ret));
            return ret;
        };

        return convert(date.substr(0, 4))
            + "-"
            + convert(date.substr(5, 2))
            + "-"
            + convert(date.substr(8, 2));
    }
};
// 2 ms
// 8.83 MB
