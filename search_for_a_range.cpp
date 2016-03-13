class Solution {
public:
    int b_search(vector<int>& nums, int start, int end, int target){    //二分搜索
        if (start > end)
            return -1;
        int mid = (start+end)/2 ;
        if (nums[mid] < target)
            b_search(nums, mid+1, end, target);
        else if (nums[mid] > target)
            b_search(nums, start, mid-1, target);
        else
            return mid;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int cur = b_search(nums, 0, nums.size()-1, target);
        if (cur == -1){         //can't find
            res.push_back(-1);
            res.push_back(-1);
        }
        else{                   //can find
            res.push_back(cur);
            res.push_back(cur);
            for (int i=cur; i>=0; i--){
                if (nums[i] == target)
                    res[0] = i;
            }
            for (int i=cur; i<nums.size(); i++){
                if (nums[i] == target)
                    res[1] = i;
            }
        }
        return res;
    }
};




//方法：二分搜索，找到target存在的位置cur之后，前后扩大范围。
