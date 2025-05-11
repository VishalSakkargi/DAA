//Exp 6:Efficient Resource Allocation Using Programming
//23UAM120
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char name[10];
    int resources;
    int profit;
} Job;
int compare(const void *a, const void *b) 
{
    Job *jobA = (Job *)a;
    Job *jobB = (Job *)b;
    double ratioA = (double)jobA->profit / jobA->resources;
    double ratioB = (double)jobB->profit / jobB->resources;
    return (ratioB > ratioA) - (ratioB < ratioA);
}
void allocateResources(Job jobs[], int n, int totalResources) 
{
    qsort(jobs, n, sizeof(Job), compare);
	int resourcesUsed = 0;
    int totalProfit = 0;
	printf("Allocated Jobs:\n");
	int i;
    for (i = 0; i < n; i++) {
        if (resourcesUsed + jobs[i].resources <= totalResources) 
		{
            resourcesUsed += jobs[i].resources;
            totalProfit += jobs[i].profit;
            printf("%s ", jobs[i].name);
        }
    }
	printf("\nTotal Profit: %d\n", totalProfit);
}
int main() 
{
    Job jobs[] = {
        {"Job1", 2, 50},
        {"Job2", 3, 60},
        {"Job3", 4, 70},
        {"Job4", 5, 100}
    };
    int totalResources = 10;
    int n = sizeof(jobs) / sizeof(jobs[0]);
	allocateResources(jobs, n, totalResources);
	return 0;
}
