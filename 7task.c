#include <stdio.h>
#include <stdlib.h>
#include "4task.h" //Импортируем нашу библиотеку для работы с матрицами.
#include <limits.h>


//Прототипа функции перестановки строк матрицы.
void replace_rows(int **matrix, int row,int column,int index,int index_start); 
//Прототипа функции определения сумм строк с нечетными элементами.
void identifying_inappropriate_strings(int **matrix, int row,int column);



int main(void){

    void **matrix;          //Указатель на двумерный динамический массив.
    int row,column;         //кол-во строк, столбцов.
    int size_data;          //Память под 1 элемент двумерного массива.

    //Вводим кол-во строк, столбцов и память под 1 элемент двумерного массива.
    printf("Введите размер матрицы и память: "); 
    scanf("%d %d %d",&row,&column,&size_data);

    matrix = init_dynamic_matrix(row,column,size_data); //Вызываем функцию для выделения памяти под динамический двумерный массив.

    int **m = (int**)matrix;                            //Указатель на целочисленную матрицу.

    printf("Заполните матрицу [%d]x[%d]\n", row,column);
    add_int_elements_in_matrix(m,row,column);          //Вызываем функцию заполения матрицы.
    printf("Ваша матрица:\n");
    output_int_matrix(m,row,column);                   //Вызываем функцию вывода матрицы.

    identifying_inappropriate_strings(m,row,column);   //Вызываем функцию определения сумм строк с нечетными элементами.
    printf("\n");
    output_int_matrix(m,row,column);                    //Вызываем функцию вывода матрицы(Выводим измененную матрицу).



return 0;
}


//Функция перестановки строк матрицы.
void replace_rows(int **matrix, int row,int column,int index,int index_start){

    int buf[row]; //Вспомогательный массив для хранения переданной строчки в функцию.

    //Сохраняем переданную строчку в массив.
    for(int i = 0; i <column; i++)
    {
        buf[i] = matrix[index_start][i];
    }
    // Меняем строчки местами методом пузырька.
    for(int j =0;j<column;j++){
            matrix[index_start][j] = matrix[index][j];
            matrix[index][j] = buf[j];
    
    }
}

//Функция определения сумм строк с нечетными элементами.
void identifying_inappropriate_strings(int **matrix, int row,int column){

    int max_sum;    //Максимальная сумма нечетных элементов строк.
    int max_index;  //Индекс строки с максмиальной суммой нечетных элементов.


    //Убираем строки по этапно сверху вниз.
    for(int c = 0; c < row; c++){
        for(int i = c; i < row; i++){
            int sum = 0;
            for (int j = 0; j < column; j++){   
                //Если элемент строки нечетный, то записываем его в сумму.
                if(matrix[i][j] % 2 != 0){
                    sum += matrix[i][j];
                }
            }
            if(sum < max_sum){
                max_index = i; //Запоминаем индекс текущей строки, если сумма минимальная.
                max_sum = sum;
            }
        }
        replace_rows(matrix,row,column,max_index,c); //Вызываем функцию перестановки строк.
        max_sum = INT_MAX;
    }
}