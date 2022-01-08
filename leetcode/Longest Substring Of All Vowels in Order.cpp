class Solution {
public:
    int longestBeautifulSubstring(string word) {
        vector<char> vowels {'a', 'e', 'i', 'o', 'u'};
        int currLen, ans, currVowel;
        currLen = ans = currVowel = 0;
        int n = word.size();
        for (int i = 0; i < n; i++) {
            if (word[i] == 'a') {
                currLen = (currVowel == 1 ? currLen : 0) + 1;
                currVowel = 1;
            } else if (currVowel < 5 && word[i] == vowels[currVowel]) {
                currLen++;
                currVowel++;
            } else if (currVowel > 0 && word[i] == vowels[currVowel - 1]) {
                currLen++;
            } else {
                currLen = currVowel = 0;
            }
            if (currVowel == 5) {
                ans = max(ans, currLen);
            }
        }
        return ans;
    }
};
