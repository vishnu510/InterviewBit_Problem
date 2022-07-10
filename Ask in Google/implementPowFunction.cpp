#include<bits/stdc++.h>
using namespace std;
int pow(int x, int n, int d){

    if(n==0)
        return 1%d;
    if(n==1)
        return max(abs(x)%d, d-abs(x)%d);
    long long ans = pow(x, n/2, d)%d;
    ans = (ans*ans)%d;
    if(n%2)
        ans = (ans*x)%d;
    return ans%d;

}
int main(){
    
    cout<<pow(2,3,3);

    return 0;
}