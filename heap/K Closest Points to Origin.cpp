#include<bits/stdc++.h>
using namespace std;

class KthLargest{
        private:
        priority_queue<pair<int, int > > maxheap;
        int k;
        public:
      
         vector<vector<int>> find(vector<vector<int>> points, int k ){
                  vector<vector<int>> all ;
                  for(int i=0;i<points.size();i++){
                    int x=points[i][0];
                    int y=points[i][1];
                    maxheap.push({x*x+ y*y  , i  }  );
                    if(maxheap.size() > k ){
                      maxheap.pop();
                    }
                  }
                  while(! maxheap.empty()){
                        all.push_back(points[maxheap.top().second]);
                        maxheap.pop();
                  }
                  return all;
        }
};

int main(){
    int k = 2;
    KthLargest kthLargest;
     vector<vector<int>>  finalx = kthLargest.find(  {{0,2},{2,0},{2,2}},  k  );
     for(int i=0;i<finalx.size();i++){
       for(int x: finalx[i]){
         cout<< x<<" ";
       }
       cout<<endl;
     }
}
