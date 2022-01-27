class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int half_length = nums.size() / 2;
        unordered_map<int, int> nums_times; // 各数字出现的次数
        for (auto& num : nums) {
            if (++nums_times[num] > half_length) {
                return num;
            } 
        }
        return nums[0];
    }
};
