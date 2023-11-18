#include <stdio.h>
#include <stdlib.h>


//Прототип функции вывода трехмерного массива.
void output_array(int ***array, int x,int y,int z);
//Прототип функции выделения памяти под трехмерную матрицу.
int ***init_three_dimensional_rray(int X, int Y, int Z);
//Прототип функции создания табуретки.
void create_stool(int ***array, int x, int y, int z);




//Лучше использовать со значениями 10 10 10! 
int main() {
    int X,Y,Z;  //Размеры бруска.
    int ***arr; //Указатель на трехмерный массив.

    printf("Введите размер вашей заготовки X Y Z: ");
    scanf("%d %d %d", &X, &Y, &Z);
    arr = init_three_dimensional_rray(X,Y,Z);  //Вызываем функцию для выделения памяти под трхмерный массив.
    

    create_stool(arr,X,Y,Z); //Вызываем функция для создания табуретки(Заполнение массива нулями).
    output_array(arr,X,Y,Z);  //Вызываем функция вывода массива.
    return 0;
}


//Функция выделения памяти под трехмерную матрицу.
int ***init_three_dimensional_rray(int X, int Y, int Z){
    int ***array = (int ***)malloc(Z * sizeof(int**));

    for(int i = 0; i<Z;i++){
        array[i] =(int**) malloc(X* sizeof(int*));
        for(int j=0;j<X;j++){
        array[i][j] = (int*) malloc(Y* sizeof(int));
        }
    }

    if(!array){
        printf("Память не выделена\n");
        return NULL;
    }

    return array;
}

//Функция вывода трехмерного массива.
void output_array(int ***array, int x,int y,int z) {
    for (int i = 0; i < z; i++) {
        printf("Layer %d:\n", i);
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < x; k++) {
                printf("%d", array[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

//Функция создания табуретки.
void create_stool(int ***array, int x, int y, int z) {
    //Заполняем массив нулями
    for (int i = 0; i < z; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < x; k++) {
                array[i][j][k] = 0;
            }
        }
    }

    //Определяем размеры табуретки.
    int layer = z/2;            //Высота табуретки.
    int wid = x;   
    int hig = y;
    int perekladina = z - 7;   //Расположение перекладины.

    // Заполняем элементы, принадлежащие табуретке, единицами.
    int stopx = x -3;
    int stopy = y -3;
    for (int i = 0; i < layer; i++) {
        for (int j = 0; j < hig; j++) {
            for (int k = 0; k <  wid; k++) {
                //Заполнение ножек табуретки.
                if( ((i<(perekladina-1)) || ( i > (perekladina -1))) && (i<=(layer-2))){
                    if( ((j<2) || (j > stopx)) && ((k<2) || (k > stopy))){   
                        array[i][j][k] = 1; 
                    }
                }
                //Заполнение перекладины табуретки.
                if(i ==(perekladina-1)){
                    if(((k<2) || (k > stopy)) || ((j < 2) || (j > stopx))){
                        array[i][j][k] = 1;
                    }
                }
                //Заполнение сидушки табуретки.
                if(i == (layer-1)){
                    array[i][j][k] = 1;
                }

            }
        }
    }

}