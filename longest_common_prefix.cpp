class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()){  //空
            return "";
        }
        int i=0;
        string rslt;
        while (true){
            char prefixTmp = (*(strs.begin()))[i];
            vector<string>::iterator it;
            for (it=strs.begin(); it!=strs.end(); it++){    //比较每个字符串的第i位是否一样
                if ((*it).size() == i)        // 某个字符串长度超出
                    return rslt;
                if ((*it)[i] != prefixTmp)
                    return rslt;
            }
            rslt.push_back(prefixTmp);
            i++;
        }
        return rslt;
    }
};
