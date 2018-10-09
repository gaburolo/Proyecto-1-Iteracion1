//
// Created by martinPC on 8/10/2018.
//

#ifndef PROYECTO_INSERTSORT_H
#define PROYECTO_INSERTSORT_H

#include "../Single/ListaDoble.h"
#include "../Single/MPointer.cpp"

class InsertSort {
public:
    InsertSort(){

    }
    template <class T>
    void insertionSort(Lista<MPointer<T>>* lista, int n)
    {
        MPointer<T> key2;

        int i,key, j;
        for (i = 1; i < n; i++)
        {
            key = lista->get_Data(i).getID();
            key2=lista->get_Data(i);
            j = i-1;

            /* Move elements of arr[0..i-1], that are
               greater than key, to one position ahead
               of their current position */
            while (j >= 0 && lista->get_Data(j).getID() > key)
            {
                lista->ChangeDataPos(lista->get_Data(j),j+1);
                //arr[j+1] = arr[j];
                j = j-1;
            }
            lista->ChangeDataPos(key2,j+1);
            //arr[j+1] = key;
        }

    }
    template <class T>
    void printList(Lista<MPointer<T>> lista, int size)
    {
        int i;
        for (i=0; i < size; i++)
            printf("%d ", lista.get_Data(i));
        printf("n");
    }
};


#endif //PROYECTO_INSERTSORT_H
