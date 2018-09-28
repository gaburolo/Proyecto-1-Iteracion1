//
// Created by gaburolo on 22/9/2018.
//}

#include <iostream>

#include <typeinfo>
#include "MPointerGC.h"
#include <stdlib.h>
//#include "MPointerGC.h"



template <class T>
class MPointer {
private:
    //Attributes
    T value ;

    int ID;
    bool cont=false;
    MPointer<T> *pointer;


public:
    /**
     * Constructor
     */
    MPointer(void){

    }
    /**
     * Destroyer
     */
    ~MPointer(){

    }
    
    /**
     * Call the MPointerGC class
     * Pointer->this Class
     * Send the pointer
     * Get the ID
     * Cont = true
     */
    void Upgrade(){
        if(cont== false){

            MPointerGC<MPointer<T>*>& pointerGC= MPointerGC<MPointer<T> *>::Instance();
            pointer=this;

            ID=pointerGC.AddElement(pointer);
            cont=true;

        }


    }

     static MPointer<T> New(){


    }
    /**
     * Overload operator *
     * Example: *pointer=6
     * @return value
     * Example: 6
     */
    T& operator *() {

        Upgrade();
        //return value;
    }

    /**
     *Overload operator &
     *Example: &pointer
     * @return MPointer Value
     * Example: 6
     */
    T operator &(){
        if(pointer==NULL or pointer==0){
            return 0;
        }else{

            return pointer->getValue();
        }


    }
    /**
     * Overload operator =
     * @param point MPointer<T>
     * Example MPointer<int> ptr;
     * @return MPointer<T> point
     */
    MPointer<T> operator =(MPointer<T> point){

        if(typeid(value)== typeid(point.value)){
            pointer=point.pointer;
            ID=point.getID();


            return point;

        }

    }
    /**
     * Overload operator =
     * @param mPointer T
     * Example MPointer<int> ptr=6;
     * @return
     */
    MPointer<T> operator =(T mPointer){

        if(typeid(value)== typeid(mPointer)){

            value=mPointer;
            Upgrade();
            std::cout<<"El value a igualar es del mismo tipo del value base del puntero"<<std::endl;
        }

    }
    /**
     * Overload ostream operator <<
     * @param os ostream
     * @param point MPointer<T>
     * @return ostream os
     */
    friend std::ostream& operator <<(std::ostream &os, const MPointer<T> &point){

        os<<point.pointer;
        return os;
    }

public:
    //GET AND SET
    T getValue() const {
        return value;
    }

    void setValue(T value) {
        MPointer<T>::value = value;
    }
    int getID() const {
        return ID;
    }

    void setID(int ID) {
        MPointer::ID = ID;
    }




};


