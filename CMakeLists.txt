cmake_minimum_required(VERSION 3.6)
project(lem_in)

#include_directories(inc libft ft_printf) # part to include headers (or it may be included in your .h file)
link_directories(libft ft_printf) # part to include libraries

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.c lem_in.h validation.c basic_function.c libft/ft_error.c init_room.c validation_rooms.c validation_links.c find_ways.c trash.c reserve_ways.c) #
add_executable(lem_in ${SOURCE_FILES}) # include all *.c files to make binary

target_link_libraries(lem_in libft.a libftprintf.a) # include libraries