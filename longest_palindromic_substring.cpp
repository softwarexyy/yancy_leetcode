class Solution {
public:
    string longestPalindrome(string s) {
        int i,radius,len,maxLen = 0;
        string rslt;
        int strSize = s.size();
        if (strSize == 1){
            return s;
        }
        for (i=0; i<strSize; i++){      // 以s[i]为中点，比较两边是否对称
            // s[i]为中点
            radius = 1;
            len = 1;
            while(i-radius>=0 && i+radius<strSize){
                if (s[i-radius] == s[i+radius]){    //如果是回文子串
                    len += 2;
                    if (len > maxLen){              //如果是当前最长回文子串
                        rslt.assign(s, i-radius, 2*radius+1);
                        maxLen = len;
                    }
                }
                else{
                    break;
                }
                radius ++;                          //增长半径，中心不变，搜索更长的回文子串
            }
            // s[i]是中点前一位
            radius = 1;
            len = 0;
            while(i-radius+1>=0 && i+radius<strSize){
                if (s[i-radius+1] == s[i+radius]){
                    len += 2;
                    if (len > maxLen){
                        rslt.assign(s, i-radius+1, 2*radius);
                        maxLen = len;
                    }
                }
                else{
                    break;
                }
                radius ++;
            }
        }
        return rslt;
    }
};
