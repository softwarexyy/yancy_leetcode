class Solution {
public:
    void mypermute(vector<int>& nums, vector<vector<int>>& res, vector<int>& prefix){
        if (nums.empty())
            res.push_back(prefix);
        
        int previous;
        for (int i=0; i<nums.size(); i++){
            if (i!=0 && nums[i]==previous)          //如果选取的头部与上次一样，则略过，避免重复排列
                continue;
               
            vector<int> nums_tmp = nums;            //prevent to modify nums and prefix
            vector<int> prefix_tmp = prefix;
                
            prefix_tmp.push_back(nums[i]);
            nums_tmp.erase(nums_tmp.begin() + i);   //delete the head element
            mypermute(nums_tmp, res, prefix_tmp);
            previous = nums[i];
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> tmpres;
        mypermute(nums, res, tmpres);
        return res;
    }
}



//方法：
//  参考permutation题
