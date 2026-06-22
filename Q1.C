#include <stdio.h>
int main() {
    int n;
    printf("Enter number of time slots: ");
    scanf("%d", &n);
    int demand[n], price[n], revenue[n + 1];
    printf("\nEnter demand for each time slot:\n");
    for(int i = 0; i < n; i++) {
        printf("Demand %d: ", i + 1);
        scanf("%d", &demand[i]);
    }
    printf("\nEnter price per unit for each time slot:\n");
    for(int i = 0; i < n; i++) {
        printf("Price %d: ", i + 1);
        scanf("%d", &price[i]);
    }
    revenue[0] = 0;
    for(int i = 1; i <= n; i++) {
        revenue[i] = revenue[i - 1] + (demand[i - 1] * price[i - 1]);
    }
    printf("\nTime Slot\tDemand\tPrice\tRevenue\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t\t%d\t%d\t%d\n",
               i + 1,
               demand[i],
               price[i],
               demand[i] * price[i]);
    }

    printf("\nMaximum Total Revenue = %d\n", revenue[n]);
    return 0;
}
