#include <iostream>
#include <string>
#include <map>
#include <vector>

#define pb push_back

using namespace std;

int np; // number of positions
vector<int> *ps; // positions
map<int,int> bp; // mapping of block to current position

void draw()
{
    vector<int>::iterator it;
    for (int i = 0; i < np; i++) {
        cout << i << ":";
        for (it = ps[i].begin(); it != ps[i].end(); it++)
            cout << " " << *it;
        cout << "\n";
    }
}

void move(int a, int b, bool cleara, bool clearb)
{
    vector<int>::iterator _ita, ita, _itb, itb;
    int pa, _pb; // push_back typedef naming conflict
    pa = bp[a]; _pb = bp[b];
    for (ita = ps[pa].begin(); ita != ps[pa].end(); ita++)
        if (*ita == a)
            break;
    for (itb = ps[_pb].begin(); itb != ps[_pb].end(); itb++)
        if (*itb == b)
            break;
    _ita = ita;
    itb++;
    _itb = itb;
    if (clearb) { // onto
        for ( ; itb != ps[_pb].end(); itb++) {
            bp[*itb] = *itb;
            ps[*itb].pb(*itb);
        }
        ps[_pb].erase(_itb, ps[_pb].end());
    }
    // no special behavior for over
    if (cleara) { // move
        ita++;
        for ( ; ita != ps[pa].end(); ita++) {
            bp[*ita] = *ita;
            ps[*ita].pb(*ita);
        }
        ps[pa].erase(_ita, ps[pa].end());
        bp[a] = _pb;
        ps[_pb].pb(a);
    } else { // pile
        for ( ; ita != ps[pa].end(); ita++) {
            bp[*ita] = _pb;
            ps[_pb].pb(*ita);
        }
        ps[pa].erase(_ita, ps[pa].end());
    }
}

int main()
{
    int a, b;
    string cmd, how;
    cin >> np >> cmd;
    ps = new vector<int>[np];
    for (int i = 0; i < np; i++) {
        ps[i].pb(i);
        bp[i] = i;
    }
    while (cmd != "quit") {
        cin >> a >> how >> b;
        if (a != b && bp[a] != bp[b])
            move(a, b, cmd == "move", how == "onto");
        cin >> cmd;
    }
    draw();
    return 0;
}
