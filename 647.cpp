class Solution {
public:
    int countSubstrings(string s) {
        int ret = 0;
        // 回文长度为偶数
        for (int i = 0; i < s.size() - 1; i++) {
            int left = i, right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
                ret++;
            }
        }
        // 回文长度为奇数
        for (int i = 0; i < s.size(); i++) {
            int left = i, right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
                ret++;
            }
        }
        return ret;
    }
};
