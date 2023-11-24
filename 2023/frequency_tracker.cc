class FrequencyTracker {
  unordered_map<int, int> nums;
  unordered_map<int, int> freq;

 public:
  FrequencyTracker() {}

  void add(int number) {
    if (nums.find(number) != nums.end()) {
      int curFreq = nums[number];
      --freq[curFreq];
    }

    ++nums[number];
    ++freq[nums[number]];
  }

  void deleteOne(int number) {
    if (nums.find(number) == nums.end()) {
      return;
    }

    int curFreq = nums[number];
    --freq[curFreq];

    --nums[number];
    if (nums[number] > 0) {
      ++freq[nums[number]];
    } else if (nums[number] == 0) {
      nums.erase(number);
    }
  }

  bool hasFrequency(int frequency) { return freq[frequency] > 0; }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
// Runtime 512 ms
// Memory 200.4 MB