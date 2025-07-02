class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        // priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> min_heap;
        // vector<vector<int>> distances(n, vector<int>(k + 2, 1e9));

        // vector<vector<pair<int,int>>> adj_list(n);
        // for(int i = 0; i < flights.size(); i ++){
        //     adj_list[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        // }

        // distances[src][0] = 0;
        // min_heap.push({0, src, 0}); //weight node stops

        // while(!min_heap.empty()){
        //     auto [cost, node, stops] = min_heap.top();
        //     min_heap.pop();

        //     if(stops > k + 1) continue;
        //     if(cost > distances[node][stops]) continue;

        //     for(auto edge : adj_list[node]){
        //         int next_node = edge.first;
        //         int next_cost = edge.second;

        //         if(stops + 1 <= k + 1 && distances[next_node][stops + 1] > distances[node][stops] + next_cost){
        //             distances[next_node][stops + 1] = distances[node][stops] + next_cost;
        //             min_heap.push({distances[next_node][stops + 1], next_node, stops +1});
        //         }
        //     }
        // }

        // int min_flight = 1e9;
        // for(int i = 0; i < distances[dst].size(); i++){
        //     min_flight = min(distances[dst][i], min_flight);
        // }

        // return (min_flight == 1e9 ? -1 : min_flight);

        vector<int> distances(n, 1e9), temp(n, 1e9);
        distances[src] = 0;

        for (int i = 0; i <= k; i++)
        {
            temp = distances; // so new distances calculated are not taken into consideration
            for (auto &flight : flights)
            {
                int from = flight[0];
                int to = flight[1];
                int cost = flight[2];
                if (distances[from] == 1e9)
                    continue;

                if (temp[to] > distances[from] + cost)
                {
                    temp[to] = distances[from] + cost;
                }
            }

            distances.swap(temp);
        }

        return (distances[dst] == 1e9 ? -1 : distances[dst]);
    }
};