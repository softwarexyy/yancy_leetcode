class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ret = 0; 
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0;
        for (const int i : nums) {
            sum += i;
            if (mp.find(sum - k) != mp.end()) {
                ret += mp[sum - k];
            }
            mp[sum]++;
        }
        return ret;
    }
};
