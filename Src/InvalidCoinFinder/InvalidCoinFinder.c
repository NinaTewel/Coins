#include <stdio.h>
#include <InvalidCoinFinder.h>
#include "InvalidCoinFinder_Internal.h"

int compare(t_CoinMass* table1, t_CoinMass* table2, t_CoinNumber size)
{
    t_CoinMass   m1  = 0;
    t_CoinMass   m2  = 0;
    t_CoinNumber cnt;

    int          retVal;

    for(cnt = 0; cnt < size; cnt++)
    {
        m1 += table1[cnt];
        m2 += table2[cnt];
    }

    if(m1 == m2)      retVal = EQUAL;
    else if (m1 < m2) retVal = LIGHTER;
    else              retVal = HEAVIER;

    return retVal;
}

t_CoinNumber findInvalidCoin(t_CoinMass* coins, t_CoinNumber numberOfCoins)
{
    t_CoinNumber ret = 0;

    if(NUMBER_OF_COINS != numberOfCoins)
    {
    	printf("\n%s: Only solved for %d coins now",
               __FUNCTION__,
               NUMBER_OF_COINS);
    }
    else
    {
        // STEP 1:
        switch(compare(&coins[0], &coins[4], 4))
        {
            case EQUAL:
                ret = step1_Equal(coins); break;
            case LIGHTER:
                ret = step1_NotEqual(coins, LIGHTER); break;
            case HEAVIER:
                ret = step1_NotEqual(coins, HEAVIER); break;
            default: break;
        }
    }

    return ret;
}
