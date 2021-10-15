class Solution {
private:
    int primaryKey;
    unordered_map<string, string> mp;
    
public:
    
    Solution() {
        primaryKey = 1;
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        // Map to store 62 possible characters
        char chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        
        string shortUrl;
        int n = primaryKey;
        while (n) {
            shortUrl.push_back(chars[n%62]);
            n = n/62;
        }
        reverse(shortUrl.begin(), shortUrl.end());
        mp[shortUrl] = longUrl;
        primaryKey++;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
