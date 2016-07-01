class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> rslt;
        if (matrix.empty())
            return rslt;
            
        int k = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        while (k<m/2 && k<n/2){
            int x = k;
            int y = k;
            for (y=k; y<n-k-1; y++)         rslt.push_back(matrix[x][y]);
            for (x=k; x<m-k-1; x++)         rslt.push_back(matrix[x][y]);
            for (y=n-k-1; y>k; y--)         rslt.push_back(matrix[x][y]);
            for (x=m-k-1; x>k; x--)         rslt.push_back(matrix[x][y]);
            k++;
        }
        
        if (k>=m/2 && m%2!=0)
            for (int y=k; y<n-k; y++)   
                rslt.push_back(matrix[m/2][y]);
                
        else if (k>=n/2 && n%2!=0)
            for (int x=k; x<m-k; x++)   
                rslt.push_back(matrix[x][n/2]);
        
        return rslt;
    }
};








/**** 一圈一圈输出，每一圈按照顺时针方向输出，设一个变量k控制圈号 *****/
