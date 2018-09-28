//
// Created by gaburolo on 24/9/2018.

#ifndef PROYECTO_MPOINTERGC_H
#define PROYECTO_MPOINTERGC_H



#include <iostream>
#include "ListaSimple.h"



template <class pr>
void Show(pr &d){
    std::cout<<d<<",";
}


template <class pt>

class MPointerGC {

private:
    static int pivot;
    static MPointerGC<pt>* s_instancia;
public:
    /**
     * Destroyer
     */
    ~MPointerGC(){

    }
    /**
     * Create a unique object
     * @return instance
     */
    static MPointerGC<pt>& Instance(){


        return  *s_instancia;
    }
    /**
     * Prevents another object from being created
     */
    MPointerGC(const MPointerGC<pt>&)= default;
    MPointerGC<pt>& operator=(const MPointerGC<pt>&)=delete;

    /**
     * Add an element to the list
     * @param point
     * Example: MPointe<int>
     * @return int pivot
     */
    int AddElement(pt point){
         list.InsertarFinal(point);


         pivot+=1;
         return pivot-1;
    }
    /**
     * Draw all elements in list
     */
    static void Draw(){
        list.ParaCada(Show);
    }
    /**
     * Get data in a certain position
     * @param pos int Position
     * @return data or element
     * Example: MPointe<int>
     */
    static pt getElementPos(int pos){

        return list.get_Dato(pos);
    }


private:
    /**
     * Constructor
    */
    MPointerGC(){

         pivot=0;
    }
    //Attributes
    static Lista<pt> list;


};
template<class pt>
int MPointerGC<pt>::pivot=0;

template<class pt>
Lista<pt> MPointerGC<pt>::list;

template <class pt>
MPointerGC<pt>* MPointerGC<pt>::s_instancia;

#endif //PROYECTO_MPOINTERGC_H
