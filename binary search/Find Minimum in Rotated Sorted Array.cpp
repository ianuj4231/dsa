
class Solution {
public:
    int findMin(vector<int> &nums) {
                      int n= nums.size();
                      int left=0, right=n-1;
                      while(left<right){
                          int mid=left+(right-left) /2;
                            if(nums[mid]>nums[right]){
                                    left=mid+1;
                            }
                            else{
                                    right=mid;
                            }
                      }
                      return nums[left];
            }
};



//min is in my unsorted half , am I right...
//so i'll spot the unsorted half.. 
