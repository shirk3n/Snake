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

#include "tablero.h"

//const int MAX = 25;

Tablero::Tablero(const char fichero[]){
  	int i,j;
  	int c;
	ifstream mapa;
  
	mapa.open(fichero);
	if (mapa.fail()) {
		cout << "error al abrir el mapa" << endl;
		exit(-1);
	}
	for(i=0;i<MAX;i++){
		for(j=0;j<MAX;j++){
			mapa >> c;
      			m[i][j] = (TContenido)c; //convierte de int a TContenido (Casting)
		}
	}
	mapa.close();
}

Tablero::~Tablero(){

}

void Tablero::SetContenido(int x, int y, TContenido Contenido){
	if ((x >= 0) && (x < MAX) && (y >= 0) && (y < MAX))
    		m[x][y] = Contenido;
}

TContenido Tablero::GetContenido(int x, int y){
	if ((x >= 0) && (x < MAX) && (y >= 0) && (y < MAX))
		return m[x][y];

  	return Obstaculo;
}

int Tablero::GetDimension(){
	return MAX;
}

void Tablero::Refrescar(){ //refresca cuando no hay obstaculos
	for (int i=0; i<MAX; i++){
		for(int j=0; j<MAX; j++){
			if(m[i][j]> Obstaculo) //No es un obstaculo
				m[i][j]=Vacio;
		}
	}
}

void Tablero::ObtenerPosicionAleatoria(int &x, int &y){
	do { 
		x=rand()%(MAX-1);
		y=rand()%(MAX-1);
    
  	}while (GetContenido(x, y) != Vacio);
}
		
