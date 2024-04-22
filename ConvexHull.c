#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x, y;
} Point;

double cross_product(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

Point next_to_top(Point *stack, int top) {
    return stack[top - 1];
}

void push(Point *stack, int *top, Point p) {
    stack[*top] = p;
    (*top)++;
}

Point pop(Point *stack, int *top) {
    (*top)--;
    return stack[*top];
}

int cmp(const void *a, const void *b) {
    Point *p1 = (Point *) a;
    Point *p2 = (Point *) b;
    double cmp = p2->y - p1->y;
    if (cmp != 0) {
        return cmp;
    }
    return p2->x - p1->x;
}

void merge(Point *L, int l, Point *R, int r, Point *H) {
    int i = 0, j = 0, k = 0;
    while (i < l && j < r) {
        if (next_to_top(L, l).x <= next_to_top(R, r).x) {
            if (k > 0 && cross_product(next_to_top(H, k - 1), next_to_top(L, l)) < 0) {
                pop(H, &k);
                push(H, &k, next_to_top(L, l));
            } else {
                i++;
            }
        } else {
            if (k > 0 && cross_product(next_to_top(H, k - 1), next_to_top(R, r)) < 0) {
                pop(H, &k);
                push(H, &k, next_to_top(R, r));
            } else {
                j++;
            }
        }
    }
    while (i < l) {
        if (k > 0 && cross_product(next_to_top(H, k - 1), next_to_top(L, l)) < 0) {
            pop(H, &k);
            push(H, &k, next_to_top(L, l));
        }
        i++;
    }
    while (j < r) {
        if (k > 0 && cross_product(next_to_top(H, k - 1), next_to_top(R, r)) < 0) {
            pop(H, &k);
            push(H, &k, next_to_top(R, r));
        }
        j++;
    }
}

Point *convex_hull(Point *P, int n) {
    if (n <= 3)
        return P;
    qsort(P, n, sizeof(Point), cmp);
    Point *L = malloc(n/2 * sizeof(Point));
    Point *R = malloc((n-n/2) * sizeof(Point));
    for (int i = 0; i < n/2; i++)
        L[i] = P[i];
    for (int i = n/2; i < n; i++)
        R[i-n/2] = P[i];
    Point *LH = convex_hull(L, n/2);
    Point *RH = convex_hull(R, n-n/2);
    int size = n/2 + n - n/2 - 1;
    Point *H = malloc(size * sizeof(Point));
    merge(LH, n/2, RH, n-n/2, H);
    free(LH);
    free(RH);
    return H;
}
int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);
    Point *P = malloc(n * sizeof(Point));
    printf("Enter the coordinates of the points:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &P[i].x, &P[i].y);
    }
    Point *H = convex_hull(P, n);
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || cross_product(next_to_top(H, m), P[i]) != 0) {
            H[m++] = P[i];
        }
    }
    H = realloc(H, m * sizeof(Point));
    printf("The number of points in the convex hull is %d\n", m);
    printf("The points in the convex hull are:\n");
    for (int i = 0; i < m; i++) {
        printf("(%lf, %lf)\n", H[i].x, H[i].y);
    }
    free(P);
    free(H);
    return 0;
}