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

#ifndef __CLASE__MANZANA__ 
#define __CLASE__MANZANA__ 

#include "tablero.h"


using namespace std;

class Manzana{
	private:
    		//Tipos
		struct TPosicion{
			unsigned int x,y;
		};
    		//Atributos
		TPosicion h;
	
	public:
		Manzana();
		~Manzana();
		void SetPosicion(int x, int y);
    		int GetPosicionX();
    		int GetPosicionY();
    		void PosicionAleatoria(Tablero &t); //Genera una posicion aleatoria para la manzana
		void Dibujar(Tablero &t);
};
#endif
