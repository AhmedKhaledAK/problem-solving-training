class Solution {
public:
    string convertToBase7(int num) {
        if (!num) { return string{ "0" }; }
        int absNum = abs(num);
        deque<char> chars;
        while (absNum > 0) {
            int digit = absNum % 7;
            chars.push_front(static_cast<char>(48 + digit));
            absNum /= 7;
        }
        if (num < 0) {
            chars.push_front('-');
        }
        return string(chars.begin(), chars.end());
    }
};
