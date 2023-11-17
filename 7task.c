#include <stdio.h>
#include <stdlib.h>
#include "4task.h"
#include <limits.h>
/*
void swapRows(int **matrix, int i, int j,int row) {
    int temp[row];

    for(int k=0;k<row;k++) {
        temp[k] = matrix[i][k];  
    }
    for(int k=0;k<row;k++) {
        matrix[i][k] = matrix[j][k];
        matrix[j][k] = temp[k];
    }

}*/
/*
int findMaxIndex(int **matrix, int row,int column) {
    int max_index = 0, max_sum = 0;
    for(int i=0;i<row;i++) {
        int sum = 0;
        for(int j=0;j<column;j++) {
            if(matrix[i][j]%2!=0) {  
                sum += matrix[i][j];
                //printf("%d\n",sum);
            }
        }
        if(sum > max_sum) {
            max_sum = sum;
            max_index = i;
        }
    }
    printf("%d ", max_index);
return max_index;
}*/

void replace_rows(int **matrix,int column, int last_index, int index){
    int buf[column];

    for(int i = 0; i < column; i++){
        buf[i] = matrix[last_index][i];
        matrix[last_index][i] = matrix[index][i];
    }
    for(int j = 0; j < column;j++){
        matrix[index][j] = buf[j];
    }
}

void sort_matrix(int **matrix, int row,int column){
    int sum = 0;
    int max_sum = 0;
    int max_index = 0;
    int last_index = (row-1);
    for(int i=0;i<row;i++){
        for(int j =0; j< column; j++){
            if(matrix[i][j]%2!=0)
            {
                sum += matrix[i][j];
            }
        }
        if (sum > max_sum)
        {
            printf("%d ", i);
            printf("%d ", sum);
            max_sum = sum;
            max_index = i;
            last_index -= i;
            if(last_index == max_index){
                last_index += 1;
            }
            printf("%d %d", last_index,max_index);
            //printf("%d", last_index);
            replace_rows(matrix,column,last_index,max_index);
        }
        sum = 0;
    }
}
/*
void sortMatrix(int **matrix, int row,int column){
    for(int i=0;i<row;i++) {
        swapRows(matrix, i, findMaxIndex(matrix, row,column),row);
}
}
*/
void rep(int **matrix, int row,int column,int index,int index_start){
    int buf[row];
    for(int i = 0; i <column; i++)
    {
        buf[i] = matrix[index_start][i];
    }
    for(int j =0;j<column;j++){
            matrix[index_start][j] = matrix[index][j];
            matrix[index][j] = buf[j];
    
    }
}

int main(void) {
    void **matrix;
    int row,column;
    int size_data;
    int max_sum  = INT_MAX;
    int max_index = 0;
    printf("Введите размер матрицы и память: "); 
    scanf("%d %d %d",&row,&column,&size_data);
    matrix = init_dynamic_matrix(row,column,size_data);

    int **m = (int**)matrix;
    printf("Заполните матрицу [%d]x[%d]\n", row,column);
    add_int_elements_in_matrix(m,row,column);
    printf("Ваша матрица:\n");
    output_int_matrix(m,row,column);

    int index= row - 1;
    for(int c = 0; c < row; c++)
    {
        for(int i = c; i < row; i++)
        {
            int sum = 0;
            for (int j = 0; j < column; j++)
            {
                if(m[i][j] % 2 != 0)
                {
                    sum += m[i][j];
                }
            }
            if(sum < max_sum){
                //printf("%d\n", );
                max_index = i;
                max_sum = sum;
            }
        }
        //printf("%d ",c);
        rep(m,row,column,max_index,c);
        max_sum = INT_MAX;
    }
    printf("\n");
    output_int_matrix(m,row,column);



return 0;
}