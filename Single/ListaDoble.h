#ifndef LISTASIMPLE
#define LISTASIMPLE

#include <iostream>

template<class DATO>
class Lista {
  private:
   //// Clase local de Lista para Nodo de Lista:
   template<class DATON>
   class Nodo {
     public:
      // Constructor:
      Nodo(const DATON dat, Nodo<DATON> *sig) : data(dat), next(sig) {}
      // Attributes
      DATON data;
      Nodo<DATON> *next;
   };

   // Pointers of list for node first and current:
   Nodo<DATO> *first;
   Nodo<DATO> *current;

  public:
   // Constructor y destructor:
   Lista() : first(NULL), current(NULL) {}
   ~Lista();
   // Insert Functions:
   void FinaInsert(const DATO dat);
   void InsertFirst(const DATO dat);
   bool CurrentInsert(const DATO dat);
   void InserPos(const DATO dat, int pos);
   void Insert(const DATO dat);
   // Delete Function:
   void Delete_Pos(int pos);
   void DeleteCurrent();
   // Check if the list is empty:
   bool Empty() { return first==NULL; }
   // Get data in current node:
   DATO &CurrentValue() { return current->data; }
   // Current node is a first:
   void First() { current = first; }
   // Check current node is valid:
   bool Curret() { return current != NULL; }
   // Current node point next node:
   void Next() {
      if(current) {

         current = current->next;
      }
   }
   // Overload operator++:
   void operator++(int) { Next(); }
   // Apply function to each node:
   void ForEach(void (*func)(DATO &));
   //Get Node in determined position
   DATO get_Data(int pos);

   //Change data in determined position
   void ChangeDataPos(const DATO dat, int pos);
   //Get position in list, whit ID
   DATO SearchData(int ID);



};

//////// Implementaci�n:

// Destructor
template<class DATO>
Lista<DATO>::~Lista()
{
   while(!Empty()) {
      current = first;
      first = first->next;
      delete current;
   }
}

template<class DATO>
void Lista<DATO>::FinaInsert(const DATO dat)
{
   Nodo<DATO> *ultimo;

   // Si la lista est� vac�a, insertar al principio:
   if(Empty()) InsertFirst(dat);
   else { // Si no lo est�:
      // Buscar el �ltimo nodo:
      ultimo = first;
      while(ultimo->next) ultimo = ultimo->next;
      // Insert a continuaci�n:
      ultimo->next = new Nodo<DATO>(dat, NULL);
   }
}

template<class DATO>
void Lista<DATO>::InsertFirst(const DATO dat)
{
   first = new Nodo<DATO>(dat, first);
}

template<class DATO>
bool Lista<DATO>::CurrentInsert(const DATO dat)
{
   // S�lo si la lista no est� vac�a y current es v�lido:
   if(!Empty() && current) {
      current->next = new Nodo<DATO>(dat, current->next);
      return true;
   }
   // Si no se puede insertar, retornar con false:
   return false;
}

// Insert ordenadamente:
template<class DATO>
void Lista<DATO>::Insert(const DATO dat)
{
   Nodo<DATO> *temp = first;
   Nodo<DATO> *anterior = NULL;

   // Si la lista est� vac�a, insertar al principio:
   if(Empty()) InsertFirst(dat);
   else {
      // Buscar el nodo anterior al primer nodo con un data mayor qur 'dat'
      while(temp && temp->data < dat) {
         anterior = temp;
         temp = temp->next;
      }
      // Si no hay anterior, insertar al principio,
      // nuestro valor es el menor de la lista:
      if(!anterior)
          InsertFirst(dat);
      else // Insert:
         anterior->next = new Nodo<DATO>(dat, temp);
   }
}

template<class DATO>
void Lista<DATO>::DeleteCurrent()
{
   Nodo<DATO> *anterior;

   // Si el nodo current es el first:
   if(current && current == first) {
      // El primer nodo ser� ahora el segundo:
      // Sacar el nodo current de la lista:
      first = current->next;
      // Borrarlo:
      delete current;
      current = NULL;
   } else
   if(current && !Empty()) {
      // Buscar el nodo anterior al current:
      anterior = first;
      while(anterior && anterior->next != current)
         anterior = anterior->next;
      // Sacar el nodo current de la lista:
      anterior->next = current->next;
      // Borrarlo:
      delete current;
      current = NULL;
   }
}

// Aplicar una funci�n a cada nodo de la lista:
template<class DATO>
void Lista<DATO>::ForEach(void (*func)(DATO &))
{
   Nodo<DATO> *temp = first;

   // Recorrer la lista:
   while(temp) {
      // Aplicar la funci�n:
      func(temp->data);
      temp = temp->next;
   }
}
template <class DATO>
DATO Lista<DATO>::get_Data(int pos){
   Nodo<DATO> *temp = first;
   int i=0;
   while(temp){
      if(i==pos){
         return temp->data;
      }else{
         temp=temp->next;

      }i++;

   }

}
template <class DATO>
void Lista<DATO>::InserPos(const DATO dat, int pos) {

   int i=0;
    this->First();
   while(i<pos-1){

       this->Next();

      i++;
   }
    CurrentInsert(dat);
}

template <class DATO>
void Lista<DATO>::ChangeDataPos(const DATO dat, int pos) {
    int i=0;
    this->First();
    while(i<pos){

        this->Next();

        i++;
    }
    CurrentInsert(dat);
    DeleteCurrent();
}


template <class DATO>
DATO Lista<DATO>::SearchData(int ID){
   Nodo<DATO> *temp = first;

   int i=0;
   while(temp){

      if(temp->data==ID){

         return i;
      }else{

         temp=temp->next;

      }i++;

   }
}
template <class DATO>
void Lista<DATO>::Delete_Pos(int pos){
   int i=0;
    this->First();
   while(i<pos){

       this->Next();

      i++;
   }

    DeleteCurrent();

}





#endif

