//Write a program to find the solution to Knapsack Problem Instance.
//Exp 4.A

#include <stdio.h>
int max(int a, int b) 
{
    return (a > b) ? a : b;
}

void knapsack(int W, int wt[], int val[], int n) 
{
    int i, w;
    int K[n + 1][W + 1];
    for (i = 0; i <= n; i++) 
	{
        for (w = 0; w <= W; w++) 
		{
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
	printf("Maximum value in Knapsack = %d\n", K[n][W]);
}

int main() 
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    knapsack(W, wt, val, n);
    return 0;
}

23UAM120_Exp4.c
Displaying 23UAM120_Exp4.c.
