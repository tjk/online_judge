#include <iostream>

#define IF(v) if (min == v) { cout << #v << " " << min << endl; continue; }

using namespace std;

int main()
{
    unsigned int b1, g1, c1, b2, g2, c2, b3, g3, c3;
    unsigned int b12, b13, b23;
    unsigned int g12, g13, g23;
    unsigned int c12, c13, c23;
    unsigned int BGC, BCG, GBC, GCB, CBG, CGB, min;
    while (cin >> b1 >> g1 >> c1 >> b2 >> g2 >> c2 >> b3 >> g3 >> c3) {
        b12 = b1 + b2; b13 = b1 + b3; b23 = b2 + b3;
        g12 = g1 + g2; g13 = g1 + g3; g23 = g2 + g3;
        c12 = c1 + c2; c13 = c1 + c3; c23 = c2 + c3;
        min = BGC = b23 + g13 + c12;
        if ((BCG = b23 + g12 + c13) < min) min = BCG;
        if ((GBC = b13 + g23 + c12) < min) min = GBC;
        if ((GCB = b12 + g23 + c13) < min) min = GCB;
        if ((CBG = b13 + g12 + c23) < min) min = CBG;
        if ((CGB = b12 + g13 + c23) < min) min = CGB;
        IF(BCG) IF(BGC) IF(CBG) IF(CGB) IF(GBC) IF(GCB)
    }
    return 0;
}
