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

#ifndef __CLASE__SNAKE__ 
#define __CLASE__SNAKE__ 

#include <iostream>
#include "cola.hpp"
#include "manzana.h"
#include "tablero.h"
#include "global.h"

using namespace std;
	
class Snake {
	private:
    		//Tipos
		struct TPosicion{
			int x,y;
		};

    		//Atributos
		CCola<TPosicion> cola;
		TPosicion v;  //vector velocidad
    
	public:
  
		Snake();
		~Snake();
		TPosicion Cabeza(); 
		TPosicion Rabo(); 
		void Mover(); //Actualiza la serpiente en funcion de su vector velocidad		
		void SetVelocidad(int vx, int vy);
		int GetVelocidadX();
		int GetVelocidadY();
    		TDireccion GetDireccion();    
    		void Dibujar(Tablero &t);
    		bool Come(Manzana &m);
    		bool Choca(Tablero &t);
    		bool ChocaSiMisma();
    		void Agrandar();
};
#endif
