#pragma once
#include <string>
#include <map>
#include "State.h"

class Game
{
	std::string initState;						//starea initiala
public:
	std::string currState;						//starea curenta
	std::map<std::string, State>   states;		//fiecare game are un anumit numar de stari, ce pot fi accesate printr-o denumire
	void Read_file();
	void Play();
};

