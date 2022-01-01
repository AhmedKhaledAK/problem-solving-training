class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        unordered_set<int> numbers;
        int count = 0;
        for (int digit = 1; digit <= 9; digit++) {
            numbers.insert(digit);
            helper(n, numbers, count);
            numbers.erase(digit);
        }
        return count + 1;
    }
    
    void helper(int& n, unordered_set<int>& numbers, int& count) {
        count++;
        if (numbers.size() == n) {
            return;
        }
        for (int i = 0; i <= 9; i++) {
            if (numbers.find(i) != numbers.end()) {
                continue;
            }
            numbers.insert(i);
            helper(n, numbers, count);
            numbers.erase(i);
        }
    }
};
