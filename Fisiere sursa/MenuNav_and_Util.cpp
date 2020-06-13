#include "Game.h"
#include "MenuNav_and_Util.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>

extern Game game;

void NewGame() {
	game.Read_file();
	game.Play();
}

void Menu(){
	system("cls");
	int opt = 0;
	std::cout << "1.Joc nou\n2.Iesi din joc\n";
	std::cin >> opt;
	switch (opt) {
	case 1:
		NewGame();
		break;
	case 2: {
		exit(0);
		std::cout << "Jocul se va inchide imediat.";
	}
			break;
	}
}

void StartScreen() {										//Se citeste si afiseaza splash screenul.
	std::ifstream file("splash.txt");
	std::string line;
	while (std::getline(file, line))
		std::cout << line<<"\n";
	_getch();
}

std::string WordWrap(std::string text) {						/*Introduce spatii suplimentare in string, pentru ca toate cuvintele
																sa fie afisate pe o linie fiecare, nu separate*/
	int k = text.length() / 80;									//Fereastra consolei e de 80 de caractere, default.
	for (int i = 1; i <= k; i++, k = text.length() / 80) {
		if (((text[80 * i - 1] != ' ') || (text[80 * i] != ' ')) && (text[80 * i + 1] != '\n')) {
			int char_back = 0;
			do {
				char_back++;
				if (text[80 * i - char_back - 1] == ' ') {
					for (int cont = 0; cont < char_back; cont++) {
						text.insert(80 * i - char_back - 1, " ");
					}
					char_back = 0;
					break;
				}
			} while (text[80 * i - char_back - 1] != ' ');
		}
	}
	return text;
}

