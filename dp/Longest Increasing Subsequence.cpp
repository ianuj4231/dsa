#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int > nums={2, 16, 18, 9, 10, 11, 12 };
    vector<int> arr;
    for(int i=0;i<nums.size();i++){
           auto it=lower_bound(arr.begin(), arr.end(), nums[i]);
           if(it==arr.end()){
              arr.push_back(nums[i]);
           }
           else{
              *it=nums[i];
           }
    }
    cout <<  arr.size();
}
