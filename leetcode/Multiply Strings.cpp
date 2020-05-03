class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.length(), len2 = num2.length();
        vector<int> res(len1 + len2, 0); 
        int shift = 0, pos = 0, carry = 0;
        for (int i = len1 - 1; i >= 0; i--) {
            int n1 = num1[i] - '0';
            pos = 0;
            carry = 0;
            for (int j = len2 - 1; j >= 0; j--) {
                int n2 = num2[j] - '0';
                int ans = n1 * n2 + res[shift + pos] + carry;
                carry = ans / 10;
                res[shift + pos] = ans % 10;
                pos++;
            }
            if (carry > 0) {
                res[shift + pos] += carry;
            }
            shift++;
        }
        int i = (int) res.size() - 1;
        while (i >= 0 &&  res[i] == 0) {
            i--;
        }
        if (i == -1) {
            return "0";
        }
        string num3 = "";
        while (i >= 0) {
            num3 += to_string(res[i]);
            i--;
        }
        return num3;
    }
};
