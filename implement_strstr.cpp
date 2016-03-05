class Solution {
public:
    int strStr(string haystack, string needle) {
        int p=0, q=0;
        int sizeh = haystack.size();
        int sizen = needle.size();
        while (sizeh-p >= sizen){       // haystack is longer than needle
            int pp = p;                 // haystack's cursor
            while (q!=sizen && needle[q]==haystack[pp]){
                pp++;   
                q++;                    // needle's cursor
            }
            if (q == sizen){            // needle is the substring of haystack
                return p;
            }
            else {
                p++;                    // haystack's cursor + 1    
                q = 0;                  // needle's cursor clear to 0
            }
        }
        return -1;
    }
};
