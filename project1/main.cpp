/*MATH-2165-001
Robert Thomas
Project 1
Feb 26, 2025
Description: This program takes an integer as input from the user and calculates
the number of trailing zeros and the number of digits from the factorial
without calculating the factorial directly.
*/

#include <iostream>
#include <cmath>

unsigned long long fact_no_zeros(int n){
    unsigned long long r=1;
    for(n; n>1; n--){
        if(n%10) r*=n;
        else r*=n/10;
    }
    return r;
}

int main(){
    int n=0;
    std::cin>>n;
    
    //find the number of trailing zeros first
    //trailing zeros are only made with a 2 and 5 in the prime factorization since 2*5=10
    //there are always more fives than twos unless n=2
    //thus we can divide by five until it's indivisible
    //we'll count the number of fives along the way to get the power of 10 which is the number of zeros
    int count=0;
    for(int i=5; n/i>=1; i*=5) count+=n/i;
    
    unsigned long long f=fact_no_zeros(n);
    unsigned long long sum=0;
    for(unsigned long long i=f; i>0; i=floor(i/10)) sum+=i%10;
    
    std::cout<<sum<<count;
    
    return 0; 
}