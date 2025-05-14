#include <stdio.h>
#include <unistd.h> // For sleep()

#define MAX 5

int main() {
    int n, h, ch;
    int hp[MAX]; // hungry philosophers

    printf("Enter the total number of philosophers: ");
    scanf("%d", &n);

    printf("How many are hungry: ");
    scanf("%d", &h);

    for (int i = 0; i < h; i++) {
        printf("Enter philosopher %d position (1 to %d): ", i + 1, n);
        scanf("%d", &hp[i]);
    }

    while (1) {
        printf("\n1. One can eat at a time\n");
        printf("2. Two can eat at a time\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        if (ch == 3) {
            printf("Exiting...\n");
            break;
        }

        if (ch == 1) {
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < h; j++) {
                    printf("P %d is waiting\n", hp[j]);
                }

                printf("P %d is granted to eat\n", hp[i]);
                sleep(1);
                printf("P %d has finished eating\n", hp[i]);
            }
        }

        else if (ch == 2) {
            int i = 0;
            while (i < h) {
                for (int j = 0; j < h; j++) {
                    printf("P %d is waiting\n", hp[j]);
                }

                for (int j = 0; j < 2 && i < h; j++, i++) {
                    printf("P %d is granted to eat\n", hp[i]);
                    sleep(1);
                    printf("P %d has finished eating\n", hp[i]);
                }
            }
        }
    }

    return 0;
}
