#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> strings(6);
    for (int i = 0; i < 6; i++)
    {
        cin >> strings[i];
    }

    int num_notes;
    cin >> num_notes;
    vector<int> notes(num_notes);
    for (int i = 0; i < num_notes; i++)
    {
        cin >> notes[i];
    }

    // 1) Build all (fret, note_index) pairs
    vector<pair<int, int>> all_fret_note(6 * num_notes);
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < num_notes; j++)
        {
            int idx = i * num_notes + j;
            all_fret_note[idx].first = notes[j] - strings[i];
            all_fret_note[idx].second = j;
        }
    }

    // 2) Sort by fret ascending
    sort(all_fret_note.begin(), all_fret_note.end(),
         [&](auto &A, auto &B)
         {
             return A.first < B.first;
         });

    // 3) Sliding‐window to cover all note‐indices 0..(num_notes-1)
    vector<int> cnt(num_notes, 0);
    int covered = 0;
    int L = 0;
    long long answer = LLONG_MAX;

    for (int R = 0; R < 6 * num_notes; R++)
    {
        int noteR = all_fret_note[R].second;
        if (cnt[noteR] == 0)
        {
            covered++;
        }
        cnt[noteR]++;

        // Once we've covered all notes, try to shrink from the left
        while (covered == num_notes && L <= R)
        {
            // Compute current fret‐span
            long long fretL = all_fret_note[L].first;
            long long fretR = all_fret_note[R].first;
            answer = min(answer, fretR - fretL);

            // Now remove the L‐th pair from the window
            int noteL = all_fret_note[L].second;
            cnt[noteL]--;
            if (cnt[noteL] == 0)
            {
                covered--;
            }
            L++;
        }
    }

    cout << answer << "\n";
    return 0;
}
