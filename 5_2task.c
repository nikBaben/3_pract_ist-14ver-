#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include "4task.h"
int string_correctness(int **matrix, int row,int column,int index){
    
        int flag = 0;
        int element = matrix[index][0];
        for(int j=0; j<column; j++)
        {
            if(abs(element) == abs(matrix[index][j]))
            {
                flag +=1;
            } 
        }
        if (flag == column) 
        { 
            return 0;
        }
        return 1;
}



void swap_sign_of_element(int **matrix,int row,int column){
    int max_char = INT_MIN;
    int index = 0;
    int *p;
    int flag = 0;
    for(int i = 0; i<row; i++){
        flag = string_correctness(matrix,row,column,i);
        if(flag)
        {
            for(int j =0; j<column; j++)
            {   
                if((abs(matrix[i][j]) > max_char) && ((i != j) || (j!=row-i-1)))
                {
                    max_char =abs(matrix[i][j]);
                    p = &matrix[i][j];
                }
            }
            *p = *p*(-1);
            max_char = INT_MIN;
    }
    printf("\n");
    }
}


int main(){

    int **matrix; 
    int row,column,size_of_data;
    void **p;



    for(int i = 1; i < 3; i++){
        printf("Введите размер [%d] квадратной матрицы  и память\n", i);
        scanf("%d %d %d",&row,&column,&size_of_data); 
        if((row <= 2 || column <= 2) || (column != row)){
            printf("Введите больший размер\n");
            return 1;
        }
        p = init_dynamic_matrix(row,column,size_of_data);
        matrix = (int **) p;
        add_int_elements_in_matrix(matrix,row,column);
        printf("\n Ваша матрица\n");
        output_int_matrix(matrix,row,column); 
        swap_sign_of_element(matrix,row,column);
        printf("Измененная матрица\n");
        output_int_matrix(matrix,row,column); 
    }

    return 0;
}