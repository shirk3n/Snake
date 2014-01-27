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

#include <iostream>
#include<cstdlib>
#include "snake.h"

using namespace std;

Snake::Snake(){
	v.x=0; 
	v.y=1;
	TPosicion p;
	p.x=MAX/2; //Se inicializa en la mitad del tablero
	p.y=MAX/2;
	cola.Encolar(p);	
}

Snake::~Snake(){
}

Snake::TPosicion Snake::Cabeza(){
	return cola.Ultimo();
}

Snake::TPosicion Snake::Rabo(){
	return cola.Primero();
}

void Snake::Mover(){
	TPosicion nuevaCabeza;
	nuevaCabeza.x = Cabeza().x + v.x;
	nuevaCabeza.y = Cabeza().y + v.y;

  	cola.Desencolar(); //Quitamos un elemento del final
	cola.Encolar(nuevaCabeza); //Metemos el elemento nuevo
	
}

void Snake::SetVelocidad(int vx, int vy){
	v.x = vx;
  	v.y = vy;
}

int Snake::GetVelocidadX(){
	return v.x;
}

int Snake::GetVelocidadY(){
	return v.y;
}

TDireccion Snake::GetDireccion(){
	TDireccion result;
  
  	if (v.x > 0) {
    		result = Abajo;
  	} else {
    		if (v.x < 0) {
      		result = Arriba;
    		} else {
      			if (v.y > 0) {
        			result = Derecha;
      			} else {
        			result = Izquierda;
      			}
    		}
  	}

  	return result;
}

void Snake::Dibujar(Tablero &t){
	CCola<TPosicion> caux; //Cola auxiliar
	TPosicion e;
 
  	//Vamos extrayendo cada elemento y mostrandolo en el tablero
  	while (! cola.Vacia()) {
    		e = cola.Primero();
    		cola.Desencolar();
    		if (cola.Vacia()) {
      		//Es el ultimo de la cola: dibujamos la cabeza
      		t.SetContenido(e.x, e.y, CabezaS);
    		} else {
      			t.SetContenido(e.x, e.y, CuerpoS);
    		}
    		caux.Encolar(e);
  	}

	//Devolvemos los elementos a la cola original
  	while (! caux.Vacia()) {
    		e = caux.Primero();
    		caux.Desencolar();
    		cola.Encolar(e);
  	}
}

bool Snake::Come(Manzana &m){
	return ((Cabeza().x == m.GetPosicionX()) && (Cabeza().y == m.GetPosicionY()));
}

bool Snake::Choca(Tablero &t){
	return t.GetContenido(Cabeza().x, Cabeza().y) == Obstaculo;
}

bool Snake::ChocaSiMisma(){
	CCola<TPosicion> caux; //Cola auxiliar
  	TPosicion e;
  	bool Choca = false;

  	while (! cola.Vacia()) {
    		e = cola.Primero();
    		cola.Desencolar();
    		if ((! Choca) && (! cola.Vacia())){
      		//Si choca vale true ya no seguimos comprobando, si esta vacia es la cabeza, que
      		//no puede chocar consigo misma
      		Choca = (Cabeza().x == e.x) && (Cabeza().y == e.y);
    		}
    		caux.Encolar(e);
  	}

  	while (! caux.Vacia()) {
    		e = caux.Primero();
    		caux.Desencolar();
    		cola.Encolar(e);
  	}

  	return Choca;
}
    
void Snake::Agrandar(){
	TPosicion nuevaCabeza;
	nuevaCabeza.x = Cabeza().x + v.x;
	nuevaCabeza.y = Cabeza().y + v.y;
	
	cola.Encolar(nuevaCabeza);//Metemos el elemento nuevo
}
