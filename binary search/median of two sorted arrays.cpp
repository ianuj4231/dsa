class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
             if(nums1.size() > nums2.size()){
                  swap(nums1, nums2);
             }        
             int n=nums1.size();
             int m=nums2.size();
             int left=0, right=n;
             while(left<=right){
                  int i=  left+ (right-left ) /2 ;
                  int j=   ((m +  n + 1) / 2 ) - i;
                  int maxleft1=(i==0) ? INT_MIN:nums1[i-1];
                  int minright1=(i==n) ? INT_MAX:nums1[i];
                  int maxleft2=(j==0) ? INT_MIN:nums2[j-1];
                  int minright2=(j==m) ? INT_MAX:nums2[j];
                  if(minright1>=maxleft2 && minright2>=maxleft1 ){
                        if((m+n)&1){
                                return max(maxleft1, maxleft2);
                        }   
                        else {
                            return (max(maxleft1, maxleft2)+ min(minright1, minright2)  )/2.0;
                        }
                  }
                  else if(maxleft1 >  minright2){
                    right=i-1;
                  }
                  else{
                          left=i+1;  
                  }
             }
             return 0.0;
    }
};
