class Solution {
public:
    bool isValidArea(int i, int j, vector<vector<char>>& board){     //验证3*3区域是否valid, 3*3块的左上角第一块设为board[i][j]
        string area_tmp;                //将3*3区域内的字符构造成为一个一维字符串方便比较
        for (int p=0; p<3; p++)
            for (int q=0; q<3; q++)
                area_tmp.push_back(board[i+p][j+q]);
        for (int k=0; k<9; k++)
            for (int m=k+1; m<9; m++)
                if (area_tmp[k]!='.' && area_tmp[k]==area_tmp[m])
                    return false;
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            string row_tmp;
            for (int m=0; m<9; m++)
                row_tmp.push_back(board[i][m]);
            for (int j=0; j<9; j++)
                for (int k=j+1; k<9; k++)
                    if (row_tmp[j]!='.' && row_tmp[j]==row_tmp[k])
                        return false;   //行中有重复数字
        }
        
        for(int i=0; i<9; i++){
            string col_tmp;
            for (int j=0; j<9; j++)
                col_tmp.push_back(board[j][i]);
            for (int j=0; j<9; j++)
                for (int k=j+1; k<9; k++)
                    if (col_tmp[j]!='.' && col_tmp[j]==col_tmp[k])
                        return false;   //列中有重复数字
        }
        
        int i, j;
        for (i=0; i<7; i+=3){
            for (j=0; j<7; j+=3){
                bool res = isValidArea(i, j, board);
                if (res == false)
                    return false;
            }
        }
        
        return true;
    }
};







//方法：1、每一整行共9个元素，没有重复数字；
//      2、每一整列共9个元素，没有重复数字；
//      3、每3*3小区域共9个元素，没有重复数字；
//      4、以上有一个条件不符合，break并返回false。
