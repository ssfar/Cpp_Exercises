#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include "mystery_word.h"

int	main()
{
	srand(time(0));
	clear_terminal();
	while (1)
	{
		std::string	mystery_word;
		switch (menu())
		{
			case 1:
				mystery_word = rand_dictionary_word();
				break;
			case 2:
				std::cout << "Entre un mot : ";
				std::cin >> mystery_word;
				clear_terminal();
				break;
			case 3:
				return (0);
		}
		guess_loop(mystery_word);
	}
}

/*
** Display the game menu in a loop while the input of the user is not correct.
** Return : The option choosen in the menu.
*/

int	menu()
{
	int	game_mode;
	do
	{
		std::cout << "--MENU--\n1- Un joueur\n2- Deux joueurs\n3- Quitter\n";
		std::cout << "\nEntrez le chiffre correspondant à votre choix : ";
		std::cin >> game_mode;
		clear_cin();
		clear_terminal();
	}	while (game_mode < 1 || game_mode > 3);
	std::cin.clear();
	std::cin.ignore(2147483647, '\n');
	return (game_mode);
}

/*
** Loop while the player haven't found the mystery_word.
** - mystery_word : The string that contains the word to find.
*/

void	guess_loop(const std::string &mystery_word)
{
	std::string	mixed_word = rand_mix_string(mystery_word);
	std::string	assumed_word;
	while (1)
	{
		std::cout << "Quel est ce mot ? " << mixed_word << std::endl;
		std::cin >> assumed_word;
		if (assumed_word != mystery_word)
			std::cout << "Ce n'est pas le mot !\n";
		else
		{
			std::cout << "Bravo !\nAppuyez sur entrée pour retourner au menu.";
			std::cin.ignore();
			getline(std::cin, assumed_word);
			break;
		}
	}
	clear_terminal();
}

/*
** Create a shuffled string form the given string.
** <i> rand() need to be previously initialised with srand().
** - str : The string to mix.
** Return : The new randomly mixed string.
*/

std::string	rand_mix_string(std::string str)
{
	std::string	mixed_str;

	while (str.size() != 0)
	{
		int	pos = rand() % str.size();

		mixed_str += str[pos];
		str.erase(pos, 1);
	}
	return (mixed_str);
}

/*
** Pick a random word from dico.txt.
** <i> rand() need to be previously initialised with srand().
** Return : The randomly choosen word string.
*/

std::string	rand_dictionary_word()
{
	std::ifstream	dictionary("dico.txt");
	dictionary.seekg(0, std::ios::end);
	dictionary.seekg(rand() % dictionary.tellg(), std::ios::beg);
	std::string	mystery_word;
	getline(dictionary, mystery_word);
	if (dictionary.eof())
		dictionary.seekg(0, std::ios::beg);
	dictionary >> mystery_word;
	dictionary.close();
	return (mystery_word);
}

/*
** Execute the right system command deppending on the OS to clear the terminal.
*/

void	clear_terminal()
{
	#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
		system("clear");
	#elif defined(_WIN32) || defined(_WIN64)
		system("cls");
	#endif
}

/*
** Clear unwanted input form cin.
*/

void	clear_cin()
{
	while (!std::cin.good())
	{
		std::cin.clear();
		std::cin.ignore(2147483647, '\n');
	}
}