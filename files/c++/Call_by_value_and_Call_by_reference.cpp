#include<iostream>
using namespace std;
 
// Example of call by value
void func1(int a ){

    a = a + 10;
}


// Example of call by reference
void func2(int &a){
    
    a = a + 20;
}

int main(){

    int a = 10;

// Call by value does not change original value 
    func1(a);
    cout<<a<<endl;

// Call by reference will change original value 
    func2(a);
    cout<<a<<endl;
 
   return 0;
}