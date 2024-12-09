#include<bits/stdc++.h>
using namespace std;

// a a a a a a b b b b b b min(freq[0]-1, freq[i])

int fn (vector<int> v , int  n ){
    vector<int> freq(26, 0 ); // space - constant
    for(char ch : v  ){
      freq[ch-'A']++;  
    }
    sort(freq.begin(), freq.end(), greater<int>()); //descending order
    int rem= (freq[0]-1 ) *  n ;
    for(int i=1;i<freq.size();i++){
        rem=rem- min(freq[i], freq[0]-1   )  ;
    }
    rem=max(0, rem); // if rem is < 0 , then no idleslots will be  needed.
    return   rem + v.size();
}

int main(){
    cout << fn({'X','X','Y','Y', 'X', 'X', 'X', 'X', 'Z', 'Z'}, 2);
}
