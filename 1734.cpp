/*
    [a,b,c]
      3,1
    n=3
    abc=1^2^3=0

    abc ab bc abc
       c  b a

    a b c d e n=odd
    [6,5,4,6]

    a b c d e f n=even
    ab bc cd de ef
*/
class Solution {
public:
    vector<int> decode(vector<int>& encoded)
    {
        int n=encoded.size(), a=0;
        for (int i=1; i<=n+1; ++i) {
            a^=i;
            if (i%2==0)
                a^=encoded[i-1];
        }
        vector<int> ans;
        ans.push_back(a);
        for (int num:encoded)
            ans.push_back(ans.back()^num);
        return ans;
    }
};
