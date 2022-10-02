// Duplicate Element in an array
// Problem Link:  https://leetcode.com/problems/find-the-duplicate-number/


// Approach

/*

    -> Traverse the whole array
    -> Multiply each element as an index with -1     (arr[arr[i]]*=-1)
    -> Check if a element is left with 0,
       -> if it is that's mean it is multiply by -1 twice, so this is the repeating element

    -> If not found return -1;

*/

#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &nums){

    for (int i = 0; i < nums.size(); i++){
        int index = abs(nums[i]) - 1;

        nums[index] *= -1;

        if (nums[index] > 0){
            return abs(nums[i]);
        }
    }
    return -1;
}

int main(){

    vector<int> arr = {2,3,1,4,5,3};

    cout<<findDuplicate(arr)<<endl;

    return 0;
}