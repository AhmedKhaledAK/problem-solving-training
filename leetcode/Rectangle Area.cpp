class Solution {
public:
    int computeArea(int a, int b, int c, int d, int e, int f, int g, int h) {
        
        long long A = a;
        long long B = b;
        long long C = c;
        long long D = d;
        long long E = e;
        long long F = f;
        long long G = g;
        long long H = h;
        
        
        if (C < E || G < A) {
            return (G - E) * (H - F) + (C - A) * (D - B);
        }
        if(D < F || H < B){
            return (G - E) * (H - F) + (C - A) * (D - B);
        }
        
        long long right = min(C,G);
        long long left = max(A,E);
        long long top = min(H,D);
        long long bottom = max(F,B);
        
        return (G - E) * (H - F) + (C - A) * (D - B) - (right - left) * (top - bottom);
    }
};
