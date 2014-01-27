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

#ifndef __CLASE__GRAFICOSSDL__
#define __CLASE__GRAFICOSSDL__

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h" 
#include "SDL/SDL_mixer.h"
#include "tablero.h"
#include "snake.h"
#include "global.h"

using namespace std;

/* Clase que utiliza la libreria SDL para pintar los contenidos en pantalla */

class GraficosSDL {

	private:
    		//Tipos - Ctes.
    		static const int SCREEN_WIDTH = 700;  //ancho ventana
    		static const int SCREEN_HEIGHT = 700; //alto ventana
    		static const int SCREEN_BPP = 32; //bits por pixel

    		static const int TILE_WIDTH = 28; //ancho cuadro
    		static const int TILE_HEIGHT = 28; //alto cuadro

    		//Atributos
    		SDL_Surface *screen;
    		SDL_Surface *fondo;
    		SDL_Surface *pared;
    		SDL_Surface *cuerpo;
    		SDL_Surface *cabeza_arriba;
    		SDL_Surface *cabeza_abajo;
    		SDL_Surface *cabeza_derecha;
    		SDL_Surface *cabeza_izquierda;
    		SDL_Surface *manzana;
		SDL_Surface *gameover;
		int channel;
		//sonido
		Mix_Chunk *soundtrack;
		Mix_Chunk *cyber;
    		//Metodos privados
    		SDL_Surface *load_image(string filename);
		void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip);
    		

  	public:
	
    		GraficosSDL();
    		~GraficosSDL();
    		bool Init(); //Inicializa el subsistema SDL
    		bool LoadFiles(); //Carga las imagenes para mostrar en pantalla
    		bool DibujarContenidos(Tablero &t, Snake &s); //Pinta las imagenes dependiendo del contenido
		void play_sound(Mix_Chunk *sonido, int milisegundos);
		void game_over();
		void SonidoAmbiente();	
};
#endif
