#include <stdio.h>
#include <stdlib.h>

int main(){
    int X = 10, Y = 10, Z = 10; 
    int center_x = X / 2; 
    int center_y = (X-1)/ 2 ;
    int center_z = Z / 2;
    int block_of_wood[X][Y][Z];
    for(int i = 0; i<X; i++)
    {
        for(int j =0; j < Y; j++)
        {
            for(int k=0; k < Z;k++)
            {
                block_of_wood[i][j][k] = 1;
            }
        }
    }
    for(int i = 0; i<X; i++)
    {
        for(int j = 0; j<Y;j++)
        {
            for(int k = 0; k < Z; k++)
            {
                if (i == center_y && (j < center_x || j > center_x+1) ||
                    (i < center_y || i > center_y+1) &&
                    (k < center_z || k > center_z+1))
                    {
                        block_of_wood[i][j][k]=0;
                    }
            }
        }
    }

    for (int layer = 0; layer < X; layer++) {
        for (int column = 0; column < Y; column++) {
        for (int row = 0; row < Z; row++) {
            printf("%d ", block_of_wood[layer][column][row]);
        }
        printf("\n");
    }
    printf("\n");
}
    return 0;
}

