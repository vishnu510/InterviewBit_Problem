#include<bits/stdc++.h>
using namespace std;

string solve(string str) {
int n=str.size();
   
    if(n==1)
    {
        if(str=="9")
        {
            return "11";
        }
        else
        {
            str[0]++;
            return str;
        }
    }
   
    // if the length of string is odd
   
    // case 1 -> if str[r] < str[l] -> just make str[r]=str[l]
   
    // case 2 str[r]> str[l] , go to mid and start incrementing the mid value by 1
   
    // also take care of '9' , if present there
   
    // if str[l]==str[r] , then l++ , r--; if (l==-1) , then it is like of 9999 -> 10001
   
    if(n%2!=0)
    {
        int mid=(n/2);
       
        int l=mid-1 , r=mid+1;
       
        while(true)
        {
            if(str[l]>str[r])
            {
                str[r]=str[l];
                break;
            }
            else
            if(str[l]<str[r])
            {
                int i=0 ;
               
                int carry=1; // start incrementing the mid value by 1
               
                while((mid-i)>=0 && carry)
                {
                    if(str[mid-i]=='9')
                    {
                        str[mid-i]='0';
                        carry=1;
                    }
                    else{
                        str[mid-i]++;
                        carry=0;
                    }
                    i++;
                }
                // done now we will come outside of while loop
                // make right part as left part for palindrome
                break;
            }
            else{
               
                l--;
                r++;
               
                // that means thet this number is palindrome
               
                //4735374
               
                // increment the mid by 1 , if contains 9 then take care of thet too
               
                // eg : 99999
               
               
                if(l==-1)
                {
                   
                     int i=0 , carry=1;
                     
                    while((mid-i)>=0 && carry)
                    {
                        if(str[mid-i]=='9')
                        {
                            str[mid-i]='0';
                            carry=1;
                        }
                        else{
                            str[mid-i]++;
                            carry=0;
                        }
                        i++;
                    }
                   
                    if(str[0]=='0')
                    {
                        // 00099-> 100001
                        str[0]='1';
                        str+='1'; // insert 1 at the end
                    }
                   
                    break;
                     
                }
               
            }
        }
       
        // complete the string by copying the left part to right part
       
        // makes it palindrome
       
        for(int i=0;i<str.length()/2;i++)
        {
            str[str.length()-i-1]=str[i];
        }
    }
    else{
       
        int mid=n/2;  // n=8 , mid=4
       
        int l=mid-1 , r=mid;
       
        while(true)
        {
            if(str[r]<str[l])
            {
                str[r]=str[l];
                break;
            }
            else
            if(str[r]>str[l])
            {
                int i=1;
                int carry=1;
               
                // mid-1 , i.e (mid-1) left part of mid 176689 , mid-1 = index 2 of value=6
               
                while((mid-i)>=0 && carry)
                {
                    if(str[mid-i]=='9')
                    {
                        str[mid-i]='0';
                        carry=1;
                    }
                    else{
                        str[mid-i]++;
                        carry=0;
                    }
                    i++;
                }
                break;
            }
            else{
                l--;
                r++;
               
                    if(l==-1)
                    {
                        int i=1;
                    int carry=1;
                   
                    // mid-1 , i.e (mid-1) left part of mid 176689 , mid-1 = index 2 of value=6
                   
                        while((mid-i)>=0 && carry)
                        {
                            if(str[mid-i]=='9')
                            {
                                str[mid-i]='0';
                                carry=1;
                            }
                            else{
                                str[mid-i]++;
                                carry=0;
                            }
                            i++;
                        }
                       
                        if(str[0]=='0')
                        {
                            str[0]='1';
                            str[mid]='0';
                            str+='1';
                        }
                       
                        break;
                }
            }
        }
       
        for(int i=0;i<str.length()/2;i++)
        {
            str[str.length()-i-1]=str[i];
        }
       
       
       
    }
   
    return str;
}

int main(){
    
    string A = "23545";
    cout<<solve(A);
}