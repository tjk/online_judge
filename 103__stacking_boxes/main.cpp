#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

// NOTE algo wrong (look at wrong.txt)

bool seqSort(const pair<vector<int>,int> &pi, const pair<vector<int>,int> &pj)
{
    for (int i = 0; i < pi.first.size(); i++)
        if (pi.first[i] > pj.first[i])
            return false;
    return true;
}

// DEBUG
void printSequences(const vector<pair<vector<int>,int> > &v)
{
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].second + 1 << ": ";
        for (int j = 0; j < v[i].first.size(); j++)
            cout << v[i].first[j] << " ";
        cout << endl;
    }
}

int main()
{
    int k, n;
    int d;
    while (cin >> k >> n) {
        vector<pair<vector<int>,int> > sequences;
        for (int i = 0; i < k; i++) {
            sequences.push_back(make_pair(vector<int>(), i));
            for (int j = 0; j < n; j++) {
                cin >> d;
                sequences[i].first.push_back(d);
            }
            sort(sequences[i].first.begin(), sequences[i].first.end());
        }
        sort(sequences.begin(), sequences.end(), seqSort);

        // DEBUG
        printSequences(sequences);
        // DEBUG

        int prev = 0;
        vector<int> answer;
        answer.push_back(sequences[prev].second);
        for (int curr = 1; curr < k; curr++) { // TODO take care of when size < 1
            for (int j = 0; j < n; j++)
                if (sequences[curr].first[j] <= sequences[prev].first[j])
                    goto continueOuter;
            answer.push_back(sequences[curr].second);
            prev = curr;
continueOuter:
            curr = curr; // nothing
        }
        // then go up the lines and as long as prev[i] <= curr[i]
        // for 0 <= i <= n, add 1
        int size = answer.size();
        cout << size << endl;
        for (int j = 0; j < size - 1; j++)
            cout << answer[j] + 1 << " ";
        cout << answer[size - 1] + 1 << endl;
    }
    return 0;
}
