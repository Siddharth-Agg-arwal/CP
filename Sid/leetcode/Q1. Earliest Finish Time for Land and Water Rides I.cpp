class Solution
{
public:
    int earliestFinishTime(vector<int> &landStartTime, vector<int> &landDuration, vector<int> &waterStartTime, vector<int> &waterDuration)
    {
        // priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        long long minfin = LLONG_MAX;
        int n = landStartTime.size();
        int m = waterStartTime.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                long long landfintime = (long long)landStartTime[i] + landDuration[i];
                long long waterfintime = max(landfintime, (long long)waterStartTime[j]);
                long long totaltime = waterfintime + waterDuration[j];
                minfin = min(minfin, totaltime);
            }
        }

        for (int j = 0; j < m; j++)
        {
            for (int i = 0; i < n; i++)
            {
                long long waterfintime = (long long)waterStartTime[j] + waterDuration[j];
                long long landfintime = max(waterfintime, (long long)landStartTime[i]);

                long long totaltime = landfintime + landDuration[i];
                minfin = min(minfin, totaltime);
            }
        }

        return minfin;

        // for(int i = 0; i < n; i++){
        //     pq.push({landStartTime[i] + landDuration[i], 0, i});
        // }
        // for(int i = 0; i < m; i++){
        //     pq.push({waterStartTime[i] + waterDuration[i], 1, i});
        // }

        // vector<int> on_top = pq.top();
        // int end1 = on_top[0];
        // int first_ = on_top[1];
        // int end2 = 0;
        // pq.pop();
        // while(!pq.empty()){
        //     auto[end, slide, idx] = pq.top();
        //     pq.pop();
        //     if(slide == first_) continue;
        //     else{
        //         if()
        //     }
        // }

        // int et1 = 1e9;
        // int min_land_time = 1e9;
        // int min_water_time = 1e9;
        // int landidx = 0;
        // int wateridx = 0;
        // char c = '\0';
        // for(int i = 0; i < n; i++){
        //     if(min_land_time > landStartTime[i] + landDuration[i]){
        //         min_land_time = landStartTime[i] + landDuration[i];
        //         landidx = i;
        //     }
        //     // et1 = min(, et1);
        // }
        // for(int i = 0; i < m; i++){
        //     if(min_water_time > waterStartTime[i] + waterDuration[i]){
        //         min_water_time = waterStartTime[i] + waterDuration[i];
        //         wateridx = i;
        //     }
        // }

        // // if(min_land_time < min_water_time){
        //     int start_time1 = max(min_land_time, waterStartTime[wateridx]);
        //     int v1 = start_time1 + waterDuration[wateridx];
        // // }/
        // // else{
        //     int start_time2 = max(min_water_time, landStartTime[landidx]);
        //     int v2 = start_time2 + landDuration[landidx];
        // // }
        // return min(v1, v2);

        // return -1;
    }
};

// 98