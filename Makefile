NAME = lem-in

#WWW = -Wall -Wextra -Werror

LIB_PATH = libft/
LIBFT = $(LIB_PATH)libft.a

FT_PRINTF_PATH = ft_printf
FT_PRINTF = $(FT_PRINTF_PATH)/libftprintf.a

OBJECTS = main.o \
            basic_function.o \
            init_room.o \
            validation.o \
            validation_rooms.o \
            validation_links.o \
            find_ways.o \

all: $(NAME)

libmk:
	make -C $(LIB_PATH)

ft_printfmk:
	make -C $(FT_PRINTF_PATH)

$(NAME): libmk ft_printfmk $(OBJECTS)
	gcc $(WWW) -o $(NAME) $(OBJECTS) $(LIBFT) $(FT_PRINTF)

%.o: %.c
	gcc  $(WWW) -o $@ -c $<

clean:
	#make -C $(LIB_PATH) clean
	#make -C $(FT_PRINTF_PATH) clean
	rm -f $(OBJECTS)

fclean: clean
	#rm -f $(LIBFT)
	#rm -f $(FT_PRINTF)
	rm -f $(NAME)

re: fclean all