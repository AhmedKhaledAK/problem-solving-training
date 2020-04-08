class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> *vsmall = nums1.size() <= nums2.size() ? &nums1 : &nums2;
        vector<int> *vbig = nums1.size() <= nums2.size() ? &nums2 : &nums1;
        
        int sz = vsmall->size(), halflen = (nums1.size() + nums2.size() + 1) / 2, szb = vbig->size();
        int s = 0, e = sz;
        
        while (s <= e) {
            int m = (s+e)/2;
            int j = halflen - m;
            
            if (m < e && vbig->at(j-1) > vsmall->at(m)) {
                s = m + 1;
            } else if (m > s && vsmall->at(m-1) > vbig->at(j)) {
                e = m - 1;
            } else {
                int mxleft = 0;
                if (m == 0) mxleft = vbig->at(j-1); // j can't be zero here
                else if (j == 0) mxleft = vsmall->at(m-1);
                else mxleft = max(vsmall->at(m-1), vbig->at(j-1));
                
                if ((nums1.size() + nums2.size())%2 == 1) return (double)mxleft;
                
                int mnright = 0;
                if (m == sz) mnright = vbig->at(j);
                else if (j == szb) mnright = vsmall->at(m);
                else mnright = min(vsmall->at(m), vbig->at(j));
                return (mxleft + mnright) / 2.0;
            }
        }
        return 0.0;
    }
};
