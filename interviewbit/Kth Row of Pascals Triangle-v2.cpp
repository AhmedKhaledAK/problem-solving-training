vector<int> Solution::getRow(int A) {
    vector<int> ans; 
    int el = 1;
    for (int i = 0; i <= A; i++) {
        ans.push_back(el);
        el = el * (A - i) / (i + 1);
    }
    return ans;
}

