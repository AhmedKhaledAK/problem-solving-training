/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:

    char buf4[4];
    int idx=0;
    int left=0;
    
    int read(char *buf, int n) {
        
        int i=0;
        int ans=0;
        
        if(!left) {
            left = read4(buf4);
            idx=0;
        }
        while(ans < n && left) {
            buf[i++]=buf4[idx++];
            ans++;
            left--;
            
            if(!left)
            {
                left = read4(buf4);
                idx=0;
            }
        }
        return ans;
    }
};
