//MATH-2165-001
//Robert Thomas
//Project 1
//Feb 26, 2025

#include <iostream>
#include <cmath>




int main(){
    int n=0;
    std::cin>>n;
    
    //find the number of trailing zeros first
    //trailing zeros are only made with a 2 and 5 in the prime factorization
    //we can divide by five until it's indivisible.
    int count=0;
    for(int i=5; n/i>=1; i*=5) count+=n/i;
    
    std::cout<<count;
    
    //we can use the count to help us calculate the factorial without the trailing zeros
    
    
    return 0;
}