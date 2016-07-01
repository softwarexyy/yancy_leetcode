class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int sum = 0;
        for (int i=0; i<nums.size(); i++){
            if (sum < 0)
                sum = 0;
            sum += nums[i];
            maxSum = maxSum>sum ? maxSum : sum;
        }
        return maxSum;
    }
};








/*******
属于一种DP问题。
已知了前k个元素的最大子序列和为maxSub（已经被记录下来了），以及一个临时和sum，如果添加了第k+1这个元素，
由于是连续子序列这个限制，所以如果k+1这个元素之前的和是小于0的，
那么对于增大k+1这个元素从而去组成最大子序列是没有贡献的，所以可以把sum 置0。

举个例子，-1， -2 ，4， -5， 7这里假定7为第k+1个元素，
那么很明显可以看出，之前的sum = -5 + 4 =-1，那么这样对于7来说只会减少它，
所以直接置sum = 0， 0 + 7才能得到正确的答案。
再拓展这个数组， -1， -2， 4， -5， 7， 1 这里1之前的sum = 7 > 0，对于后面的1来组成最大子序列是有贡献的，
所以sum = 7 + 1 =8。再注意一点，只要sum不减到负数，中间出现小于0的元素是没关系的，sum仍然可以继续累加。
********/
