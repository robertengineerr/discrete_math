/*
MATH-2165-001
Robert Thomas
Project 1
Feb 26, 2025
Description: This program takes an integer as input from the user and calculates
the number of trailing zeros and the number of digits from the factorial
without calculating the factorial directly.
*/

#include <iostream>
#include <vector>

//for this algorithm we will take an integer value and manually calculate the factorial of the number with no zeros as an array
//we can do this by dividing by ten on each iteration that is divisible by ten
//in this way there will be no trailing zeros
//the factorial is technically done backwards but it doesn't matter since we only need the digits

std::vector<int> multiply(std::vector<int> n, int x) {
    int carry=0;
    for (int i=0; i<n.size(); i++) {
        int product=n[i]*x+carry;
        n[i]=product%10;
        carry=product/10;
    }
    while (carry) {
        n.push_back(carry%10);
        carry/=10;
    }
    return n;
}

std::vector<int> fact_no_zeros(int n) {
    std::vector<int> r = {1};
    for (int i=2; i<=n; i++) {
        int x=i;
        while (x%10==0) x/=10; //keep dividing by ten when divisible
        r = multiply(r, x);
        while (!r.empty() && r[0] == 0) r.erase(r.begin()); //remove trailing zeros
    }
    //uncomment this code to see the result in terminal
    //for(int i=r.size()-1; i>=0; i--) std::cout<<r[i];
    //  std::cout<<std::endl;
    return r;
}

//this will iterate over the array and add all the digits together
int sum_digits(const std::vector<int>& n) {
    int sum=0;
    for (int i=0; i<n.size(); i++)
        sum+=n[i];
    return sum;
}

int main(){
    int n=0;
    std::cin>>n;
    
    //for the count we only need to know how many 5s are in the primes of this number
    //formula=[x/5]+[x/25]+[x/125]+...
    int count=0;
    for(int i=5; n/i>=1; i*=5) count+=n/i;
    
    std::vector<int> f=fact_no_zeros(n);
    int sum=sum_digits(f);
    
    std::cout<<sum<<count;
    
    return 0; 
}