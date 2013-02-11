#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef vector<int> Seq;
typedef pair<Seq,int> OrderedSeq;

struct Node {
    OrderedSeq val; // TODO this can be int
    vector<Node> edges;
    Node(OrderedSeq v) : val(v), edges(vector<Node>()) {}
};

typedef vector<Node> Graphs;

// ========================= DEBUG
void printSequence(const OrderedSeq &orderedSeq)
{
    cout << orderedSeq.second + 1 << ": ";
    for (int i = 0; i < orderedSeq.first.size(); i++)
        cout << orderedSeq.first[i] << " ";
    cout << endl;
}

void printSequences(const vector<OrderedSeq> &orderedSeqs)
{
    for (int i = 0; i < orderedSeqs.size(); i++)
        printSequence(orderedSeqs[i]);
}

void printGraphs(const Graphs &graphs, int depth=0)
{
    for (int i = 0; i < graphs.size(); i++) {
        for (int j = 0; j < depth; j++)
            cout << "  ";
        printSequence(graphs[i].val);
        printGraphs(graphs[i].edges, depth + 1);
    }
}
// ========================= DEBUG

// 1 2 4 7
// 1 2 4 8
// 1 4 7 9
// 2 3 4 5
// 2 7 8 9
bool seqSort(const OrderedSeq &orderedSeqA, const OrderedSeq &orderedSeqB)
{
    for (int i = 0; i < orderedSeqA.first.size(); i++) {
        if (orderedSeqA.first[i] == orderedSeqB.first[i])
            continue;
        return orderedSeqA.first[i] < orderedSeqB.first[i];
    }
}

bool nestsIn(const OrderedSeq &orderedSeqA, const OrderedSeq &orderedSeqB)
{
    for (int i = 0; i < orderedSeqA.first.size(); i++)
        if (orderedSeqA.first[i] > orderedSeqB.first[i])
            return false;
    return true;
}

void addToGraphs(Graphs &graphs, OrderedSeq orderedSeq)
{
    bool added = false;
    for (int i = 0; i < graphs.size(); i++) {
        if (nestsIn(graphs[i].val, orderedSeq)) {
            addToGraphs(graphs[i].edges, orderedSeq);
            added = true;
        }
    }
    if (!added)
        graphs.push_back(Node(orderedSeq));
}

// this is totally fucked
vector<int> getLongestPath(const Graphs &graphs, vector<int> path=vector<int>())
{
    vector<int> longest(path); // lol so terrible
    int len = 0;
    for (int i = 0; i < graphs.size(); i++) {
        vector<int> dup(path);
        dup.push_back(graphs[i].val.second);
        vector<int> ret = getLongestPath(graphs[i].edges, dup);
        if (ret.size() > len) {
            longest = ret;
            len = ret.size();
        }
    }
    return longest;
}

int main()
{
    int k, n;
    int d;
    int prev, size;
    while (cin >> k >> n) {
        vector<OrderedSeq> orderedSeqs;
        for (int i = 0; i < k; i++) {
            orderedSeqs.push_back(make_pair(Seq(), i));
            for (int j = 0; j < n; j++) {
                cin >> d;
                orderedSeqs[i].first.push_back(d);
            }
            sort(orderedSeqs[i].first.begin(), orderedSeqs[i].first.end());
        }
        sort(orderedSeqs.begin(), orderedSeqs.end(), seqSort);
        //printSequences(orderedSeqs);
        //cout << "*************************************" << endl;

        Graphs graphs = vector<Node>();
        for (int i = 0; i < orderedSeqs.size(); i++) {
            addToGraphs(graphs, orderedSeqs[i]);
        }

        // DEBUG
        // printGraphs(graphs);

        vector<int> longestPath = getLongestPath(graphs);
        int size = longestPath.size();
        cout << size << endl;
        for (int i = 0; i < size - 1; i++)
            cout << longestPath[i] + 1 << " ";
        cout << longestPath[size-1] + 1 << endl;
    }
    return 0;
}
