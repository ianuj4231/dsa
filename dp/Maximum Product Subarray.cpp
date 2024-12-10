#include <bits/stdc++.h>
using namespace std;

 int maxProduct(vector<int>& nums) {
      int front=1, back=1, maxx=INT_MIN;
      int n=nums.size();
      for(int i=0;i<n;i++){
         front*=nums[i];
         maxx=max(maxx, front);
         if(front==0)front=1;
         back*=nums[n-i-1];
         maxx=max(maxx, back);
         if(back==0)back=1;
      }
      return maxx;
}
int main(){
  int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int result = maxProduct(nums);
    cout << "The maximum product subarray is: " << result << endl;
    return 0;
}
