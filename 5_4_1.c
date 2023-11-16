#include <stdio.h>

#define WIDTH 10
#define HEIGHT 5
#define DEPTH 8

void printArray(int arr[][HEIGHT][DEPTH], int width) {
    for (int i = 0; i < width; i++) {
        printf("Layer %d:\n", i);
        for (int j = 0; j < HEIGHT; j++) {
            for (int k = 0; k < DEPTH; k++) {
                printf("%d ", arr[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void createStool(int arr[][HEIGHT][DEPTH], int width) {
    // Заполняем массив нулями
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            for (int k = 0; k < DEPTH; k++) {
                arr[i][j][k] = 0;
            }
        }
    }

    // Определяем размеры табуретки
    int stoolWidth = 4;
    int stoolHeight = 3;
    int stoolDepth = 4;

    // Заполняем элементы, принадлежащие табуретке, единицами
    int startX = (width - stoolWidth) / 2;
    int startY = (HEIGHT - stoolHeight) / 2;
    int startZ = (DEPTH - stoolDepth) / 2;

    for (int i = startX; i < startX + stoolWidth; i++) {
        for (int j = startY; j < startY + stoolHeight; j++) {
            for (int k = startZ; k < startZ + stoolDepth; k++) {
                arr[i][j][k] = 1;
            }
        }
    }
}

int main() {
    int arr[WIDTH][HEIGHT][DEPTH];

    createStool(arr, WIDTH);
    printArray(arr, WIDTH);

    return 0;
}
