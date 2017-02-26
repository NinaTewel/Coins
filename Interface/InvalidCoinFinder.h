#ifndef INVALID_COIN_FINDER_H
#define INVALID COIN_FINDEF_H

#define NUMBER_OF_COINS 12

#define PROPER_MASS     3
#define TOO_LIGHT       2
#define TOO_HEAVY       4

#include <stddef.h>

typedef unsigned char t_CoinMass;
typedef size_t        t_CoinNumber;

t_CoinNumber findInvalidCoin(t_CoinMass* coins, t_CoinNumber numberOfCoins);

#endif

