/*
 Shirken's Snake
 
 Copyright (C) 2007-2014 Juan Delgado dp.juan@gmail.com

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef __CLASE__COLA__ 
#define __CLASE__COLA__ 

#include <iostream>
using namespace std;

//NO ACOTADA

template <typename TBase>

class CCola{

   public:
      CCola();
      ~CCola();
      void Encolar(const TBase x);
      void Desencolar();
      TBase Primero() const;
      TBase Ultimo() const;
      int NElementos() const;
      bool Vacia();

   private:
      struct TNodo{
         TBase dato;
         TNodo *sigui;
      };
      TNodo *ult;
      TNodo *prim;
      int NElem;
};

//-----------------------------------------------------------------------------------
//implementacion		
template <typename TBase>
CCola<TBase>::CCola(){
   NElem = 0;
   prim =NULL;
   ult=NULL;
}

template <typename TBase>
CCola<TBase>::~CCola(){
   TNodo *aux;
   while (prim != NULL){
      aux = prim;
      prim = prim->sigui;
      delete aux;
   }
}

template <typename TBase>
void CCola<TBase>::Encolar(const TBase x){
   TNodo *tmp = new TNodo;
   tmp->dato=x;
   tmp->sigui=NULL;
   if (Vacia()){
   	prim=tmp;
   }else{
   	ult->sigui=tmp;
   }
   ult=tmp;
   NElem++;
}

template <typename TBase>
void CCola<TBase>::Desencolar(){
   TNodo *tmp = prim;
   prim = prim->sigui;
   delete tmp;
   if (prim==NULL){
   	prim=NULL;
   }
   NElem--;
}

template <typename TBase>
TBase CCola<TBase>::Primero() const{
   return prim->dato;
}

template <typename TBase>
TBase CCola<TBase>::Ultimo() const{
   return ult->dato;
}

template <typename TBase>
int CCola<TBase>::NElementos() const{
   return NElem;
}

template <typename TBase>
bool CCola<TBase>::Vacia(){
	return (prim==NULL);
}
#endif
