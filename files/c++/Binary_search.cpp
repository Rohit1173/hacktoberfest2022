// Input: nums = [-1,0,3,5,9,12], target = 9
// Output: 4
// Explanation: 9 exists in nums and its index is 4

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int low = 0,high = nums.size()-1;

        while(low<=high){
            int mid = low + (high - low)/2;

            if(nums[mid] == target)return mid;
            else if(nums[mid] > target)high = mid-1;
            else low = mid+1;
        }

        return -1;
    }
};

// 2nd method Complete solution with main method
#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int x) {
  while (left <= right) {
    int mid =  (right + left) / 2;

    if (arr[mid] == x) {
      return mid;
    } else if (arr[mid] < x) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return 0;
}

int main() {
  int arr1[10];
  int n;
  int key;

  cout << "Enter 10 elements "<<endl;
  for (int i = 0; i < 10; i++) {
    cin >> arr1[i];
  }
  cout <<"Enter an element to be searched "<< endl;
  cin >> n;

  key= binarySearch(arr1, 0, 9, n);

  if (key == -1) {
    cout << "Not Found" << endl;
  } else {
    cout <<n<<" is found at "<< key<<"th index"<< endl;
  }

  return 0;
}
