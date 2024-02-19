#define ll long long
#define pi pair<ll,ll>

class Solution {
    
public:
   int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        vector<int> freq(n, 0);
        sort(meetings.begin(), meetings.end());


        priority_queue<int, vector<int>, greater<int>> freeRooms;
        priority_queue<pi, vector<pi>, greater<pi>> occupiedRooms;
        for(int i = 0; i < n; i++){
            freeRooms.push(i);
        } 
        int maxi = -1, count = 0;
        for(int i = 0; i < m; i++){
            int diff = meetings[i][1] - meetings[i][0];
            while(!occupiedRooms.empty() && meetings[i][0] >= occupiedRooms.top().first){
                freeRooms.push(occupiedRooms.top().second);
                occupiedRooms.pop();
            }
            if(!freeRooms.empty()){
                occupiedRooms.push({meetings[i][1], freeRooms.top()});
                int room = freeRooms.top();
                freq[freeRooms.top()]++;
                freeRooms.pop();
                if(freq[room] == count)maxi = min(room, maxi);
                if(freq[room] > count){
                    
                    count = freq[room];
                    maxi = room;
                }
            }else{
                int room = occupiedRooms.top().second;
                ll time = occupiedRooms.top().first;
                ll newTime = time + diff;
                if(meetings[i][0] > time)newTime = meetings[i][1];
                occupiedRooms.pop();
                occupiedRooms.push({newTime, room});
                freq[room]++;
                cout<<room<<" "<< freq[room]<<" ";
                if(freq[room] == count)maxi = min(room, maxi);
                if(freq[room] > count){
                    
                    count = freq[room];
                    maxi = room;
                }
            }
            

        }
        return maxi;
    }
};