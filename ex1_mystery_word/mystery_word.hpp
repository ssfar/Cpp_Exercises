#ifndef MYSTERY_WORD_HPP
#define MYSTERY_WORD_HPP
#include <string>

const std::string	rand_mix_string(std::string str);
const std::string	rand_dictionary_word();
void				clear_terminal();
int					menu();
void				guess_loop(const std::string &mystery_word);
void				exit_failure(const std::string &error_message);

/*
** Read a line from the stream, and store a representation of the first, one or
** more characters followed by a space, a '\n' or an EOF into var.
** The representation deppend on the type of variable passed as argument.
** The rest of the line is then discarded.
** In case of an error, clear all flags of the stream.
** -stream: The stream to read from.
** -variable: The variable to stock the data read.
** Return:	0 in case of an error(stream can't be read or data can't be stored).
** 			1 if everything worked.
*/

template <typename T> 
int	get_word(std::istream &stream, T &var)
{
	int	valid = 1;
	stream >> var;
	if (stream.fail())
	{
		valid = 0;
		stream.clear();
	}
	stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return (valid);
}

#endif