//MATH-2165-001
//Robert Thomas
//Project 1
//Feb 26, 2025

#include <iostream>
#include <cmath>


long long fact(int n, int count){
    if(n>1) return fact(n-1, count)*n; 
    else if(n==0) return 1;
    else if(n<0) return 0;
    return n;
}

int main(){
    int n=0;
    std::cin>>n;
    
    //find the number of trailing zeros first
    //trailing zeros are only made with a 2 and 5 in the prime factorization
    //there are always more fives than two unless the n=2
    //we can divide by five until it's indivisible.
    int count=0;
    for(int i=5; n/i>=1; i*=5) count+=n/i;
    
    std::cout<<count<<std::endl;
    
    //we can use the count to help us calculate the factorial without the trailing zeros
    long long f=fact(n, count);
    
    //from there we can find the sum of the digits by looping through the digits and adding the rightmost place
    int sum=0;
    for(int i=f; i>0; i=floor(i/10)) sum+=i%10;
    
    std::cout<<sum<<std::endl;
    
    return 0;
}