#include <stdio.h>
#include <stdlib.h>

//Прототип функции заполенения одномерного массива.
void add_elements_in_array(int array[], int size_array);

//Прототип функция вывода одномерного массива.
void output_array(int array[], int size_array);

//Прототип функция удаления элемента одномерного массива по значению ключа.
int deleting_even_array_elements(int array[], int size_array,int *k);

//Прототип функции нахождение элемента в массиве по заданому ключу.
int *find_element_in_array(int array[],int size_array,int key);


int main() {
        int n;      //Размер массива.
        int* m;     //Указатель на массив.
        int *k;     //Указатель на найденный элемент массива по ключу.
        int key;    //Ключ.
        //Ввод размера массива.
        printf("Размер массива?: ");
        scanf("%d", &n);
        if(n <= 0) 
        {
            printf("Размер должен быть > 0.\n");
            return 0;
        }
        
        m = (int*)malloc(sizeof(int)*n); //Выделение памяти под одномерный динамический массив.

        add_elements_in_array(m,n);//Вызываем функцию заполнения одномерного массива.

        printf("Введите  ключ(индекс) элемента, который хотите удалить ");
        scanf("%d", &key);//Ввод ключа

        k = find_element_in_array(m,n,key);     //Вызываем функцию нахождение элемента в массиве по заданому ключу(Возвращаемое значение - адрес элемента в памяти).
        n = deleting_even_array_elements(m,n,k);//Вызываем функцию удаления элемента одномерного массива по значению ключа.

       
        output_array(m,n);//Вызываем функцию вывода одномерного массива.
 
        printf("\n");

        free(m);//Чистим память занятую под динамический одномерный массив.
        return 0;

}

//Функция заполенения одномерного массива.
void add_elements_in_array(int array[], int size_array){
    for(int i = 0; i < size_array; i++){
        if(scanf("%d", array+i) != 1){
            printf("Введено не число.\n");
        }
    }

}

//Функция вывода одномерного массива.
void output_array(int array[], int size_array){
    for(int i = 0; i < size_array; i++){   
        printf("%d ", array[i]);
    }

}

//Функция удаления элемента одномерного массива по значению ключа
int deleting_even_array_elements(int array[], int size_array,int *k){
        
        int flag = 0;  //Флаг при нахождении элемента по ключу.
        int index = 0;  //Индекс элемента для заполнения массива новыми значениями(размер измененного массива)

        for(int i = 0; i < size_array; i++) {
            if (&array[i] == k)
            {   
                flag = 1;
            }
            if(!flag)
            {   
                array[index++] = array[i];
                flag = 0;
            }
            flag = 0;
        }

        size_array = index;
        int* _array = array;

        //Перевыделение памяти массива.
        if(index)
                array = (int*)realloc(array, sizeof(int)*size_array);
        if(!array) {
                printf("Память не перевыделена!\n");
                array = _array;
        }
        //Возвращаем размер измененного массива.
        return size_array;

}

//Функция нахождение элемента в массиве по заданому ключу.
int *find_element_in_array(int array[],int size_array,int key){

    int *k = NULL;  //указатель на найденный элемент по ключу.

    for(int i = 0; i < size_array; i++) 
    {
        if(i == (key))
        {
            k = &array[i];

            //Если ключ найден, возвращаем адрес найденного элемента в массиве.
            return k;
        }
    }
    printf("Ключ не найден\n");
    //Если ключ не найден, возвращаем NULL
    return k;
}