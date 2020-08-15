#ifndef MYSTERY_WORD_H
#define MYSTERY_WORD_H
#include <string>
std::string	rand_mix_string(std::string str);
std::string	rand_dictionary_word();
void		clear_terminal();
void		clear_cin();
int			menu();
void		guess_loop(const std::string &mystery_word);
#endif