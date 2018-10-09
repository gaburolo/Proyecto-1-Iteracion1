//
// Created by martinPC on 28/9/2018.
//

#ifndef BUBBLESORT_H
#define BUBBLESORT_H
// C program for implementation of Bubble sort
#include <stdio.h>
#include "../Single/ListaDoble.h"
#include "../Single/MPointer.cpp"

template <class pr>
void Show2(pr &d){

    std::cout<<d<<",";
}

class Bubblesort {
public:
    Bubblesort(){

    }


public:
// A function to implement bubble sort
    template <class T>
    void bubbleSort(Lista<MPointer<T>>* lista, int n)
    {


        int i, j;
        for (i = 0; i < n-1; i++){
            // Last i elements are already in place
            for (j = 0; j < n-i-1; j++){

                if (lista->get_Data(j).getID()> lista->get_Data(j+1).getID()){

                    MPointer<T> tempo=lista->get_Data(j);
                    lista->ChangeDataPos(lista->get_Data(j+1),j);
                    lista->ChangeDataPos(tempo,j+1);

                }

            }
        }
    }



/* Function to print an array */
    template <class T>
    void printList(Lista<MPointer<T>> lista, int size)
    {
        int i;
        for (i=0; i < size; i++)
            printf("%d ", lista.get_Data(i));
        printf("n");
    }

};


#endif //PRUEBA_BUBBLESORT_H
