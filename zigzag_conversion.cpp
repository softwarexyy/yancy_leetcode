class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
            
        string rslt;    //存储结果
        int i,j=0;
        int strSize = s.size();
        int indSum = 2*(numRows-1);
        while (j<numRows-1){
            int ind = 2*(numRows-j-1);
            for(i=j; i<strSize; ){
                if (ind == indSum){
                    rslt.push_back(s[i]);
                    i += ind;
                }
                else {
                    rslt.push_back(s[i]);
                    i += ind;
                    if (i>=strSize)
                        break;
                    rslt.push_back(s[i]);
                    i += (indSum-ind);
                }
            } 
            j++;
        }
        for(i=j; i<strSize; i+=indSum){
            rslt.push_back(s[i]);
        }
        return rslt;
    }
};
