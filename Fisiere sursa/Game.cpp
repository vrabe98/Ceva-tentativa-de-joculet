#include "Game.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <conio.h>

extern Game game;

void Game::Read_file() {
	std::ifstream file("data.txt");
	std::string state_in, currline, currline2;
	while (std::getline(file, state_in)) {
		if (game.initState.empty()) {									//Initializeaza starea initiala a game-ului
			game.initState = state_in;
		}
		std::getline(file, game.states[state_in].descriere);			//Creeaza o noua stare in mapa starilor din game.
		currline.clear();												//Masura de siguranta. Curata streamul
		while (currline != ";") {										//Se citesc legaturile cu alte stari, din fisier
			std::getline(file, currline);								//Se citesc cate 2 linii, corespunzatoare optiunii si numelui
			std::getline(file, currline2);								//starii. Fisierul e formata astfel incat legaturile cu alte
			if (currline == ";")										//stari sunt urmate de 2 linii de ";".Se verifica daca ultima
				break;													//linie citita e ";", daca da se iese din bucla si se trece 
			else{														//la citirea unei alte stari.
				game.states[state_in].legatura[currline] = currline2;	
			}

		}
	}
}

/*
	Nota: in fisierul text, starile pot aparea oriunde, caci legaturile se fac indiferent daca starile exista sau nu. Daca nu exista,
vor fi create,odata cu legatura, daca exista, se creeaza doar legatura. Totul datorita template-ului map :)
	Starile se pot redefini, mai tarziu, in fisier, dar legaturile nu se rescriu, ci doar descrierea si doar se adauga starile
inexistente in mapa legaturilor. Cele existente raman.
*/

void Game::Play() {														//pretty self explanatory
	game.currState = game.initState;
	game.states[game.currState].DispState();
	while (game.currState != "Moarte") {
		game.states[game.currState].Changestate();
		game.states[game.currState].DispState();
	}
}
