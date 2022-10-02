// Arrange the given number to form the biggest number

// intput = 1, 34, 3, 98, 76, 45, 4
// output = 98764543431

//  --------------------- Approach ------------------------------
/*
    let we have two numbers 1 and 3,
    so possible combination is 13 or 31                 and biggest number is 31
    
    only thing is we have to identify the position of numbers
*/

#include <bits/stdc++.h>
using namespace std;

bool customSort(int a, int b){
    
    string s1 = to_string(a);
    string s2 = to_string(b);
    
    string n1 = s1+s2;
    string n2 = s2+s1;
    
    return n1>n2;
}

int main()
{
    int n = 7;                               //length of arr
    int arr[] = {1, 34, 3, 98, 76, 45, 4};
    
    sort(arr, arr+n, customSort);            //sort function with customSort
    
    for(int i=0;i<n;i++){                   // to print output arr
        cout<<arr[i];
    }
    cout<<endl;

    return 0;
}
