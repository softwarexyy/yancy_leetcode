class Solution {
public:
    int b_search(vector<int>& nums, int begin, int end, int target){
        if (begin > end)
            return begin;                   //can't find then return the insert position
        int mid = (begin+end)/2;
        if (nums[mid] > target)
            b_search(nums, begin, mid-1, target);
        else if (nums[mid] < target)
            b_search(nums, mid+1, end, target);
        else
            return mid;
    }
    int searchInsert(vector<int>& nums, int target) {
        int res;
        int insertPos = b_search(nums, 0, nums.size()-1, target);
        if (nums[insertPos] == target){     // have find
            for(int i=insertPos; i>=0; i--){
                if (nums[i] == target)
                    res = i;
            }
        }
        else{                               //  haven't find
            res = insertPos;
        }
        return res;
    }
};




//方法：二分搜索
