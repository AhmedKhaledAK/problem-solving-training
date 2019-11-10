class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        map<string, bool> mp;
        int cnt=0;
        for(int i =0; i < emails.size(); i++){
            string e = emails[i], s="";
            int j =0;
            bool isatfnd=false;
            while(j < e.length() && e[j] != '+'){
                if(e[j] == '@') 
                    isatfnd=true;
                else if(e[j] == '.' && !isatfnd){
                    j++;
                    continue;
                }
                s+=e[j];
                j++;
            }
            if(j==e.length()){
                if(mp[s] != true) cnt++;
                mp[s]=true;
                cout << "s: " << s << endl;
                continue;
            }
            j++;
            while(j < e.length() && e[j] != '@') j++;
            s+=(e.substr(j,e.length()-1));
            if(mp[s] != true) cnt++;
            mp[s]=true;
            cout << "s: " << s << endl;
        }
        return cnt;
    }
};
