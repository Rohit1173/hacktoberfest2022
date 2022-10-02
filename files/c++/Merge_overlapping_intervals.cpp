//  Merge Overlapping Intervals
// Problem Link:   https://leetcode.com/problems/merge-intervals/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
    vector<vector<int>> ans;
        
    sort(intervals.begin(), intervals.end());
    
    vector<int> start(2);
    start[0] = intervals[0][0];
    start[1] = intervals[0][1];
    
    for(int i=1;i<intervals.size();i++){
        
        if( start[1] >= intervals[i][0] ){
    
            start[1] = max( intervals[i][1], start[1]) ;
        }
        else{
            ans.push_back(start);
            
            start[0] = intervals[i][0];
            start[1] = intervals[i][1];
            
        }
    }
    ans.push_back(start);
    
    return ans;
}
 
int main(){

    vector<vector<int>> intervals = {{1,3}, {2,4}, {6,8}, {9,10}};

    vector<vector<int>> ans = merge(intervals);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
 
   return 0;
}