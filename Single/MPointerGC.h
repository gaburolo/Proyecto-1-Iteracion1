//
// Created by Martin Calderon and Olman Castro
//

#ifndef PROYECTO_MPOINTERGC_H
#define PROYECTO_MPOINTERGC_H



#include <iostream>
#include "ListaSimple.h"


/**
 * Print Elements
 * @tparam pr template
 * @param d data
 */
template <class pr>
void Show(pr &d){
    std::cout<<d<<",";
}


template <class pt>

class MPointerGC {

private:
    static int pivot;
    static MPointerGC<pt> *s_instancia;
public:
    /**
     * Destroyer
     */
    ~MPointerGC() {

    }

    /**
     * Create a unique object
     * @return instance
     */
    static MPointerGC<pt> &Instance() {


        return *s_instancia;
    }

    /**
     * Prevents another object from being created
     */
    MPointerGC(const MPointerGC<pt> &) = default;

    MPointerGC<pt> &operator=(const MPointerGC<pt> &) = delete;

    /**
     * Add an element to the list
     * @param point
     * Example: MPointe<int>
     * @return int pivot
     */
    int AddElement(pt point) {
        long id = (((long) point) % 10000);

        list_IDs.FinaInsert((int) id);

        list.FinaInsert(point);

        return (int) id;
    }

    /**
     * Draw all elements in list
     */
    static void Draw() {
        list.ForEach(Show);
    }

    /**
     * Search with ID
     * Get Data
     * @param ID int ID pointer
     * @return pt DATA
     * Example: MPointe<int>
     */
    static pt getElementPos(int ID) {
        int pos = list_IDs.SearchData(ID);

        return list.get_Data(pos);
    }

    /**
     * Delete ELement in Position
     * SearchData(ID)
     * Get position
     * @param ID int ID pointer
     */
    static void Delete(int ID) {
        int pos = list_IDs.SearchData(ID);


        list_IDs.Delete_Pos(pos);

        list.Delete_Pos(pos);
    }


    /**
     * Get data in a certain position
     * @param pos int Position
     * @return data or element
     * Example: MPointe<int>
     */
    static pt get(int pos){
        return list.get_Data(pos);

    }
private:
    /**
     * Constructor
    */
    MPointerGC(){


    }
    //Attributes
    static Lista<pt> list;
    static Lista<int>list_IDs;


};
//Declarations
template<class pt>
Lista<int> MPointerGC<pt>::list_IDs;

template<class pt>
Lista<pt> MPointerGC<pt>::list;

template <class pt>
MPointerGC<pt>* MPointerGC<pt>::s_instancia;

#endif //PROYECTO_MPOINTERGC_H
