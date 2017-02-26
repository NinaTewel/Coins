#include <InvalidCoinFinder.h>
#include "InvalidCoinFinder_Internal.h"

static t_CoinNumber step1_NotEqual_Step2_Equal(int step3Res, int step1Res)
{
    t_CoinNumber retVal = 999;

    //STEP 3:
    // step3Res and step1Res = LIGHTER or step3Res and step1Res = HEAVIER
    (1 == (step3Res * step1Res))?(retVal = 7):(retVal = 6);

    return retVal;
}

static t_CoinNumber step1_NotEqual_Step2_NotEqual(int step3Res,
                                                  int step2Res,
                                                  int step1Res)
{
    t_CoinNumber retVal = 999;

    //STEP 3:
    if(EQUAL == step3Res)
    {
       (1 == (step1Res * step2Res))?(retVal = 5):(retVal = 4);
    }
    else if(step1Res == step2Res)
        (step1Res == step3Res)?(retVal = 0):(retVal = 1);
    else
        (step1Res == step3Res)?(retVal = 2):(retVal = 3);

    return retVal;
}

t_CoinNumber step1_NotEqual(t_CoinMass* coins, int step1Res)
{
    t_CoinMass tab1[] =\
        {
            coins[0], coins[1], coins[4]
        };
    t_CoinMass tab2[] =\
        {
            coins[2], coins[3], coins[5]
        };
    int step3Res;

    t_CoinNumber retVal = 999;

    //STEP 2:
    switch(compare(tab1, tab2, 3))
    {
        case EQUAL:
            step3Res = compare(&coins[6], &coins[7], 1);
            retVal = step1_NotEqual_Step2_Equal(step3Res, step1Res);
        break;

        case LIGHTER:
            if (LIGHTER == step1Res)
                step3Res = compare(&coins[0], &coins[1], 1);
            else
                step3Res = compare(&coins[2], &coins[3], 1);

            retVal = step1_NotEqual_Step2_NotEqual(step3Res, LIGHTER, step1Res);
        break;

        case HEAVIER:
            if (LIGHTER == step1Res)
                step3Res = compare(&coins[2], &coins[3], 1);
            else
                step3Res = compare(&coins[0], &coins[1], 1);

            retVal = step1_NotEqual_Step2_NotEqual(step3Res, HEAVIER, step1Res);
        break;
        default: break;
    }
    return retVal;
}
