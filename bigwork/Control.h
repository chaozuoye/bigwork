#pragma once
#include "Scene.h"
#include "SDL.h"
#include <map>
#include <string>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <filesystem>
namespace fs = std::filesystem;

/*to control the program*/
class Control {
private:
	int width, height;
	//��Ҫ��Ⱦ�Ĵ���
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	std::map<std::string, SDL_Texture*>Textures;
	std::map<int, TTF_Font* >Fonts;
	std::map<std::string, Mix_Chunk*>Sounds;
public:
	/*ctor,dtor*/
	Control(int _width, int _height);
	Control();
	~Control();
	void mainLoop();
	void putImage(std::string path, int x, int y, int width, int height);
	void playSound(std::string path, int cnt=1);
	void xyprintf(int x, int y, const char* c, int size);
	int rand();
	bool is_NoAarrow = true;
	bool is_NoWarrow = true;
	bool is_NoDarrow = true;
	void Initmypngs(fs::path strPath);
	void Initmywavs(fs::path strPath);
	SDL_Renderer* getRenderer();
	Scene* scene;
};

