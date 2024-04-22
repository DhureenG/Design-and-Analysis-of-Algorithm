#include <stdio.h>

int main() {
    int n, i;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    float weight[n], profit[n], ratio[n], capacity, totalValue = 0;

    printf("Enter the weight and profit of each item:\n");
    for (i = 0; i < n; i++) {
        scanf("%f %f", &weight[i], &profit[i]);
        ratio[i] = profit[i] / weight[i];
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%f", &capacity);

    for (i = 0; i < n; i++) {
        if (weight[i] <= capacity) {
            capacity -= weight[i];
            totalValue += profit[i];
        } else {
            totalValue += ratio[i] * capacity;
            capacity = 0;
            break;
        }
    }

    printf("The maximum value is: %.2f\n", totalValue);
    return 0;
}