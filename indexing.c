#include <stdio.h>

int main() {
    int a[50] = {10, 20, 30, 40, 50};
    int n = 5;

    int i, pos, value;

    printf("Original Array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    printf("Element at index 2 = %d\n", a[2]);

    pos = 2;
    value = 99;
    for (i = n; i > pos; i--)
        a[i] = a[i - 1];
    a[pos] = value;
    n++;

    printf("After Insertion at index 2: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    pos = 3;
    for (i = pos; i < n - 1; i++)
        a[i] = a[i + 1];
    n--;

    printf("After Deletion from index 3: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    a[1] = 500;
    printf("After Updating index 1 to 500: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    for (i = 0; i < n; i++) {
        if (a[i] == 40) {
            printf("40 found at index %d\n", i);
            break;
        }
    }

    return 0;
}
