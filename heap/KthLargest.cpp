#include<bits/stdc++.h>
using namespace std;

class KthLargest{
   private:priority_queue<int, vector<int> , greater<int> > minheap; int k;
   public:
   KthLargest(int k  , vector<int> v){
      this->k=k;
      for(int x: v){
            add(x);
      }
   }
   
   int  add(int x){
        minheap.push(x);
        if(minheap.size() > k){
          minheap.pop();
        }
        return  minheap.top();
   }
};

int main(){
  KthLargest kthLargest(3, {1, 2, 3, 3});
cout<< kthLargest.add(3);   // return 3
cout<<endl;
cout<< kthLargest.add(5);   // return 3
kthLargest.add(6);   // return 3
kthLargest.add(7);   // return 5
kthLargest.add(8);   // return 6
}
