#include <iostream>
#include <utility>
#include <map>
#include <vector>

#define mp make_pair

using namespace std;

map<int,int> ccs;

int cc(int n)
{
    int _cc;
    if ((_cc = (*ccs.find(n)).second))
        return _cc;
    if (n % 2 == 1) {
        _cc = 1 + cc(3 * n + 1);
    } else {
        _cc = 1 + cc(n / 2);
    }
    ccs.insert(mp(n, _cc));
    return _cc;
}

int main()
{
    int _i, _j, i, j, k, cl, max;
    ccs.insert(mp(1, 1));
    while (cin >> _i) {
        cin >> _j;
        max = 0;
        if (_i > _j) {
            i = _j;
            j = _i;
        } else {
            i = _i;
            j = _j;
        }
        for (k = i; k <= j; k++) {
            cl = cc(k);
            if (cl > max)
                max = cl;
        }
        cout << _i << " " << _j << " " << max << "\n";
    }
    return 0;
}
