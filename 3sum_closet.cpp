class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); //排序
        int resSum;         //存放结果
        int minDiff = INT_MAX;        //最小差值
        for(int i=0; i<nums.size()-2; i++){
            int p = i+1;
            int q = nums.size()-1;
            while(p<q){
                int tempSum = nums[i]+nums[p]+nums[q];
                int tempDiff;
                if (tempSum < target){
                    tempDiff = target-tempSum;
                    if (tempDiff < minDiff){
                        minDiff =  tempDiff;
                        resSum = tempSum;
                    }
                    p++;
                }
                else if (tempSum > target){
                    tempDiff = tempSum-target;
                    if (tempDiff < minDiff){
                        minDiff =  tempDiff;
                        resSum = tempSum;
                    }
                    q--;
                }
                else{
                    tempDiff = 0;
                    if (tempDiff < minDiff){
                        minDiff =  tempDiff;
                        resSum = tempSum;
                    }
                    p++;
                }
            }
        }
        return resSum;
    }
};
