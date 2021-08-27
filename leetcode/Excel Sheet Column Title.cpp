class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        while (columnNumber > 0)
        {
            int temp = columnNumber % 26;
            columnNumber /= 26;
            if (temp == 0)
            {
                res += 'Z';
                columnNumber--;
            }
            else
            {
                res += (temp - 1) + 'A';
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
