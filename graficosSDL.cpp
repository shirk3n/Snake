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

#include "graficosSDL.h"

GraficosSDL::GraficosSDL(){
	screen = NULL;
   	fondo = NULL;
   	pared = NULL;
   	cuerpo = NULL;
   	cabeza_arriba = NULL;
   	cabeza_abajo = NULL;
   	cabeza_derecha = NULL;
   	cabeza_izquierda = NULL;
   	manzana = NULL;
	gameover =NULL;
	soundtrack=NULL;
	cyber=NULL;
	
	

   	if (! Init())
      		exit(-1);
	

   	if (! LoadFiles())
      		exit(-1);
}

GraficosSDL::~GraficosSDL(){
	SDL_FreeSurface(screen);
	SDL_FreeSurface(fondo);
	SDL_FreeSurface(pared);
	SDL_FreeSurface(cuerpo);
	SDL_FreeSurface(cabeza_arriba);
	SDL_FreeSurface(cabeza_abajo);
	SDL_FreeSurface(cabeza_derecha);
	SDL_FreeSurface(cabeza_izquierda);
	SDL_FreeSurface(manzana);
	SDL_FreeSurface(gameover);
	Mix_FreeChunk(soundtrack);
	Mix_FreeChunk(cyber);

	
	SDL_Quit();
}

bool GraficosSDL::Init(){
	//Inicializacion de los subsistemas de SDL
    	if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ){
        	return false;
    	}

    	//Configuracion de la pantalla
    	screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_HWSURFACE );

    	//Error configurando la pantalla
    	if( screen == NULL ){
        	return false;
    	}
	
		//If there was in error in setting up the sound
    	if(Mix_OpenAudio(22050, AUDIO_S16, 2, 4096)) 
    	{ 
        return false;
    	} 
 
    	atexit(Mix_CloseAudio);

    	//Titulo de la pantalla
    	SDL_WM_SetCaption( "SHIRKEN'S SNAKE", NULL );

    	//Todo inicializado correctamente
    	return true;
}

SDL_Surface* GraficosSDL::load_image(string filename){
	//La imagen a cargar
    	SDL_Surface* loadedImage = NULL;

    	//La superficie optimizada que va a ser usada
    	SDL_Surface* optimizedImage = NULL;

    	//Carga la imagen
    	loadedImage = IMG_Load( filename.c_str() );

    	//Si la imagen ha cargado correctamente
    	if( loadedImage != NULL ){
        	//Crear la superficie optimizada
        	optimizedImage = SDL_DisplayFormat( loadedImage );

        	//Liberar la superficie antigua
        	SDL_FreeSurface( loadedImage );

        	//Si la superficie ha sido optimizada correctamente
        	if( optimizedImage != NULL ){
            		//El color-key de la superficie
            		SDL_SetColorKey( optimizedImage, SDL_RLEACCEL | SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format,255,0,0) );
	    		//RGB->rojo es el color que es transparente
        	}
    	}

    	//Devuelve la superficie optimizada
    	return optimizedImage;
}

bool GraficosSDL::LoadFiles() { //Carga de sonidos e imagenes
	soundtrack = Mix_LoadWAV("sonidos/soundtrack.wav");
	if ( soundtrack == NULL ) {	
        return false;
	}
	
	cyber = Mix_LoadWAV("sonidos/cyber.wav");
	if ( cyber == NULL ) 
	{	
        return false;
	}
	
	fondo = load_image("imagenes/fondo.png");
	if (fondo == NULL){
	    return false;
	}

	pared = load_image("imagenes/pared.png");
	if (pared == NULL){
	    return false;
	}

	cuerpo = load_image("imagenes/cuerpo.png");
	if (cuerpo == NULL){
	    return false;
	}

	cabeza_arriba = load_image("imagenes/cabeza_arriba.png");
	if (cabeza_arriba == NULL){
	    return false;
	}

	cabeza_abajo = load_image("imagenes/cabeza_abajo.png");
	if (cabeza_abajo == NULL){
	    return false;
	}
	cabeza_derecha = load_image("imagenes/cabeza_derecha.png");

	if (cabeza_derecha == NULL){
	    return false;
	}

	cabeza_izquierda = load_image("imagenes/cabeza_izquierda.png");
	if (cabeza_izquierda == NULL){
	    return false;
	}

	manzana = load_image("imagenes/manzana.png");
	if (manzana == NULL){
	    return false;
	}
	
	gameover = load_image("imagenes/gameover.png");
	if (gameover == NULL)
	{
	    return false;
	}

  	return true;
}

//Pinta diferentes imagenes dependiendo del contenido
bool GraficosSDL::DibujarContenidos(Tablero &t, Snake &s){
	bool result=false;
  
	for(int i=0; i<t.GetDimension(); i++){
		for(int j=0; j<t.GetDimension(); j++){
			switch(t.GetContenido(i,j)){
				case Vacio:
             				apply_surface( j*TILE_WIDTH, i*TILE_HEIGHT, fondo, screen, NULL);//pinta fondo
				break;
				case Obstaculo:
             				apply_surface( j*TILE_WIDTH, i*TILE_HEIGHT, pared, screen, NULL );//pinta pared
				break;
				case CuerpoS:
				     	apply_surface( j*TILE_WIDTH, i*TILE_HEIGHT, cuerpo, screen, NULL );//pinta cuerpo
				break;
				case CabezaS: 
            				switch(s.GetDireccion()){ //pinta cabezas
						case Arriba:
							apply_surface( j*TILE_WIDTH, i*TILE_HEIGHT, cabeza_arriba, screen, NULL);
						break;
						case Abajo:
							apply_surface( j*TILE_WIDTH, i*TILE_HEIGHT, cabeza_abajo, screen, NULL);
						break;
						case Derecha:
							apply_surface( j*TILE_WIDTH, i*TILE_HEIGHT, cabeza_derecha, screen, NULL);
	              				break;
						case Izquierda:
							apply_surface( j*TILE_WIDTH, i*TILE_HEIGHT, cabeza_izquierda, screen, NULL);
						break;
					}
				break;
				case Objetivo:
					apply_surface( j*TILE_WIDTH, i*TILE_HEIGHT, manzana, screen, NULL );//pinta manzana
				break;
			}
		}
	}

	if( SDL_Flip(screen) == -1 ){
     		result=true;
  	}
	return result;
}

void GraficosSDL::apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip){
	//Contiene los margenes
    	SDL_Rect offset;
    	//Obtiene los margenes
    	offset.x = x;
    	offset.y = y;
    	//Pinta en pantalla
    	SDL_BlitSurface( source, clip, destination, &offset );
}

void GraficosSDL::play_sound(Mix_Chunk *sonido, int milisegundos){
int ticks;
int channel;
		
		channel = Mix_PlayChannel(-1,sonido,0);
		
		ticks = SDL_GetTicks();
		while( SDL_GetTicks() < ticks + milisegundos)
			{
				//wait...    
			}
}

void GraficosSDL:: game_over(){
	Mix_HaltChannel(-1);
	
	apply_surface(0, 0, gameover, screen,NULL); //cargo en la pantalla la imagen de gameover
	
	if( SDL_Flip(screen) == -1 ){
			exit(-1);    
        }
	
	play_sound(cyber,2000);//ejecuto el sonido fin de partida
	
}

void GraficosSDL::SonidoAmbiente(){
	channel = Mix_PlayChannel(-1,soundtrack,-1);
}

