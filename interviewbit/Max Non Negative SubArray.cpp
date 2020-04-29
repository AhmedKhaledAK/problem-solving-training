vector<int> Solution::maxset(vector<int> &A) {
    vector<int> ans;
    int  n = (int) A.size();
    long long maxsum = 0, currsum = 0;
    int first = -1, maxfirst = -1, maxlast = -1;
    for (int i = 0; i < n; i++) {
        if (A[i] >= 0) {
            if (first == -1) {
                first = i;
            }
            currsum += A[i];
            if (currsum >= maxsum) {
                if (currsum == maxsum) {
                    if (i - first + 1 >= maxlast - maxfirst + 1) {
                        maxlast = i;
                        maxfirst = first;
                    }
                } else {
                    maxlast = i;
                    maxfirst = first;
                }
                maxsum = currsum;
            }
        } else {
            currsum = 0;
            first = -1;
        }
    }
    if (maxfirst < 0 && maxlast < 0) {
        return ans;
    }
    for (int i = maxfirst; i <= maxlast; i++) {
        ans.push_back(A[i]);
    }
    return ans;
}

