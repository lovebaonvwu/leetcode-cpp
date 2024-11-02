class Solution {
public:
    bool isCircularSentence(string sentence) {
        auto index = sentence.find(" ");
        while (index != string::npos) {
            if (sentence[index - 1] != sentence[index + 1]) {
                return false;
            }

            index = sentence.find(" ", index + 1);
        }

        return sentence[0] == sentence.back();
    }
};
// 0 ms
// 8.31 MB

