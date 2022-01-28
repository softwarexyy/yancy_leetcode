class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max = 0;
        unordered_set<int> exists;  // nums中存在的数字set
        for (auto& num : nums) {
            exists.insert(num);
        }
        for (auto& num : nums) {
            // 如果已经存在num-1，那么num一定也被搜过，因此可跳过
            if (exists.find(num - 1) == exists.end()) { 
                // 如果num-1不存在，则在set中寻找num+1、num+2....
                int cnt = 0;
                while (exists.find(num) != exists.end()) {
                    cnt++;
                    num++;
                }
                max = cnt > max ? cnt : max;
            }
        }
        return max;     
    }
};
