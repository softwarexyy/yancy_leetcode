class Solution {
public:
    void mypermute(vector<int> nums, vector<vector<int>>& res, vector<int> tmpres){    //tmpres是上一次遗留的头部,res是最终结果
        if (nums.empty())
            res.push_back(tmpres);

        for (int i=0; i<nums.size(); i++){
            vector<int> tmpres_tmp = tmpres;    //为了防止几次循环改变tmpres和nums(在选取不同的头部元素时，tmpres和nums是不允许被改变的)
            vector<int> nums_tmp = nums;
            
            tmpres_tmp.push_back(nums[i]);
            nums_tmp.erase(nums_tmp.begin() + i);   //delete the element to go on next recursion
            mypermute(nums_tmp, res, tmpres_tmp);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> tmpres;
        mypermute(nums, res, tmpres);
        return res;
    }
};







//方法：
//  先固定一个数，再对剩余的数进行排列，这样就形成了递归结构
//  permutation(int n){
//      1、选取一个数作为头部；tmp.push_back(选中的数)
//      2、踢掉第1步中的数，再进行tmp.insert(tmp.begin(), permutation(n-1));
//  }
//  每次递归都改变最终结果res,这样等到递归结束时就得到正确的res
