#ifndef INVALID_COIN_FINDER_INTERNAL_H
#define INVALID_COIN_FINDER_INTERNAL_H

#include <stddef.h>
#include <InvalidCoinFinder.h>

#define EQUAL    0
#define LIGHTER -1
#define HEAVIER  1

int compare(t_CoinMass* table1, t_CoinMass* table2, t_CoinNumber size);
t_CoinNumber step1_Equal(t_CoinMass* coins);
t_CoinNumber step1_NotEqual(t_CoinMass* coins, int step1Res);

#endif

