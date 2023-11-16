#include <stdio.h>
#include <stdlib.h>

void add_elements_in_array(int array[], int size_array){
    for(int i = 0; i < size_array; i++)
    {
        if(scanf("%d", array+i) != 1) 
        {
            printf("Введено не число.\n");
        }
    }

}

void output_array(int array[], int size_array){
    printf("Новый массив\n");
    for(int i = 0; i < size_array; i++)
    {   
        printf("%d ", array[i]);
    }

}

int deleting_even_array_elements(int array[], int size_array,int *k){
        
        int flag = 0;
        int added = 0;
        int index = 0;

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

        if(added)
                array = (int*)realloc(array, sizeof(int)*size_array);
        if(!array) {
                printf("Память не перевыделена!\n");
                array = _array;
        }
        return size_array;
}

int *find_element_in_array(int array[],int size_array,int key){
    int *k = NULL;
    for(int i = 0; i < size_array; i++) 
    {
        if(i == (key))
        {
            k = &array[i];
            return k;
        }
    }
    printf("Ключ не найден\n");
    return k;
}


int main() {
        int n;
        int* m;
        int *k;
        int n_size;
        int key;
        printf("Размер массива?: ");
        scanf("%d", &n);
        if(n <= 0) 
        {
            printf("Размер должен быть > 0.\n");
            return 0;
        }

        m = (int*)malloc(sizeof(int)*n);

        add_elements_in_array(m,n);

        printf("Введите  ключ(индекс) элемента, который хотите удалить");
        scanf("%d", &key);

        k = find_element_in_array(m,n,key);
        n_size = deleting_even_array_elements(m,n,k);

       
        output_array(m,n_size);
 
        printf("\n");

        free(m);
        return 0;
}

