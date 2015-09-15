#ifndef I3DOA_POWER_H
#define I3DOA_POWER_H

/*
1) x ganget med sig selv exp gange.
2) exp = 0. return 1.
3) exp > 0. return x * power(x, exp-1).
4) Standard heltals argument.
*/

namespace doa {
    int power(int x, unsigned int exp) {
        if (exp == 0) return 1;
        return x * power(x, exp-1);
    }
}

#endif //I3DOA_POWER_H
