#include <stdio.h>
#include <limits.h>

void print_frames(int frames[], int fcount) {
    for (int i = 0; i < fcount; i++) {
        if (frames[i] == -1)
            printf(" -");
        else
            printf(" %d", frames[i]);
    }
    printf("\n");
}

void simulate_FIFO(int pages[], int n, int fcount) {
    int frames[fcount];
    for (int i = 0; i < fcount; i++) frames[i] = -1;
    int front = 0, pf = 0;

    printf("\nFIFO Page Replacement Process:\n");
    for (int i = 0; i < n; i++) {
        int page = pages[i], hit = 0;
        for (int j = 0; j < fcount; j++)
            if (frames[j] == page) { hit = 1; break; }
        if (!hit) {
            frames[front] = page;
            front = (front + 1) % fcount;
            pf++;
            printf("PF No. %2d:", pf);
            print_frames(frames, fcount);
        }
    }
    printf("Total FIFO Page Faults: %d\n", pf);
}

void simulate_LRU(int pages[], int n, int fcount) {
    int frames[fcount], last_used[fcount];
    for (int i = 0; i < fcount; i++) {
        frames[i] = -1;
        last_used[i] = -1;
    }
    int pf = 0, time = 0;

    printf("\nLRU Page Replacement Process:\n");
    for (int i = 0; i < n; i++, time++) {
        int page = pages[i], hit = 0;
        for (int j = 0; j < fcount; j++) {
            if (frames[j] == page) {
                hit = 1;
                last_used[j] = time;
                break;
            }
        }
        if (!hit) {
            int replace = -1;
            for (int j = 0; j < fcount; j++) {
                if (frames[j] == -1) {
                    replace = j;
                    break;
                }
            }
            if (replace == -1) {
                int min_time = INT_MAX;
                for (int j = 0; j < fcount; j++) {
                    if (last_used[j] < min_time) {
                        min_time = last_used[j];
                        replace = j;
                    }
                }
            }
            frames[replace] = page;
            last_used[replace] = time;
            pf++;
            printf("PF No. %2d:", pf);
            print_frames(frames, fcount);
        }
    }
    printf("Total LRU Page Faults: %d\n", pf);
}

void simulate_Optimal(int pages[], int n, int fcount) {
    int frames[fcount];
    for (int i = 0; i < fcount; i++) frames[i] = -1;
    int pf = 0;

    printf("\nOptimal Page Replacement Process:\n");
    for (int i = 0; i < n; i++) {
        int page = pages[i], hit = 0;
        for (int j = 0; j < fcount; j++)
            if (frames[j] == page) { hit = 1; break; }
        if (!hit) {
            int replace = -1;
            for (int j = 0; j < fcount; j++) {
                if (frames[j] == -1) {
                    replace = j;
                    break;
                }
            }
            if (replace == -1) {
                int farthest = i, idx = -1;
                for (int j = 0; j < fcount; j++) {
                    int k;
                    for (k = i + 1; k < n; k++)
                        if (frames[j] == pages[k])
                            break;
                    if (k > farthest) {
                        farthest = k;
                        idx = j;
                    }
                }
                replace = (idx == -1) ? 0 : idx;
            }
            frames[replace] = page;
            pf++;
            printf("PF No. %2d:", pf);
            print_frames(frames, fcount);
        }
    }
    printf("Total Optimal Page Faults: %d\n", pf);
}

int main() {
    int fcount, n;
    printf("Enter number of frames: ");
    scanf("%d", &fcount);
    printf("Enter length of reference string: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter the reference string:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    simulate_FIFO(pages, n, fcount);
    simulate_LRU(pages, n, fcount);
    simulate_Optimal(pages, n, fcount);
    return 0;
}
