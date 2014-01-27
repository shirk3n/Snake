Shirken's Snake
===============

To compile on Linux:

```
g++ principal.cpp graficosSDL.cpp snake.cpp manzana.cpp tablero.cpp -o snake -lSDL -lSDL_image -lSDL_mixer
````

To compile on OSX :

```
g++ -pg -I/Library/Frameworks/SDL.framework/Headers -I/Library/Frameworks/SDL_image.framework/Headers -I/Library/Frameworks/SDL_mixer.framework/Headers -I/Library/Frameworks/SDL_ttf.framework/Headers -g -o Serpiente main.cpp manzana.cpp snake.cpp tablero.cpp SDLMain.m -framework SDL -framework SDL_image -framework SDL_mixer -framework SDL_ttf -framework Cocoa
````

You need the SDL library, you can download it for free on their website:

http://www.libsdl.org/

In Linux you should install the following packages, or their newer versions:
libsdlimage1.2 libsdlimage1.2dev libsdlmixer1.2 libsdlmixer1.2dev libsdl1.2dev libsdl1.2debian libsdl1.2debianalsa libsmpegdev libsmpeg0
