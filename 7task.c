#include <stdio.h>

void swapRows(int a[4][4], int i, int j) {
int temp[4];
for(int k=0;k<4;k++) {
temp[k] = a[i][k];
}
for(int k=0;k<4;k++) {
a[i][k] = a[j][k];
a[j][k] = temp[k];
}
}

int findMaxIndex(int a[][4], int n) {
int max_index = 0, max_sum = 0;
for(int i=0;i<n;i++) {
int sum = 0;
for(int j=0;j<4;j++) {
if(a[i][j]%2!=0) {
sum += a[i][j];
}
}
if(sum > max_sum) {
max_sum = sum;
max_index = i;
}
}
return max_index;
}

void sortMatrix(int a[][4], int m, int n) {
for(int i=0;i<(m-1);i++) {
swapRows(a, i, findMaxIndex(a, m));
}
}

int main(void) {
int matrix[4][4] = {
{1, 2, 3, 4},
{5, 6, 7, 8},
{9, 10, 11, 12},
{13, 14, 15, 16}
};
sortMatrix(matrix, 4, 4);
for(int i=0;i<4;i++) {
for(int j=0;j<4;j++) {
printf("%d ", matrix[i][j]);
}
printf("\n");
}
return 0;
}