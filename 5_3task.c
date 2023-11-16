#include <stdio.h>
#include <stdlib.h> 
#include "4task.h"

int find_simple_chars_array(int *array,int size_array){
    int count = 0; 
    int flag = 0;
    for(int i = 0; i <size_array; i++)
    {   
        for(int j = 1; j <=size_array; j++)
        {
            if ((*(array+i))% j  == 0)
            {   
                flag +=1;
            }
        }
        if (flag == 2)
        { 
            count+=1;
        }
        flag = 0;
    }
    return count;
}

int find_simple_chars_matrix(int **matrix,int row, int column){
    int count = 0; 
    int flag = 0;
    for(int i = 0; i <=row; i++)
    {   
        for(int j =0; j < column; j++)
        {
            for(int k = 1; k <= (row*column); k++)
            {
                if(matrix[i][j] % k  == 0)
                {   
                    flag +=1;
                }
            }
            if (flag == 2)
            { 
                count+=1;
            }
            flag = 0;
        }
    }
    return count;
}

void add_elements_in_array(int array[],size_t size_array){
    printf("Заполните массив\n");
    for(int i = 0; i< size_array; i++)
    {
        scanf("%d", &array[i]);
    }
}

void add_elements_in_matrix(int column, int array[][column],int row ){
    printf("Заполните матрицу\n");
    for(int i = 0; i< row; i++)
    {
        for(int j = 0;j<column; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }
}

void output_array(int array[],size_t size_array){
    for(int i = 0; i< size_array; i++)
    {
        printf("%d ", array[i]);
    }
}  

int main(){
    int size_array = 5;
    int row=2,column=2;
    int X[size_array];
    int size_data=4;
    void **p;
    int *ptr_array = X;
    int c;

    p = init_dynamic_matrix(row,column,size_data);

    int **ptr_matrix = (int**) p; 
    add_int_elements_in_array(ptr_array,size_array);
    add_int_elements_in_matrix(ptr_matrix,row,column);

    c = find_simple_chars_array(ptr_array,size_array);
    printf("Кол-во простых чисел у массива");
    printf(" %d\n",c);
    c = find_simple_chars_matrix(ptr_matrix,row,column);
    printf("Кол-во простых чисел у матрицы");
    printf(" %d\n",c);

    
    return 0; 
}