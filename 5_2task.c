#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include "4task.h" //Импортируем нашу библиотеку для работы с матрицами


//Прототип функции проверки корректности строки по условию задачи(хотя бы один элемент строки не равен другим)
int string_correctness(int **matrix, int row,int column,int index);
//Прототип функция для проверки на диагонали 
int is_on_diagonal(int **matrix, int size,int *element);
//Прототип функции изменения знака максимального по модолю элемента в строке
void swap_sign_of_element(int **matrix,int row,int column);



int main(){

    int **matrix;                  //Указатель на целочисленную матрицу
    int row,column,size_of_data;   //кол-во строк, столбцов и выделямая память под матрицу
    void **p;                      //Указатель на матрицу


    //В цикле обрабатываем 2 матрицы, полученные от пользователя и возвращаем измененную матрицу
    for(int i = 1; i < 3; i++){
        printf("Введите размер [%d] квадратной матрицы  и память\n", i);
        scanf("%d %d %d",&row,&column,&size_of_data); 
        //Проверка на корректность введенных данных
        if((row <= 2 || column <= 2) || (column != row)){
            printf("Введите больший размер\n");
            return 1;
        }

        p = init_dynamic_matrix(row,column,size_of_data); //Вызываем функцию выделения памяти для матрицы
        matrix = (int **) p;                              //Приводим нашу матрицу к целочисленному виду

        printf("Заполните матрицу\n");                      
        add_int_elements_in_matrix(matrix,row,column);    //Вызываем функцию заполнения матрицы

        printf("\n Ваша матрица\n");
        output_int_matrix(matrix,row,column);             //Вызываем функцию вывода матрицы
        swap_sign_of_element(matrix,row,column);          //Вызываем функцию изменения знака максимального элемента строки матрицы 

        printf("Измененная матрица\n");
        output_int_matrix(matrix,row,column);              //Вызываем функцию вывода матрицы
        printf("\n");
    }

    return 0;
}


//Функция проверки корректности строки по условию задачи(хотя бы один элемент строки не равен другим)
int string_correctness(int **matrix, int row,int column,int index){
    
        int flag = 0;                      //Подсчет кол-ва одинаковых элементов в строке
        int element = matrix[index][0];    //Первый элемент полученного индекса строки 

        //Проверка на одинаковость элементов строки
        for(int j=0; j<column; j++){
            if(abs(element) == abs(matrix[index][j])){
                flag +=1;
            } 
        }
        if (flag == column) { 
            //В случае, если все элементы строки равны между собой возвращаем 0(Проверка на корректность не прошла)
            return 0;
        }
        //В случае, если корректность строки пройдена.
        return 1;
}

//Функция для проверки на диагонали 
int is_on_diagonal(int **matrix, int size,int *element){
    //Проверка лежит ли элемент на главной диагонали
    for(int i = 0; i < size;i++){
        if ( &(matrix[i][i]) == &(*element)){
            return 1;
        }
    }
    //Проверка лежит ли элемент на побочной диагонали
    for(int j = 0, i = size-1; j< size && i >= 0 ;--i, ++j){
        if(&(matrix[j][size- 1 - j]) == &(*element)){
            return 1;
        }
    }
    return 0; 
}

//Функция изменения знака максимального по модолю элемента в строке
void swap_sign_of_element(int **matrix,int row,int column){
    int max_char = INT_MIN; //Число для сравнения с элементами матрицы
    int *p;                 //Указатель на максимальный элемент строки.
    int flag = 0;           //Флаг для корректности строки
    int stop = 0;           //Флаг для остановки изменения знака элемента строки 

    for(int i = 0; i<row; i++){
        flag = string_correctness(matrix,row,column,i); //Вызываем функцию проверки текущей строки на коррекность.
        if(flag){
            for(int j =0; j<column; j++){   
                //Проверка условия на максимальный элемент строки
                if(abs(matrix[i][j]) > max_char){
                    //Если элемент не лежит на диагоналях матрицы
                    if(!is_on_diagonal(matrix,row,&matrix[i][j])){
                        max_char = abs(matrix[i][j]);
                        p = &matrix[i][j]; //Запоминаем адрес максимального элемента 
                    }
                    else{
                        p = NULL; 
                        
                    }
                }
            }
            //Изменение знака максимального элемента строки массива
            if(p != NULL){
                *p = *p*(-1);
            }
            max_char = INT_MIN;
            stop = 0;
        }
    }

}