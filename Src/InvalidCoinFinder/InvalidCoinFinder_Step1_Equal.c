#include <InvalidCoinFinder.h>
#include "InvalidCoinFinder_Internal.h"

static t_CoinNumber step1_Equal_Step2_Equal(int step3Res)
{
    t_CoinNumber retVal = 999;

    //STEP 3:
    switch(step3Res)
    {
        case EQUAL: retVal = 11; break;
        default: retVal = 10; break;
    }

    return retVal;
}

static t_CoinNumber step1_Equal_Step2_NotEqual(int step3Res)
{
    t_CoinNumber retVal = 999;

    //STEP 3:
    switch(step3Res)
    {
        case EQUAL: retVal = 9; break;
        default: retVal = 8; break;
    }

    return retVal;
}

t_CoinNumber step1_Equal(t_CoinMass* coins)
{
    t_CoinNumber retVal  = 999;
    int          step3Res = compare(&coins[8], &coins[10], 1);

    // STEP 2:
    switch(compare(&coins[8], &coins[9], 1))
    {
        case EQUAL:
            retVal = step1_Equal_Step2_Equal(step3Res);
        break;
        case LIGHTER:
        case HEAVIER:
            retVal = step1_Equal_Step2_NotEqual(step3Res);
        break;
        default: break;
    }

    return retVal;
}
