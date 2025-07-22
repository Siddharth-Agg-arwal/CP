class Solution
{
public:
    int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers)
    {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int n = trainers.size();
        int m = players.size();

        int tptr = n - 1, pptr = m - 1;
        int matches = 0;
        while (tptr >= 0 && pptr >= 0)
        {
            if (players[pptr] > trainers[tptr])
            {
                pptr -= 1;
            }
            else
            {
                matches += 1;
                pptr -= 1;
                tptr -= 1;
            }
        }

        return matches;
    }
};