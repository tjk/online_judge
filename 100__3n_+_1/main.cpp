#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

static map<int,int> _cycle_len_cache;

static int _cycle_len(int n)
{
    int cl;

    if ((cl = _cycle_len_cache[n]))
        return cl;

    if (n % 2 == 1) {
        cl = 1 + _cycle_len(3 * n + 1);
    } else {
        cl = 1 + _cycle_len(n / 2);
    }

    _cycle_len_cache[n] = cl;
    return cl;
}

int main()
{
    _cycle_len_cache[1] = 1;

    int a, b;
    while (cin >> a) {
        cin >> b;

        int i = min(a, b);
        int j = max(a, b);

        int max_cl = 0;
        for (int k = i; k <= j; ++k) {
            int cl = _cycle_len(k);
            if (cl > max_cl)
                max_cl = cl;
        }

        cout << a << " " << b << " " << max_cl << endl;
    }

    return 0;
}
