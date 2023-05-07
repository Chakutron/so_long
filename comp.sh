echo "Compiling \033[0;32mSO_LONG\033[0m .."
gcc -Wall -Wextra -Werror *.c gnl/*.c printf/libftprintf.a -o so_long -Lmlx -lmlx -Imlx -lX11 -lXext
