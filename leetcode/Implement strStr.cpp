class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.length(), h = haystack.length();
        if (n == 0) {
            return 0;
        }
        int i = 0, j = 0;
        int cnt = 0, first = -1;
        while (i <= h - n + 1) {
            while (j < n && haystack[i] == needle[j]) {
                cnt++;
                if (cnt == 1) {
                    first = i;
                }
                if (cnt == n) {
                    return first;
                }
                i++;
                j++;
            }
            if (haystack[i] != needle[j] && cnt != 0) {
                int k = first+1; 
                cnt--;
                while (k < h && haystack[k] != needle[0]) {
                    cnt--;
                    k++;
                }
                if (k < h) {
                    cnt = 1;
                    first = k;
                    j = 1;
                }
                i = k + 1;
            } else if (haystack[i] != needle[j]) {
                i++;
            }
        }
        return -1;
    }
};
