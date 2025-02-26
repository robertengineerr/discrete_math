#include <iostream>
#include <cmath>

long long fact(int f){
    std::cout<<f<<"     ";
    if(f==1) return f;
    return fact(f-1)*f;
}

int main(){
    for(int i=1; i<15; i++){
        std::cout<<i<<":    ";
        int f=fact(i);
        std::cout<<f<<":    ";
        int sum=0;
        for(int i=f; i>0; i=floor(i/10)) sum+=i%10;
        std::cout<<sum<<std::endl;
    }
    return 0;
}