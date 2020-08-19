#include <iostream>
#include <cstdlib>
#include <fstream>
#include <limits>
#include "mystery_word.hpp"

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
				get_word<std::string>(std::cin, mystery_word);
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
** Return: The option choosen in the menu.
*/

int	menu()
{
	int	game_mode = 0;
	do
	{
		std::cout << "--MENU--\n1- Un joueur\n2- Deux joueurs\n3- Quitter\n";
		std::cout << "\nEntrez le chiffre correspondant à votre choix : ";
		get_word<int>(std::cin, game_mode);
		clear_terminal();
	}	while (game_mode < 1 || game_mode > 3);
	return (game_mode);
}

/*
** Loop while the player haven't found the mystery_word.
** - mystery_word: The string that contains the word to find.
*/

void	guess_loop(const std::string &mystery_word)
{
	std::string	mixed_word = rand_mix_string(mystery_word);
	std::string	assumed_word;
	while (1)
	{
		std::cout << "Quel est ce mot ? " << mixed_word << std::endl;
		get_word<std::string>(std::cin, assumed_word);
		if (assumed_word != mystery_word)
			std::cout << "Ce n'est pas le mot !\n";
		else
		{
			std::cout << "Bravo !\nAppuyez sur entrée pour retourner au menu.";
			std::cin.ignore();
			clear_terminal();
			break;
		}
	}
}

/*
** Create a shuffled string form the given string.
** <i> rand() need to be previously initialised with srand().
** - str: The string to mix.
** Return: The new randomly mixed string.
*/

const std::string	rand_mix_string(std::string str)
{
	std::string	mixed_str;
	while (str.size() > 0)
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
** Return: The randomly choosen word string.
*/

const std::string	rand_dictionary_word()
{
	std::ifstream	dictionary("dico.txt");
	if (!dictionary.is_open())
		exit_failure("dico.txt n'existe pas ou ne peut pas être ouvert");
	dictionary.seekg(0, std::ios::end);
	const int file_length = dictionary.tellg();
	if (file_length == 0)
		exit_failure("dico.txt est vide");
	dictionary.seekg(rand() % file_length, std::ios::beg);
	std::string	mystery_word;
	getline(dictionary, mystery_word); // Read a line to move the cursor at the beginning of an other.
	if (dictionary.eof()) // If eof, go back to first line.
		dictionary.seekg(0, std::ios::beg);
	if (dictionary.fail())
		dictionary.clear();
	get_word<std::string>(dictionary, mystery_word);
	return (mystery_word);
}

/*
** Execute the right system command depending on the OS to clear the terminal.
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
** Display an error message if given and close the program.
** - error_message: A string containing the message to print.
*/

void	exit_failure(const std::string &error_message)
{
	if (!error_message.empty())
		std::cout << "ERROR: " << error_message << '.' << std::endl;
	exit(1);
}