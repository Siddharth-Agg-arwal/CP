// class Solution {
// public:
//     static bool comparator(const vector<int>& a, const vector<int>& b){
//         return a[0] < b[0];
//     }
//     static bool width_comp(const vector<int>& a, const vector<int> & b){
//         return a[1] < b[1];
//     }

//     int maxEnvelopes(vector<vector<int>>& envelopes) {
//         vector<int> subseq_size(envelopes.size(), 1);
//         sort(envelopes.begin(), envelopes.end(), comparator);
//         for(int i = 0; i < envelopes.size(); i++){
//             envelopes[i].push_back(i);
//         }

//         int n = envelopes.size();
//         vector<vector<int>> sorted_widths = envelopes;
//         sort(sorted_widths.begin(), sorted_widths.end(), width_comp);

//         int max_subseq = 1;
//         for(int i = 1; i < envelopes.size(); i++){
//             // for(int j = i - 1; j >= 0; j--){
//             int lptr = 0, rptr = n - 1;
//             while(lptr < rptr){
//                 int mptr = (lptr + rptr) / 2;

//                 if(sorted_widths[mptr][0] < envelopes[i][0] && sorted_widths[mptr][1] < envelopes[i][1] && sorted_widths[mptr][2] < i){
//                     subseq_size[i] = max(subseq_size[i], 1 + subseq_size[sorted_widths[mptr][2]]);
//                     // break;
//                 }
//                 if(sorted_widths[mptr][1] < envelopes[i][1]){
//                     lptr = mptr + 1;
//                 }
//                 else{
//                     rptr = mptr;
//                 }
//             }

//             // }
//             max_subseq = max(max_subseq, subseq_size[i]);
//         }

//         return max_subseq;
//     }
// };

class Solution
{
public:
    // static bool comparator(const vector<int>& a, const vector<int>& b){
    //     return a[0] < b[0];
    // }
    // static bool width_comp(const vector<int>& a, const vector<int>& b){
    //     return a[1] < b[1];
    // }

    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        sort(envelopes.begin(), envelopes.end(),
             [](auto &A, auto &B)
             {
                 return A[0] < B[0] || (A[0] == B[0] && A[1] > B[1]);
             });
        vector<int> tail;
        for (auto &e : envelopes)
        {
            int h = e[1];
            auto it = lower_bound(tail.begin(), tail.end(), h);
            if (it == tail.end())
                tail.push_back(h);
            else
                *it = h;
        }
        return tail.size();
    }
};
