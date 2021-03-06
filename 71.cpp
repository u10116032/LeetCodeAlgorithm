/***** Third Visit *****/
class Solution {
public:
    string simplifyPath(string path)
    {
        vector<string> v;
        int i=0, n=path.length();
        while (i<n) {
            string dir="";
            i++;
            while (i<n&&path[i]!='/') dir+=path[i++];
            if (dir=="."||dir=="") continue;
            else if (dir==".."&&!v.empty()) v.pop_back();
            else if (dir!="..") v.push_back(dir);
        }
        string ans="";
        for (string s:v) ans+=("/"+s);
        return ans==""?"/":ans;
    }
};

/***** Second Visit *****/
/*
    Use a vector to store each folder
    case   /: delimeter
    case   .: ignore
    case  ..: pop_back
    T:O(n)/S:O(n)
*/
class Solution {
public:
    string simplifyPath(string path)
    {
        vector<string> v;
        int i=0, n=path.length();
        while (i<n) {
            string word="";
            while (i<n&&path[i]!='/') word+=path[i++];
            if (word=="..") {
                if (v.size()>0) v.pop_back();
            }
            else if (word!=""&&word!=".") v.push_back(word);
            ++i;
        }
        string ans="/";
        for (auto word:v) ans+=word+'/';
        return ans=="/"?ans:ans.substr(0,ans.length()-1);
    }
};

/***** First Visit *****/
/************* Word tokenizer ***************/
class Solution {
public:
    string simplifyPath(string path)
    {
        /*
        constrain:
        path[0]=='/';
        we can use stack to record each char from left to right.
        case '/' if s.top()=='/' continue else push
        case '.' ignore
        case '..' pop
        case default push
        */
        string res, tmp;
        vector<string> stk;
        stringstream ss(path);
        while(getline(ss,tmp,'/')) {
            if (tmp == "" or tmp == ".") continue;
            if (tmp == ".." and !stk.empty()) stk.pop_back();
            else if (tmp != "..") stk.push_back(tmp);
        }
        for(auto str : stk) res += "/"+str;
        return res.empty() ? "/" : res;
    }
};

/************* Char tokenizer, which is bad for concise ***************/
class Solution {
public:
    string simplifyPath(string path)
    {
        /*
        constrain:
        path[0]=='/';
        we can use stack to record each char from left to right.
        case '/' if s.top()=='/' continue else push
        case '.' ignore
        case '..' pop
        case default push
        */
        stack<char> s;
        s.push(path[0]);
        for (int i=1; i<path.length(); ++i) {
            char income=path[i];
            switch (income) {
                case '/': {
                    if (s.top()=='/'||i==path.length()-1) continue;
                    s.push(income);
                    break;
                }
                case '.': {
                    int j=i+1;
                    while(j<path.length()&&path[j]=='.') j++;
                    if((j-i)==1&&(path[j]=='/'||j==path.length())) continue;
                    else if ((j-i)==2&&s.top()=='/'&&(path[j]=='/'||j==path.length())){
                        if(s.size()==1) continue;
                        s.pop();
                        while(s.top()!='/')s.pop();
                        if(s.size()>1) s.pop();
                    }
                    else {
                        for (int x=0; x<j-i; ++x) s.push('.');
                    }
                    i=j-1;
                    break;
                }
                default: {
                    s.push(income);
                    break;
                }
            }
        }
        string ans="";
        while(!s.empty()) {ans+=s.top(); s.pop();}
        reverse(ans.begin(),ans.end());
        if (ans.length()>1&&ans[ans.length()-1]=='/') ans=ans.substr(0,ans.length()-1);
        return ans;
    }
};
