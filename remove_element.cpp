class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0)
            return 0;
        int tail = nums.size()-1;
        while(nums[tail] == val)
            tail--;
        if (tail==-1)
            return 0;
        
        for(int i=0; i<tail; i++){
            if (nums[i] == val){
                swap(nums[i], nums[tail]);
                tail--;
            }
            while (nums[tail] == val)
                tail--;
        }
        return tail+1;
    }
};

/******************************   方法  ***************************************
遍历数组，碰到指定元素，则与末尾tail位置元素交换(需确保tail位置元素不是指定元素)
**********************************************************************************/
