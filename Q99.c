#include <stdio.h>
#include <stdlib.h>

// Structure for car
typedef struct {
    int position;
    int speed;
} Car;

// Sort by position in descending order
int compare(const void *a, const void *b) {
    Car *c1 = (Car *)a;
    Car *c2 = (Car *)b;
    return c2->position - c1->position;
}

int main() {
    int target, n;
    scanf("%d %d", &target, &n);

    Car cars[n];

    // Input positions
    for (int i = 0; i < n; i++) {
        scanf("%d", &cars[i].position);
    }

    // Input speeds
    for (int i = 0; i < n; i++) {
        scanf("%d", &cars[i].speed);
    }

    // Sort cars by position descending
    qsort(cars, n, sizeof(Car), compare);

    int fleets = 0;
    double lastTime = 0.0;

    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].position) / cars[i].speed;

        // New fleet forms
        if (time > lastTime) {
            fleets++;
            lastTime = time;
        }
    }

    printf("%d\n", fleets);

    return 0;
}
