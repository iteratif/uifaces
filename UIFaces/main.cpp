#include <Windows.h>
#include <fstream>
#include <string>
#include <cstdio>
#include <cerrno>
#include <time.h>

#include "ClassFactory.h"
#include "itString.h"
#include "itWindow.h"
#include "Game.h"
#include "MyView.h"

#define MAX_FRAME_RATE 120
#define MIN_FRAME_RATE 15
#define UPDATE_INTERVAL (1.0 / MAX_FRAME_RATE)
#define MAX_CYCLES_PER_FRAME (MAX_FRAME_RATE / MIN_FRAME_RATE)

std::string get_file_contents(const char *filename)
{
	/*std::FILE *fp = std::fopen(filename, "rb");
	if (fp)
	{
	std::string contents;
	std::fseek(fp, 0, SEEK_END);
	contents.resize(std::ftell(fp));
	std::rewind(fp);
	std::fread(&contents[0], 1, contents.size(), fp);
	std::fclose(fp);
	return(contents);
	}
	throw(errno);*/
	/*std::ifstream ifs("view.face");
	std::string content((std::istreambuf_iterator<char>(ifs)),
	(std::istreambuf_iterator<char>()));*/
	std::ifstream in(filename, std::ios::in | std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);

}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	REGISTER_VIEW(MyView)

	TCHAR pwd[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, pwd);

	itString path = pwd;
	itString baseUI = "\\base\\ui\\";
	itString viewPath = "view3.face";
	viewPath = path + baseUI + viewPath;

	itWindow win(800, 600);

	if (!win.Init()) return 1;
	
	Game game;
	game.init(win.GetHandle(), &(path + baseUI), 800, 600);
	game.loadContent(&viewPath);
	game.run();

	return 0;
}
