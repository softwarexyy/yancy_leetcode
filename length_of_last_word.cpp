class Solution {
public:
    int lengthOfLastWord(string s) {
        int wordlen = 0;
        for (int i=s.length()-1; i>=0; i--)
        {
            if (s[i] != ' ')   //if it's alphbet
                wordlen ++;
            else
            {
                if (wordlen == 0)
                    continue;
                else
                    break;
            }
        }
        return wordlen;
    }
};
