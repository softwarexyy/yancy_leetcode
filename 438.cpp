class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) {
            return {};
        }
        vector<int> ret;
        
        // 字符串p中各字符出现次数
        int pletters[26] = {};
        for (int i = 0; i < p.size(); i++) {
            pletters[p[i]-'a']++;
        }
        int length = p.size();

        // 滑动窗口
        int tmps[26] = {};  // 每个窗口各字符出现次数
        int i = 0, j = 0, k = 0;
        for (int i = 0, j = length - 1; j < s.size(); i++, j++) {
            for (int k = i; k <= j; k++) {
                tmps[s[k]-'a']++;
            }
            // 比较各字符出现次数是否相同
            bool flag = true;
            for (char ch = 'a'; ch < 'z' + 1; ch++) {
                if (tmps[ch-'a'] != pletters[ch-'a']) {
                    flag = false;
                }
            }
            // 如果次数相同，记录i
            if (flag == true) {
                ret.push_back(i);
            }
            // 清空tmps
            for (auto& elem : tmps) {
                elem = 0;
            }
        }
        return ret;
    }
};
