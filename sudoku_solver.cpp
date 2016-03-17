class Solution {
public:
    bool isValid(vector<vector<char>>& board, int x, int y){   //判定在位置(x,y)处填入的数字val，是否能符合sudoku规则
                            //判断行是否有重复
        for (int i=0; i<9; i++)
            if (i!=y && board[x][i]==board[x][y])
                return false;
        
                            //判断列是否有重复
        for (int i=0; i<9; i++)
            if (i!=x && board[i][y]==board[x][y])
                return false;
        
                            //判断3*3区域是否有重复
        int a = x/3*3;  
        int b = y/3*3;  
        for(int i=0; i<3; i++)  
            for(int j=0; j<3; j++)  
                if(a+i!=x && b+j!=y && board[a+i][b+j]==board[x][y])  
                    return false;  
        return true; 
    }
    
    bool fill(vector<vector<char>>& board, int blank){    //blank剩余空格数 xy标定填充位置 val表示填充值
        if (blank == 0)                         //填充完成
            return true;
        for (int i=0; i<9; i++){
            for (int j=0; j<9; j++){
                if (board[i][j] == '.'){        //找下一个空白格
                    for (int k=1; k<10; k++){   //用数字1-9填充
                        board[i][j] = '0' + k;      //填充
                        if (isValid(board, i, j) && fill(board, blank-1))    //判定新填充元素是否符合sudoku
                            return true;
                        else{
                            board[i][j] = '.';      //恢复空白格
                        }
                    }
                    return false;    //到这一步了就说明board[i][j]填什么都无解了
                }
            }
        }
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        int blank = 0;                  //统计空白格个数
        for(int i=0; i<9; i++){
            for (int j=0; j<9; j++){
                if (board[i][j] == '.')
                    ++ blank;
            }
        }
        fill(board, blank);
    }
};








//方法：暴力求解：
//  1、首先填充(fill递归函数)一个空白的格子，
//  2、如果填充后仍然符合sudoku规则，则选择下一个空白格填充(fill递归)；
//  3、如果某一个格子填充后不符合Sudoku规则，那么就将该格换一个数字填充(fill递归)
//  4、统计所有的空白格是否填充完毕，如完毕退出，没完继续填充
