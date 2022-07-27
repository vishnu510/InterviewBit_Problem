#include<bits/stdc++.h>
using namespace std;

vector<int> val = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
vector<string> rom = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

string intToRom(int A){

    string ans ="";

    for(int i=0;i<val.size();i++){

        while(A>=val[i]) ans+=rom[i],A-=val[i];
    }
    return ans;
}

int main(){
    
    cout<<intToRom(452);
    return 0;
}