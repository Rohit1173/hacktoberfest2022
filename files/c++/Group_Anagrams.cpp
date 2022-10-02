// Group Anagrmas 
// Problem link: https://leetcode.com/problems/group-anagrams/

#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    
    map<string, vector<string>> ourmap;
    
    
    for(int i=0;i<strs.size();i++){
        string curr = strs[i];
        sort(strs[i].begin(), strs[i].end());
        
        ourmap[strs[i]].push_back(curr);

    }

    for(auto i:ourmap){
        ans.push_back(i.second);
    }
    
    return ans;
}

int main(){

    vector<string> input = {"eat","tea","tan","ate","nat","bat"};

    vector<vector<string>> output =  groupAnagrams(input);

    for(int i=0;i<output.size();i++){
        cout<<"[ ";
        for(int j=0;j<output[i].size();j++){
            cout<<output[i][j]<<" ";
        }
        cout<<" ]";
        cout<<endl;
    }

    return 0;
}