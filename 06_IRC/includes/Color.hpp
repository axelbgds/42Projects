#ifndef COLOR_HPP
# define COLOR_HPP

# define RESET   "\033[0m"

// USAGE 

// std::cout << COLOR << BACKGROUND << your text << RESET << std::endl;

// BACKGROUND

# define ON_BLACK	";40m"
# define ON_RED		";41m"
# define ON_GREEN 	";42m"
# define ON_YELLOW	";43m"
# define ON_BLUE	";44m"
# define ON_MAGENTA	";45m"
# define ON_CYAN	";46m"
# define ON_WHITE	";47m"

# define ON_BRIGHT_BLACK 	";100m" // == grey
# define ON_BRIGHT_RED		";101m"
# define ON_BRIGHT_GREEN 	";102m"
# define ON_BRIGHT_YELLOW	";103m"
# define ON_BRIGHT_BLUE		";104m"
# define ON_BRIGHT_MAGENTA	";105m"
# define ON_BRIGHT_CYAN		";106m"
# define ON_BRIGHT_WHITE	";107m"

// COLORS

# define BLACK		"\033[30"
# define RED		"\033[31"
# define GREEN		"\033[32"
# define YELLOW		"\033[33"
# define BLUE		"\033[34"
# define MAGENTA	"\033[35"
# define CYAN		"\033[36"
# define WHITE		"\033[37"

# define BRIGHT_BLACK 	"\033[90" // == grey
# define BRIGHT_RED		"\033[91"
# define BRIGHT_GREEN 	"\033[92"
# define BRIGHT_YELLOW	"\033[93"
# define BRIGHT_BLUE	"\033[94" 
# define BRIGHT_MAGENTA	"\033[95"
# define BRIGHT_CYAN	"\033[96"
# define BRIGHT_WHITE	"\033[97"

// OTHERS

# define UNDERLINE			"\033[4m"
# define DOUBLE_UNDERLINE	"\033[21m"
# define NOT_UNDERLINE		"\033[24m"
# define ITALIC				"\033[3m"
# define NOT_ITALIC			"\033[23m"

#endif