// main.cpp
#include <iostream>

#include <glad/glad.h>
#include <SDL2/SDL.h>
#include <FreeImagePlus.h>

int main() {
  std::cout << "Hello, Welcome to my todos!!" << std::endl;

  if (SDL_Init(SDL_INIT_VIDEO) != 0){
    std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
    return 1;
  }

  // Init FreeImage
  FreeImage_Initialise(true);
  
  SDL_Quit();
  
  return 0;
}

