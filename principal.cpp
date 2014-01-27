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
#include <fstream>
#include <string>
#include <cstdlib>

#include "tablero.h"
#include "manzana.h"
#include "snake.h"
#include "graficosSDL.h"
#include "global.h"

using namespace std;

//Ctes.
const int FRAMES_PER_SECOND = 25; //velocidad de refresco

//Prototipos
bool Input(Snake &serpiente);
bool Procesar(Tablero &t, Snake &s, Manzana &m);
bool Dibujar(GraficosSDL &gSDL, Tablero &t, Snake &s, Manzana &m);

/***************************************************************************************/

/***************************************************************************************
        PROGRAMA PRINCIPAL : SNAKE
****************************************************************************************/

int main(int argc, char* args[]){
	int ticks;
  	GraficosSDL gSDL;
	Tablero t("s.map");
	Snake serpiente;
	Manzana manzana;
 	bool quit=false;
	
	gSDL.SonidoAmbiente();
  	manzana.PosicionAleatoria(t);
  	
	while(! quit){
		
		quit = Input(serpiente); //Controla la entrada de teclado
    		if (! quit) {
      			quit = Procesar(t, serpiente, manzana); //Procesamos (actualizar, colisiones)
      			if (! quit) {
        			if (! Dibujar(gSDL, t, serpiente, manzana)) //Mostramos el contenido
		        		exit(-1);
      			}
		}

		ticks = SDL_GetTicks();
		while( SDL_GetTicks() < ticks+(1000 / FRAMES_PER_SECOND) ) //tiempo de refresco
		{
			
		}
	}
		
	gSDL.game_over();
		
	return 0;
}


/* Controla la entrada de teclado del usuario
****************************************************************************************/
bool Input(Snake &serpiente){
	bool result = false;
   	SDL_Event event;

   	if( SDL_PollEvent( &event ) ){ //Recogemos el evento
    		if( event.type == SDL_KEYDOWN ){ //Se ha pulsado una tecla
              		switch( event.key.keysym.sym ){
				case SDLK_ESCAPE:
					result = true; //Escape: Salimos del programa
                                  break;
				case SDLK_UP:
					serpiente.SetVelocidad(-1, 0);
		    		break;
                		case SDLK_DOWN: 
					serpiente.SetVelocidad(1, 0);
                  		break;
                		case SDLK_LEFT:
					serpiente.SetVelocidad(0, -1);
		    		break;
          			case SDLK_RIGHT: 
					serpiente.SetVelocidad(0, 1);
                                 break;
			}
				
		}else if( event.type == SDL_QUIT ){
            		//Se quita el programa
             		result = true;
        	}
  	}

  	return result;	
}

/***************************************************************************************/


/* Procesa un cuadro de ejecucion del programa: actualiza, detecta colisiones...
****************************************************************************************/

bool Procesar(Tablero &t, Snake &s, Manzana &m){
	bool result = false;
    	s.Mover(); //Movemos la serpiente a la nueva posicion

    	//Comprobamos colisiones
    	if (s.Come(m)) {
      		//La serpiente colisiona con la manzana
      		s.Agrandar();
      		m.PosicionAleatoria(t);      
    	}

    	if ((s.Choca(t)) || (s.ChocaSiMisma())) {
      		//La serpiente choca con el tablero
      		result = true; //Fin de la partida
    	}

    	return result;
}

/***************************************************************************************/


/* Actualiza el contenido del tablero y lo dibuja en pantalla
****************************************************************************************/

bool Dibujar(GraficosSDL &gSDL, Tablero &t, Snake &s, Manzana &m){
	gSDL.DibujarContenidos(t,s);
	t.Refrescar();
  	s.Dibujar(t);
  	m.Dibujar(t);
  	return (!gSDL.DibujarContenidos(t, s));
}

