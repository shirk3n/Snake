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

#include "manzana.h"

Manzana::Manzana(){
	h.x=0;
	h.y=0;
}

Manzana::~Manzana(){
	//no hace nada.
}

void Manzana::SetPosicion(int x, int y){ //Coloca la manzana aleatoriamente si es fondo
	h.x = x;
	h.y = y;
}

void Manzana::Dibujar(Tablero &t){
	t.SetContenido(h.x, h.y, Objetivo);
}

int Manzana::GetPosicionX(){
	return h.x;
}

int Manzana::GetPosicionY(){
	return h.y;
}

void Manzana::PosicionAleatoria(Tablero &t){
	int x, y; //Colocamos la manzana aleatoriamente
  	t.ObtenerPosicionAleatoria(x, y);
  	SetPosicion(x, y);
}
