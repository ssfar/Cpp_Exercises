#ifndef MYSTERY_WORD_HPP
#define MYSTERY_WORD_HPP
#include <string>

const std::string	rand_mix_string(std::string str);
const std::string	rand_dictionary_word();
int					get_word(std::istream &stream, std::string &str);
int					get_int(std::istream &stream, int &value);
void				clear_terminal();
int					menu();
void				guess_loop(const std::string &mystery_word);
void				exit_failure(const std::string &error_message);
#endif