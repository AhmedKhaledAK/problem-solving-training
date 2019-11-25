#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'nonDivisibleSubset' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY s
 */
unordered_map<int, int> freq;

int nonDivisibleSubset(int k, vector<int> s) {
    vector<int> rems;
    for(int i=0; i <s.size(); i++){
        rems.push_back(s[i] % k);
        freq[rems[i]]++;
    }

    bool iszerotaken=false, ishalftaken=false;
    int ans=0;

    for(int i =0; i < rems.size(); i++){
        if(rems[i] != 0){
            int m = max(freq[rems[i]], freq[k-rems[i]]);
            cout << "m: " << m << endl;
            if(rems[i]==k-rems[i] && !ishalftaken){
                ishalftaken = true;
                ans++;
            }
            else if(m==freq[rems[i]] && rems[i]!=k-rems[i]){
                ans++;
            }
        } else if(rems[i] == 0 && !iszerotaken){
            iszerotaken = true;
            ans++;
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string s_temp_temp;
    getline(cin, s_temp_temp);

    vector<string> s_temp = split(rtrim(s_temp_temp));

    vector<int> s(n);

    for (int i = 0; i < n; i++) {
        int s_item = stoi(s_temp[i]);

        s[i] = s_item;
    }

    int result = nonDivisibleSubset(k, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

