class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int a{},b{};
        int mx=0;

        unordered_set<int>se;

        while(b<s.size())
        {
            if(se.find(s[b])==se.end())
            {
                se.insert(s[b]);
                b++;
                mx= mx>se.size() ? mx : se.size();
            }else{

                se.erase(s[a]);
                a++;
            }
        }
        return mx;
    }
};