class Solution {
public:
    void rotate_single(vector<vector<int>>& nums, int i){   //旋转数组第i层
        int n = nums.size();
        for (int k=0; k<n-2*i-1; k++){
            int tmp = nums[n-i-1-k][i];
            nums[n-i-1-k][i] = nums[n-i-1][n-i-1-k];
            nums[n-i-1][n-i-1-k] = nums[i+k][n-i-1];
            nums[i+k][n-i-1] = nums[i][i+k];
            nums[i][i+k] = tmp;
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        for (int i=0; i<matrix.size()/2; i++){
            rotate_single(matrix, i);
        }
    }
};






//方法：
//  由数组外层到数组内层，一层一层旋转
//  重点：1、数组层次的选取for(int i=0; i<n/2; i++)，其中i是第i层，也是该层所在的行数和列数
//        2、每层元素的旋转，需要用到辅助空间
