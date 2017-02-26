#include <stdio.h>

#include <InvalidCoinFinder.h>

static int validateSign(char sign)
{
    int retVal = 0;

    if(('+' != sign) && ('-' != sign))
    {
        printf("\n%s: Invalid sign %c given as a parameter",
               __FUNCTION__,
               sign);

        retVal++;
    }

    return retVal;
}

static void setInvalidCoin(t_CoinMass*    coinTablePtr,
                           t_CoinNumber   tableSize,
                           t_CoinNumber   numberOfCoin,
                           char           sign)
{
    t_CoinNumber cnt;

    for(cnt = 0; cnt < tableSize; cnt++)
        coinTablePtr[cnt] = PROPER_MASS;

    if(numberOfCoin < tableSize)
    {
        (sign == '+')?\
            (coinTablePtr[numberOfCoin] = TOO_HEAVY):\
            (coinTablePtr[numberOfCoin] = TOO_LIGHT);
    }
    else
    {
        printf("\n%s: Improper number of coin %d, size of table is %d",
               __FUNCTION__,
               numberOfCoin,
               tableSize);
    }

}

static int testAllCoins(char sign)
{
    t_CoinMass   coinTable[NUMBER_OF_COINS];
    t_CoinNumber invalidCoinNumber;
    t_CoinNumber cnt;

    int          retVal = 0;

    retVal += validateSign(sign);

    if(!retVal)
    {
        for(cnt = 0; cnt < NUMBER_OF_COINS; cnt++)
        {
            setInvalidCoin((t_CoinMass*) coinTable,
                           NUMBER_OF_COINS,
                           cnt,
                           sign);
            if(cnt != \
                (invalidCoinNumber = findInvalidCoin(coinTable,
                                                     NUMBER_OF_COINS)))
            {
                printf("\n%s%c: ERROR, returned coin: %d, expected: %d.\n",
                       __FUNCTION__,
                       sign,
                       invalidCoinNumber,
                       cnt);

                retVal ++;
            }
            else
            {
                printf("\n%s%c: coin %d -> OK.\n",
                       __FUNCTION__,
                       sign,
                       cnt);
            }
        }
    }

    return retVal;
}

int main()
{
    int        retVal = 0;

    retVal += testAllCoins('+');
    retVal += testAllCoins('-');

    printf("\n%s: Test returned value %d, see previous logs for details.\n",
           __FUNCTION__,
           retVal);

    return retVal;
}
