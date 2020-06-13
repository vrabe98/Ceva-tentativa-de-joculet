#include "State.h"
#include "Game.h"
#include "MenuNav_and_Util.h"
#include <iostream>
#include <string>
#include <map>
#include <fstream>

extern Game game;

std::string State::GetOption(std::string text) {
	std::string text2;
	std::cout << text;														//Ramasita dintr-o versiune de test, am lasat-o din lene.
	text2 = game.states[game.currState].legatura.lower_bound(text)->first;	//Cauta o stare ce incepe cu caracterele introduse
	return text2;															//de utilizator.
}

void State::Changestate() {								//Trece la alta stare, specificata de optiunea utilizatorului.
	std::string nextstate;
	fflush(stdin);
	std::cin >> nextstate;
	nextstate = GetOption(nextstate);					//Cauta starea specificata de utilizator
	game.currState = game.states[game.currState].legatura[nextstate];	//Trece la starea urmatoare, cautata si gasita anterior.
}

void State::DispState() {			//Afiseaza textul starii curente, cu ceva formatare in plus, ca sa arate mai bine.
	system("cls");
	std::cout << "---------------------------//---------------------------\n" << WordWrap("		" + game.currState + "\n") << WordWrap(" " + descriere + "\n\n");
	for (std::map<std::string, std::string>::iterator it = legatura.begin(); it != legatura.end(); ++it) {
		std::cout << "-" << it->first << "\n";
	}
}
