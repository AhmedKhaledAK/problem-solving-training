class Solution {
public:
    string simplifyPath(string path) {
        stack<string> paths;
        string cur="";
        path += '/';
        for (int i=1; i<path.size(); i++){
            if (path[i]=='/'){
                if (cur==".."){
                    if (!paths.empty()) paths.pop();
                }else if (cur!="."&&cur!=""){
                    paths.push(cur);
                }
                cur = "";
            }else{
                cur += path[i];
            }
        }
        string res = "";
        while (!paths.empty()){
            res = "/" + paths.top() + res;
            paths.pop();
        }
        return (res==""?"/":res);
    }
};
