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

#ifndef __CLASE__TABLERO__ 
#define __CLASE__TABLERO__

#include <fstream>
#include <iostream>
#include <cstdlib>
#include "global.h"

using namespace std;


class Tablero{

	private:
    		//Atributos
    		TContenido m[MAX][MAX];

	public:
		Tablero(const char fichero[]); //carga el mapa del fichero
		~Tablero();
    		int GetDimension(); //obtiene el tamano maximo del tablero
    		void SetContenido(int x, int y, TContenido Contenido); //Establece el contenido de una posicion
		TContenido GetContenido(int x, int y); //obtiene el contenido de una posicion    
		void Refrescar(); //refresca el contenido vaciando los elementos no obstaculos
    		void ObtenerPosicionAleatoria(int &x, int &y); //Devuelve una posicion aleatoria valida del tablero
		
};
#endif
