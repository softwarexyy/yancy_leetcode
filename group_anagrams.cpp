class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string, vector<string>> maptmp;
        for (int i=0; i<strs.size(); i++){
            string tmp(strs[i]);
            sort(tmp.begin(), tmp.end());
            maptmp[tmp].push_back(strs[i]);
        }
        
        map<string, vector<string>>::iterator it;
        for (it=maptmp.begin(); it!=maptmp.end(); it++){
            sort(it->second.begin(), it->second.end());
            res.push_back(it->second);
        }
        return res;
    }
};



//method:可以先对字符串排序，然后存储到hashmap里面，然后跟剩余的字符（先排序）比对，相等的话则把原串存入到到map中
