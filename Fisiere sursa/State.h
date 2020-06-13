#pragma once
#include <string>
#include <map>
class State
{	
	friend class Game;									//Game e friend pentru a nu rescrie tot codul
	std::string descriere;								//Descrierea starii
	std::map<std::string, std::string> legatura;		//Legaturile starii cu alte stari (accesibile printr-un nume). Primul string
public:													//e textul optiunii ce apare pe ecran, pentru a trece in alta stare.
	void Changestate();
	void DispState();
	std::string GetOption(std::string);
};

