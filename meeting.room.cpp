#include<iostream>
#include<vector>
#include<queue> 
#include<algorithm>

using namespace std; 

class Solution{
public: 

      int minMeetingRooms(vector<vector<int>>& intervals){
        sort(intervals.begin(), intervals.end()); 
        priority_queue<int, vector<int>, greater<>> pq; 
        pq.push(intervals[0][1]); 
        for(int i=1; i< intervals.size(); ++i){
          if(pq.top()<=intervals[i][0]) pq.pop(); 
          pq.push(intervals[i][1]); 
        }
        return pq.size(); 
      }
};
int main(){
  vector<vector<int>> intervals = {{0,30}, {5,10},{15,20}};
  Solution sol; 
  cout << sol.minMeetingRooms(intervals) << endl; 
  return 0; 
}
