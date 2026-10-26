int maxProfit(int *prices, int pricesSize)
{
    int maxProfit = 0;

    for (int i = 0; i < pricesSize; i++)
    {
        for (int j = i + 1; j < pricesSize; j++)
        {
            int profit = prices[j] - prices[i];
            if (profit > maxProfit)
            {
                maxProfit = profit;
            }
        }
    }
    return maxProfit;
}
