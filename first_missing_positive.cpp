class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>::iterator it = find(nums.begin(), nums.end(), 1);
        if (it==nums.end())     //找不到1
            return 1;
        int val = *it;
        for (it; it!=nums.end(); it++){ //从1开始遍历
            if (*it!=val && *it!=val+1)
                return val+1;
            val = *it;
        }
        return val+1;
    }
};




//方法：
//  1、先排序
//  2、从1开始遍历，记住上次遍历的结果:
//          例如nums[i]是val，当nums[i+1]!=val && nums[i+1]!=val+1，就说明val+1是第一个丢失的正数(return val+1)
//  3、如果找不到1，那么第一个缺失的正数就是1   (return 1;)
