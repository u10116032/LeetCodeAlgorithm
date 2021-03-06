/***** Fourth Visit *****/
/*
    aacecaaa#aaacecaa
    abcd#dcba
*/
class Solution {
public:
    string shortestPalindrome(string s)
    {
        int n=s.length();
        string rs=s;
        reverse(rs.begin(),rs.end());
        string tgt=s+"#"+rs;
        vector<int> failure(2*n+1,0);
        for (int i=1; i<2*n+1; ++i) {
            int j=failure[i-1];
            while (j!=0&&tgt[j]!=tgt[i]) j=failure[j-1];
            if (j==0) failure[i]=tgt[0]==tgt[i];
            else failure[i]=j+1;
        }
        return rs.substr(0,n-failure.back())+s;
    }
};

/***** Third Visit *****/
/*
    string comparison: KMP
    "adding characters in front of it"
    aacecaaa # aaacecaa
               12234567

    abcd # dcba
           0001
   T:O(n)/S:O(n)
*/
class Solution {
public:
    string shortestPalindrome(string s)
    {
        string invs=s;
        reverse(invs.begin(),invs.end());
        string k=s+"#"+invs;
        int n=k.length();
        vector<int> dp(n,0);
        dp[0]=0;
        for (int i=1; i<n; ++i) {
            int j=dp[i-1];
            while (j!=0&&k[j]!=k[i]) j=dp[j-1];
            if (j!=0) dp[i]=j+1;
            else dp[i]=k[0]==k[i];
        }
        return invs+s.substr(dp.back());
    }
};

/***** Second Visit  *****/
/*
    aacecaaa . aaacecaa
    01000122 0 12234567
    string -> KMP!
*/
class Solution {
public:
    string shortestPalindrome(string s)
    {
        string inv=s;
        reverse(inv.begin(),inv.end());
        string tmp=s+"#"+inv;

        vector<int> failure(tmp.length(),0);
        for (int i=1; i<tmp.length(); ++i) {
            int j=failure[i-1];
            while(j>0&&tmp[j]!=tmp[i]) j=failure[j-1];
            if (tmp[j]==tmp[i]) failure[i]=j+1;
        }
        int l=s.length()-failure.back();
        return inv.substr(0,l)+s;
    }
};

/***** First Visit  *****/
/**************** KMP ****************/
class Solution {
public:
    // T:O(n), S:O(n)
    string shortestPalindrome(string s)
    {
        /*
            KMP
            aabca#acbaa
            01001010012

            acca#acca
            000101234

            aaac#caaa
            012000123
            In TLE approach, we reserved the original string ss and stored it
            as rev. We iterate over i and check for s[0:n-i] == rev[i:].
            Pondering over this statement, this is the process of failure table in KMP.

            refers to the solution: https://leetcode.com/problems/shortest-palindrome/
        */
        int n=s.size();
        string rev(s);
        reverse(rev.begin(),rev.end());
        string new_s=s+"#"+rev;
        int new_size=new_s.size();
        vector<int> table(new_size,0);
        for (int i=1; i<new_size; ++i) {
            int t=table[i-1];
            while(t>0&&new_s[t]!=new_s[i])
                t=table[t-1];
            if (new_s[i]==new_s[t]) t++;
            table[i]=t;
        }
        return rev.substr(0,n-table.back())+s;
    }
};

/**************** TLE O(n^2) start from middle ****************/
class Solution {
public:
    string shortestPalindrome(string s)
    {
        int mid = (s.length()+1)/2-1;
        int max_mid=0, max_length=0;
        bool odd=true;
        for (int i=mid; i>=0; --i) {
            int l=i-1,r=i+1, length=0;
            while(l>=0&&r<s.length()) {
                if (s[l]!=s[r]) break;
                length++; l--; r++;
            }
            if (length>0&&i-length==0) {
                max_length=length; max_mid=i;
                break;
            }

            l=i-1; r=i; length=0;
            while(l>=0&&r<s.length()) {
                if (s[l]!=s[r]) break;
                length++; l--; r++;
            }
            if (length>0&&i-length==0) {
                max_length=length; max_mid=i;
                odd=false;
                break;
            }
        }
        // cout<<max_mid<<","<<max_length<<endl;
        string prefix="";
        int start;
        if (odd) start=max_mid+max_length+1;
        else start=max_mid+max_length;
        for (int i=start; i<s.length(); ++i)
            prefix+=s[i];
        reverse(prefix.begin(),prefix.end());
        return prefix+s;
    }
};

/**************** TLE O(n^2) ****************/
class Solution {
public:
    string shortestPalindrome(string s)
    {
        /*
            find the shortest mid index first. T:O(n^2)
            complete front part. T:O(n)
        */
        int n=s.size();
        string rev(s);
        reverse(rev.begin(),rev.end());
        int j=0;
        for (int i=0; i<n; ++i) {
            if (s.substr(0,n-i)==rev.substr(i))
                return rev.substr(0,i)+s;
        }
        return "";
    }
};
