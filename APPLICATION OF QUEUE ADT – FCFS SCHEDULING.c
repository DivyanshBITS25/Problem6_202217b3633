#include <stdio.h>

void main() {
    int n, a[10], b[10], t[10], w[10], g[10], i;
    float att = 0, awt = 0;

    // Initialize arrays to zero
    for (i = 0; i < 10; i++) {
        a[i] = 0;
        b[i] = 0;
        w[i] = 0;
        g[i] = 0;
    }

    // Read the number of processes
    printf("Enter the number of process: ");
    scanf("%d", &n);

    // Read the burst times of each process
    printf("Enter the burst times:");
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    // Read the arrival times of each process
    printf("Enter the arrival times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Calculate the completion time for each process
    g[0] = 0; // Initial time
    for (i = 0; i < n; i++) {
        g[i + 1] = g[i] + b[i];
    }

    // Calculate waiting time and turnaround time for each process
    for (i = 0; i < n; i++) {
        w[i] = g[i] - a[i];
        t[i] = g[i + 1] - a[i];
        awt = awt + w[i];
        att = att + t[i];
    }

    // Calculate average waiting time and average turnaround time
    awt = awt / n;
    att = att / n;

    // Display results
    printf("\n\tProcess\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("\tp%d\t\t%d\t\t%d\n", i, w[i], t[i]);
    }

    printf("The average waiting time is %f\n", awt);
    printf("The average turnaround time is %f\n", att);
}
