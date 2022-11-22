class SparseVector {
  unordered_map<int, int> mp;

 public:
  SparseVector(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
      mp[i] = nums[i];
    }
  }

  // Return the dotProduct of two sparse vectors
  int dotProduct(SparseVector& vec) {
    int ans = 0;
    for (auto& [index, val] : mp) {
      ans += vec.mp[index] * val;
    }

    return ans;
  }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
// Runtime 1388 ms
// Memory 286.3 MB
// 2022.11.22 at 茗筑美嘉