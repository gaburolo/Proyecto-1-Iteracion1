#include <iostream>
#include "Single/MPointer.cpp"
#include "Single/MPointerGC.h"
#include <stdlib.h>
#include "Sort/Bubblesort.cpp"
#include "Sort/InsertSort.cpp"

int main() {
    // Inicializar el SINGLETON
    MPointerGC<MPointer<int>*>& pointerGC= MPointerGC<MPointer<int> *>::Instance();

    //Crear MPointer
    MPointer<int> ptr=MPointer<int>::New();
    MPointer<int> ptr2=MPointer<int>::New();
    MPointer<int> ptr3=MPointer<int>::New();
    MPointer<int> ptr4=MPointer<int>::New();
    //Almacenar el dato deseado forma 1
    *ptr=6;
    *ptr2=100;
    //Sobre carga del operador & para obtener el dato
    int valor = &ptr;
    int valor2 = &ptr2;
    //imprimos los valores para comprobar que este correctamente
    std::cout<<"CASO1 Operador *"<<std::endl;
    std::cout<<"Valor: "<<valor<<std::endl;
    std::cout<<"Valor2: "<<valor2<<std::endl;

    //Sobrecarga del operador =
    ptr3=ptr;
    ptr4=ptr;

    //imprimos los valores para comprobar que este correctamente
    std::cout<<"CASO2 Igualar puntero a puntero"<<std::endl;
    std::cout<<"CASO2 Valores"<<std::endl;
    std::cout<<"ptr3 valor: "<<&ptr3<<std::endl;
    std::cout<<"ptr4 valor: "<<&ptr4<<std::endl;
    std::cout<<"CASO2 Referencias"<<std::endl;
    std::cout<<"Referencia de ptr: "<<ptr<<std::endl;
    std::cout<<"Referencia de ptr3: "<<ptr3<<std::endl;
    std::cout<<"Referencia de ptr4: "<<ptr4<<std::endl;
    std::cout<<"Referencia de ptr2: "<<ptr2<<" Se puede apreciar que es diferente a los anteriores"<<std::endl;
    std::cout<<"CASO2 ID"<<std::endl;
    std::cout<<"Referencia de ptr: "<<ptr.getID()<<std::endl;
    std::cout<<"Referencia de ptr3: "<<ptr3.getID()<<std::endl;
    std::cout<<"Referencia de ptr4: "<<ptr4.getID()<<std::endl;
    std::cout<<"Referencia de ptr2: "<<ptr2.getID()<<" Se puede apreciar que es diferente a los anteriores"<<std::endl;


    //Sobrecarga del operador =
    ptr3=777;
    ptr4=100;


    int valor3 = &ptr3;
    int valor4 = &ptr4;
    //imprimos los valores para comprobar que este correctamente
    std::cout<<"CASO3 Operador = a un dato"<<std::endl;
    std::cout<<"Valor3: "<<valor3<<std::endl;
    std::cout<<"Valor4: "<<valor4<<std::endl;
    //Comprobar que MPOINTERGC esta guardando los punteros
    pointerGC.Draw();
    std::cout<<std::endl;
    //Conteo de referencias
    //ptr2 actualmente solo tiene conteo de referencias
    std::cout<<"Conteo de referencias"<<std::endl;
    std::cout<<"Conteo actual de ptr2 :"<<ptr2.getCont_ref()<<std::endl;
    //ptr2 ahora tendra 2 referencias
    ptr=ptr2;
    std::cout<<"Conteo actual de ptr2 :"<<ptr2.getCont_ref()<<std::endl;
    //ptr2 ahora tendra 3 referencias
    ptr3=ptr2;
    std::cout<<"Conteo actual de ptr2 :"<<ptr2.getCont_ref()<<std::endl;


    //Como ptr y ptr3 tomaron la referencia ptr2, su contador principal se volvio 0 por lo tanto MPOINTERGC libero la memoria
    pointerGC.Draw();
    std::cout<<std::endl;
    //Esto mismo sucede si igualamos a NULL nuestro puntero
    ptr=NULL;
    ptr3=NULL;
    //El conteo de referencias del puntero ptr2 llegara a 1 denuevo
    std::cout<<"Conteo actual de ptr2 :"<<ptr2.getCont_ref()<<std::endl;
    std::cout<<"ptr2=NULL"<<std::endl;
    ptr2=NULL;
    std::cout<<"Conteo actual de ptr2 :"<<ptr2.getCont_ref()<<std::endl;
    std::cout<<"MPOINTERGC libera la memoria"<<std::endl;
    pointerGC.Draw();
    std::cout<<std::endl;
    std::cout<<"MPOINTERGC solo queda con una posicion de memoria"<<std::endl;
    std::cout<<"MPOINTERGC valor de la unica posicion de memoria que hay actualmente: "<<pointerGC.get(0)->getValue()<<std::endl;

    //std::cout<<pointerGC.get(2)->getValue()<<std::endl;

//SORTS
/*
    Lista<MPointer<int>> lista_pointer;
    lista_pointer.FinaInsert(ptr);


    lista_pointer.FinaInsert(ptr2);
    lista_pointer.FinaInsert(ptr3);
    Lista<MPointer<int>>* lista1=&lista_pointer;
    Bubblesort bubblesort;
    bubblesort.printList(lista_pointer, 3);
    InsertSort insertSort;
    //bubblesort.bubbleSort(&lista_pointer,3);
    insertSort.insertionSort(&lista_pointer,3);
    std::cout<<std::endl;
    bubblesort.printList(lista_pointer, 3);
    return 0;
*/
}