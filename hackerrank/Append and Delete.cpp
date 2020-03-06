string appendAndDelete(string s, string t, int k) {

    int sn = s.size(), tn = t.size(), i= 0, ans=0;
    
    while (i < sn && i < tn) {
        if(s[i] != t[i]) break;
        i++;
    }

    if (k % 2 == (sn + tn) % 2)
        ans = sn + tn - 2 * i;
    else
        ans = sn + tn + 1;

    return ans <= k ? "Yes" : "No";
}
