#include <stdint.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    uint16_t coords[5000][3];

    uint16_t b = 0;
    while (3 == scanf("%hu %hu %hu", &coords[b][0], &coords[b][1], &coords[b][2])) ++b;

    // FIXME handle case with 0 buildings

    uint16_t x = coords[0][0], y = 0;
    int16_t by = -1; // building index for current y
    uint16_t byr = 0; // R for by
    int16_t nb = -1; // next building with highest y

    for (uint16_t i = 0; i < b; ++i) {
        if (coords[i][1] > y) {
            printf("%s%hu", i ? " " : "", coords[i][0]); x = coords[i][0]; // move right to it
            printf(" %hu", coords[i][1]); y = coords[i][1]; // move up to it
            by = i; byr = coords[i][2]; nb = -1;
            continue;
        }

        // build a stack of buildings under coords[by][2]
        // TODO need to figure out the "going down parts"
        // if (coords[i][0] < coords[by][2] && coords[i][2] > coords[by][2] && coords[i][1]) {
        //     nb = i;
        // }

        // if (by > 0 && coords[i][2] > byr && coords[i][1] > coords[nb][1]) {

        // }

        // if (coords[i][0] > coords[by][2]) {
        //     // we must go down to highest building under building_y...
        // }
    }

    // last number is always 0
    printf(" 0\n");

    return 0;
}
