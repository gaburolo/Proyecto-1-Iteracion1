//
// Created by Martin Calderon and Olman Castro
//
#ifndef MPOINTER_CPP
#define MPOINTER_CPP
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
    bool ready=false;
    int ID;
    int cont_ref=0;

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
            ready= true;
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

        if(ready==false){

            cont_ref=1;
            Upgrade();
            return value;
        }else if(pointer->getCont_ref()>1){

            pointer->setCont_ref(pointer->getCont_ref()-1);
            cont_ref=1;
            Upgrade();
            return value;
        }else{
            return value;
        }

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

        if(typeid(value)== typeid(point.value)&& point.pointer!=pointer){
            if(ready==false){
                cont_ref=1;
                pointer=point.pointer;
                ID=point.getID();

                value=point.value;
                pointer->setCont_ref(pointer->getCont_ref()+1);


            }else{
                MPointerGC<MPointer<T>*>& pointerGC= MPointerGC<MPointer<T> *>::Instance();
                pointerGC.Delete(this->getID());
                pointer=point.pointer;
                ID=point.getID();
                value=point.value;
                cont= false;

                pointer->setCont_ref(pointer->getCont_ref()+1);
            }

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
        if(mPointer==NULL){

            if(ready==true&&pointer->getCont_ref()>1){

                pointer->setCont_ref(pointer->getCont_ref()-1);
                ID=0;
                value=0;
            }else{
                cont_ref=0;

                MPointerGC<MPointer<T>*>& pointerGC= MPointerGC<MPointer<T> *>::Instance();
                pointerGC.Delete(this->getID());
            }

        }

        else if(typeid(value)== typeid(mPointer)){
            if(ready==false){
                this->setCont_ref(1);

                value=mPointer;

                Upgrade();
            }
            else if(pointer->getCont_ref()>1){
                pointer->setCont_ref(pointer->getCont_ref()-1);
                this->setCont_ref(1);

                value=mPointer;

                Upgrade();
            }

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

    int getCont_ref() const {
        return cont_ref;
    }

    void setCont_ref(int cont_ref) {
        MPointer::cont_ref = cont_ref;
    }




};

#endif