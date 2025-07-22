// class Solution {
// public:

//     static bool comparator(const vector<int>& a, const vector<int>& b){
//         return a[0] < b[0];
//     }

//     int mostBooked(int n, vector<vector<int>>& meetings) {
//         priority_queue<long long, vector<long long>, greater<>> pq;
//         unordered_map<long long,vector<long long>> et_rooms;
//         vector<long long> meets_held(n, 0);
//         // queue<pair<long long, long long>> et_st;
//         // priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> end_time;
//         queue<pair<long long, long long>> end_time;
//         long long m = meetings.size();

//         sort(meetings.begin(), meetings.end(), comparator);

//         for(long long i = 0; i < n; i++) pq.push(i);
//         long long timer = 0;

//         long long j = 0;
//         while(j < m || !end_time.empty() || !et_rooms.empty()){
//             // if(timer >= meetings[m-1][0] && end_time.empty()) break;

//             if(j < meetings.size() && meetings[j][0] == timer){
//                 // et_st.push({meetings[j][1], meetings[j][0]});
//                 end_time.push({meetings[j][1], meetings[j][0]});
//                 j += 1;
//             }

//             // if(et_rooms.size() != 0){
//             if(et_rooms.find(timer) != et_rooms.end()){
//                 for(long long i = 0; i < et_rooms[timer].size(); i++){
//                     pq.push(et_rooms[timer][i]);
//                     // cout << et_rooms[timer][i] << " ";
//                 }
//                 et_rooms.erase(timer);
//             } 
//             // }

//             while(!pq.empty() && !end_time.empty()){
//                 auto [et , st] = end_time.front();
//                 end_time.pop();
//                 long long room = pq.top();
//                 pq.pop();
//                 et_rooms[timer + (et - st)].push_back(room);
//                 meets_held[room] += 1;
//             }

//             // cout << timer << " : " << meetings[j] << endl;
 
//             timer += 1;
//         }

//         long long max_meets = -1, max_idx = -1;
//         for(int i = 0; i < n; i++){
//             if(meets_held[i] > max_meets){
//                 max_meets = meets_held[i];
//                 max_idx = i;
//             }
//             // cout << meets_held[i] << " ";
//         }
//         return max_idx;
//     }
// };


class Solution {
public:
    static bool comparator(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }

    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<int, vector<int>, greater<int>> freeRooms;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> busyRooms;
        vector<long long> meets_held(n, 0);

        sort(meetings.begin(), meetings.end(), comparator);
        for (int i = 0; i < n; i++) freeRooms.push(i);

        long long timer = 0, j = 0, m = meetings.size();
        while (j < m || !busyRooms.empty()) {
            long long nextEvent = LLONG_MAX;
            if (j < m) nextEvent = min(nextEvent, (long long)meetings[j][0]);
            if (!busyRooms.empty()) nextEvent = min(nextEvent, busyRooms.top().first);
            timer = max(timer, nextEvent);

            while (!busyRooms.empty() && busyRooms.top().first <= timer) {
                freeRooms.push(busyRooms.top().second);
                busyRooms.pop();
            }

            while (j < m && meetings[j][0] <= timer) {
                long long s = meetings[j][0], e = meetings[j][1];
                j++;
                int room;
                if (!freeRooms.empty()) {
                    room = freeRooms.top();
                    freeRooms.pop();
                } else {
                    timer = busyRooms.top().first;
                    room  = busyRooms.top().second;
                    busyRooms.pop();
                }
                long long dur = e - s;
                busyRooms.emplace(timer + dur, room);
                meets_held[room]++;
            }
        }

        int max_idx = 0;
        long long max_meets = meets_held[0];
        for (int i = 1; i < n; i++) {
            if (meets_held[i] > max_meets) {
                max_meets = meets_held[i];
                max_idx  = i;
            }
        }
        return max_idx;
    }
};
