# get_next_line
The aim of this project is to make you code a function that returns a line ending with a newline, read from a fd.

Usage:
get next line is a function that reads a file line by line

Return value:
return 1 when it read a line
return 0 when it finished reading a file
return -1 when an error occurs

How do I use it?
1) Download/clone this repo: 
git clone https://github.com/Oksanatishka/get_next_line
2) Get into it and build the library: 
cd get_next_line
make -C libft/
3) Build the executable: 
gcc -Wall -Wextra -Werror -I./libft/includes/ -L./libft -lft -o gnl get_next_line.c main.c

-I tells the compiler where your library header files are. ./libft/includes/ in this case
-L tells it where your library resides. ./libft here
-l takes the name of your library. This is the set of characters that come after lib in your library name.
4) Test it with: 
./gnl m83.txt
It should read the whole file to you. Kinda like a basic cat implementation.
