#include "tasks.h"
#include <math.h>
#include <stdio.h>

#define MAX_SIZE 10
#define MAX_ATHLETES 20
#define SPORTS 5
#define MAX_ARRAY 100
#define EPSILON 1e-8

void clearInputBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
}

void task960() {
  int n = 0;
  printf("enter number of athletes (3 to 20): ");
  scanf_s("%d", &n);

  if (n < 3 || n > MAX_ATHLETES) {
    puts("number of athletes must be from 3 to 20");
    return;
  }

  int a[MAX_ATHLETES][SPORTS];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < SPORTS; j++) {
      printf("enter score of athlete %d in sport %d: ", i + 1, j + 1);
      scanf_s("%d", &a[i][j]);
    }
  }

  puts("\nMatrix (rows - athletes, columns - sports):");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < SPORTS; j++) {
      printf("%6d", a[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  int sum = 0;
  for (int j = 0; j < SPORTS; j++) {
    sum += a[2][j];
  }

  printf("Result: total score of the 3rd athlete = %d\n", sum);
}

void task977() {
  int n = 0;
  printf("enter for value n: ");
  scanf_s("%d", &n);

  if (n < 1 || n > MAX_SIZE) {
    puts("n must be from 1 to 10");
    return;
  }

  int a[MAX_SIZE][MAX_SIZE];

  int top = 0;
  int bottom = n - 1;
  int left = 0;
  int right = n - 1;
  int value = 1;

  while (top <= bottom && left <= right) {
    for (int j = left; j <= right; j++) {
      a[top][j] = value++;
    }
    top++;

    for (int i = top; i <= bottom; i++) {
      a[i][right] = value++;
    }
    right--;

    if (top <= bottom) {
      for (int j = right; j >= left; j--) {
        a[bottom][j] = value++;
      }
      bottom--;
    }

    if (left <= right) {
      for (int i = bottom; i >= top; i--) {
        a[i][left] = value++;
      }
      left++;
    }
  }

  puts("\nSpiral matrix:");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%5d", a[i][j]);
    }
    printf("\n");
  }
}

void task1000() {
  int n = 0;
  printf("enter for value n (odd): ");
  scanf_s("%d", &n);

  if (n < 1 || n > MAX_SIZE || n % 2 == 0) {
    puts("n must be odd and from 1 to 9");
    return;
  }

  double a[MAX_SIZE][MAX_SIZE];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("enter for value a[%d][%d]: ", i + 1, j + 1);
      scanf_s("%lf", &a[i][j]);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        for (int l = 0; l < n; l++) {
          if ((i != k || j != l) && fabs(a[i][j] - a[k][l]) < EPSILON) {
            puts("all elements of the matrix must be different");
            return;
          }
        }
      }
    }
  }

  puts("\nOriginal matrix:");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%9.3lf", a[i][j]);
    }
    printf("\n");
  }

  int maxRow = 0;
  int maxColumn = 0;
  double maxValue = a[0][0];

  for (int i = 0; i < n; i++) {
    if (a[i][i] > maxValue) {
      maxValue = a[i][i];
      maxRow = i;
      maxColumn = i;
    }
    if (a[i][n - 1 - i] > maxValue) {
      maxValue = a[i][n - 1 - i];
      maxRow = i;
      maxColumn = n - 1 - i;
    }
  }

  int center = n / 2;

  printf("\nlargest element on diagonals: %.3lf (row %d, column %d)\n",
         maxValue, maxRow + 1, maxColumn + 1);
  printf("central element: %.3lf (row %d, column %d)\n", a[center][center],
         center + 1, center + 1);

  double temp = a[maxRow][maxColumn];
  a[maxRow][maxColumn] = a[center][center];
  a[center][center] = temp;

  puts("\nResulting matrix:");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%9.3lf", a[i][j]);
    }
    printf("\n");
  }
}

void task927() {
  int size = 0;
  printf("enter size of the one-dimensional array: ");
  scanf_s("%d", &size);

  if (size < 1 || size > MAX_ARRAY) {
    puts("size must be from 1 to 100");
    return;
  }

  int arr[MAX_ARRAY];

  for (int i = 0; i < size; i++) {
    printf("enter for value arr[%d]: ", i + 1);
    scanf_s("%d", &arr[i]);
  }

  int n = 0;
  int m = 0;
  printf("enter number of rows n: ");
  scanf_s("%d", &n);
  printf("enter number of columns m: ");
  scanf_s("%d", &m);

  if (n < 1 || n > MAX_SIZE) {
    puts("n must be from 1 to 10");
    return;
  }
  if (m < 1 || m > MAX_SIZE) {
    puts("m must be from 1 to 10");
    return;
  }
  if (n * m != size) {
    printf("n * m must be equal to the array size (%d)\n", size);
    return;
  }

  int a[MAX_SIZE][MAX_SIZE];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      a[i][j] = arr[i * m + j];
    }
  }

  puts("\nOne-dimensional array:");
  for (int i = 0; i < size; i++) {
    printf("%6d", arr[i]);
  }
  printf("\n");

  puts("\nTwo-dimensional array:");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%6d", a[i][j]);
    }
    printf("\n");
  }
}

void task995() {
  int n = 0;
  int m = 0;
  printf("enter for value n: ");
  scanf_s("%d", &n);
  printf("enter for value m: ");
  scanf_s("%d", &m);

  if (n < 1 || n > MAX_SIZE) {
    puts("n must be from 1 to 10");
    return;
  }
  if (m < 1 || m > MAX_SIZE) {
    puts("m must be from 1 to 10");
    return;
  }

  double a[MAX_SIZE][MAX_SIZE];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("enter for value a[%d][%d]: ", i + 1, j + 1);
      scanf_s("%lf", &a[i][j]);
    }
  }

  int minSize = n < m ? n : m;
  int k = 0;
  printf("enter for value k (1 to %d): ", minSize);
  scanf_s("%d", &k);

  if (k < 1 || k > minSize) {
    printf("k must be from 1 to %d\n", minSize);
    return;
  }

  puts("\nOriginal matrix:");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%9.3lf", a[i][j]);
    }
    printf("\n");
  }

  int maxRow = 0;
  int maxColumn = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (fabs(a[i][j]) > fabs(a[maxRow][maxColumn])) {
        maxRow = i;
        maxColumn = j;
      }
    }
  }

  printf("\nelement with max absolute value: %.3lf (row %d, column %d)\n",
         a[maxRow][maxColumn], maxRow + 1, maxColumn + 1);

  for (int j = 0; j < m; j++) {
    double temp = a[maxRow][j];
    a[maxRow][j] = a[k - 1][j];
    a[k - 1][j] = temp;
  }

  for (int i = 0; i < n; i++) {
    double temp = a[i][maxColumn];
    a[i][maxColumn] = a[i][k - 1];
    a[i][k - 1] = temp;
  }

  puts("\nResulting matrix:");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%9.3lf", a[i][j]);
    }
    printf("\n");
  }

  printf("\nResult: %.3lf is now at row %d, column %d\n", a[k - 1][k - 1], k,
         k);
}
