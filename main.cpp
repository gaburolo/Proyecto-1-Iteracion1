#include <iostream>
#include "Single/MPointer.cpp"
#include "Single/MPointerGC.h"
#include <stdlib.h>
int main() {
    MPointerGC<MPointer<int>*>& pointerGC= MPointerGC<MPointer<int> *>::Instance();
    MPointer<int> ptr=MPointer<int>::New();
    MPointer<int> ptr2=MPointer<int>::New();
    MPointer<int> ptr3=MPointer<int>::New();
    *ptr=6;
    ptr2=7;
    std::cout<<"ID: "<<ptr.getID()<<" Valor: "<<ptr.getValue()<< std::endl;

    std::cout<<"Valor de la lista ligado al id: "<<ptr.getID()<<" : "<<pointerGC.getElementPos(ptr2.getID())->getValue()<<std::endl;




    pointerGC.Draw();
    ptr2=ptr;
    ptr2=ptr;
    ptr3=ptr;
    std::cout<<"------"<<ptr.getCont_ref()<<std::endl;

    std::cout<<"-----bsadghsahgdhsaghdgashgdhashgdhasg-"<<std::endl;


    ptr2=1066660;
    std::cout<<"------"<<ptr.getCont_ref()<<std::endl;
    std::cout<<"ID: "<<ptr2.getID()<<" Valor: "<<&ptr3<< std::endl;
    pointerGC.Draw();
    return 0;

}