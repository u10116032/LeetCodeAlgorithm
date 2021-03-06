/***** Second Visit *****/
/*
    bottom-up
    T:O(n)/S:O(1)
*/
class Solution {
public:
    int titleToNumber(string s)
    {
        int ans=0;
        for (char c:s) {
            ans=ans*26+(c-'A'+1);
        }
        return ans;
    }
};

/***** First Visit *****/
class Solution {
public:
    int titleToNumber(string s)
    {
        /*
            A 1
            ...
            Z 26
            AA 1*26+1
            ZY 26*26+25=701
        */
        int ans=0;
        for (char c:s) {
            ans*=26;
            ans+= c-'A'+1;
        }
        return ans;
    }
};
