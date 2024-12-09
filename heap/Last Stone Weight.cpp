#include<bits/stdc++.h>
using namespace std;

class KthLargest{
   private:priority_queue<int > maxheap;
   public:
   KthLargest(vector<int> v){
      
      for(int x: v){
          maxheap.push(x);
       }
   }
   
   int  find(){
        while(maxheap.size() > 1 ){
         int first  = maxheap.top();
         maxheap.pop();
         int second = maxheap.top();
         maxheap.pop();
         if(first!=second) {maxheap.push(first-second);}  
          }
          return maxheap.top();
   }
};

int main(){
  KthLargest kthLargest({1, 2});
cout<<   kthLargest.find();
}
