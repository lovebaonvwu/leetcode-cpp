class Solution {
 public:
  bool canThreePartsEqualSum(vector<int>& A) {
    if (A.size() < 3) {
      return false;
    }

    int sum = accumulate(A.begin(), A.end(), 0);

    if (sum % 3 != 0) {
      return false;
    }

    sum /= 3;
    int pos = 0;

    return findPart(A, pos, sum) && findPart(A, pos, sum) &&
           findPart(A, pos, sum);
  }

  bool findPart(vector<int>& A, int& pos, int target) {
    int n = A.size();
    int sum = 0;
    while (pos < n) {
      sum += A[pos++];
      if (sum == target) {
        return true;
      }
    }

    return false;
  }
};  // 68ms

class Solution {
 public:
  bool canThreePartsEqualSum(vector<int>& A) {
    if (A.size() < 3) {
      return false;
    }

    int sum = 0;

    for (auto& a : A) {
      sum += a;
    }

    if (sum % 3 != 0) {
      return false;
    }

    int target = sum / 3;
    int part = 0;

    for (int i = 0; i < A.size() - 2; ++i) {
      part += A[i];
      if (part == target) {
        part = 0;
        for (int j = i + 1; j < A.size() - 1; ++j) {
          part += A[j];
          if (part == target) {
            part = 0;
            for (int k = j + 1; k < A.size(); ++k) {
              part += A[k];
            }

            return part == target;
          }
        }
      }
    }

    return false;
  }
};  // 76ms

class Solution {
 public:
  bool canThreePartsEqualSum(vector<int>& A) {
    int sum = 0;
    for (int i = 0; i < A.size() - 2; ++i) {
      sum += A[i];

      if (canTwoPartsWithTarget(A, i + 1, sum)) {
        return true;
      }
    }

    return false;
  }

  bool canTwoPartsWithTarget(vector<int>& A, int begin, int target) {
    int sum = 0;
    for (int i = begin; i < A.size() - 1; ++i) {
      sum += A[i];
      if (sum == target) {
        int remainder = 0;
        for (int j = i + 1; j < A.size(); ++j) {
          remainder += A[j];
        }

        return remainder == target;
      }
    }

    return false;
  }
};  // Time Limit Exceeded