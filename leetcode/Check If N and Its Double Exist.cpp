class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> numbers;
        for (int num : arr)
        {
            int multi = num * 2;
            int div = num / 2;
            if (numbers.find(multi) != numbers.end() 
                || (numbers.find(div) != numbers.end() && (div) * 2 == num)) {
                return true;
            }
            numbers.insert(num);
        }
        return false;
    }
};
