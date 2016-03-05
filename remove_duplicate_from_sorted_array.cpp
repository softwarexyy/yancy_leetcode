class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return 1;
        
        int i=1, size=nums.size();
        
        while (i!=size && nums[i]!=nums[i-1])  // i points to the first repeated element
            i++;
        if (i == size)              // all elements are different
            return size;
        
        int j=i;
        while (j!=size && nums[j]==nums[i])    // j points to the next different element
            j++;
        if (j == size)
            return i;
        
        while (true){
            int tempj = nums[j];
            swap(nums[i], nums[j]);
            j++;                        // j points to next position
            if (j == size)
                break;
            while (j!=size && nums[j]==tempj)    
                j++;                    // j points to next different element
            if (j == size)
                break;
            i++;
        }
        return i+1;
    }
};

/*******************************    方法：  ******************************************************
    两个指针，一个顺序往下滑(i)，另一个跳过所有重复元素往下走(j)，每一趟循环中，交换这两个元素。
    当j指向末尾时，跳出循环，i指向的元素为最后一个元素（本题注意边界溢出）
****************************************************************************************************/
