class Solution
{
public:
    int lengthOfLongestSubstring(string s){
        int locs[256];      //每个字符出现的位置
        memset(locs, -1, sizeof(locs));
        
        int i,idx = -1, maxLen=0;       //idx是子串起始位置
        for(i=0; i<s.size(); i++){
            if (locs[s[i]] > idx){      //s[i]在idx后出现过，idx设为i的下个位置
                idx = locs[s[i]];
            }
            locs[s[i]] = i;             //locs[s[i]]设为s[i]所在位置
            if (i-idx > maxLen){
                maxLen = i-idx;
            }
        }
        return maxLen;
    }
};
