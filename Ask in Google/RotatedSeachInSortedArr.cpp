#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& A, int B){

    int low =0,high =A.size()-1;

    while (low<=high)
    {
        int mid = (low+high)/2;
        if(A[mid]==B){
            return mid;
        }
        if(A[mid]>=B){
            if(B>=A[low] && B<A[mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        else{

            if(B>A[mid] && B<=A[high]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }
    return -1;
}

int main(){


    vector<int> A= {4, 5, 6, 7, 0, 1, 2, 3};
    cout<<search(A,4);
    return 0;
}