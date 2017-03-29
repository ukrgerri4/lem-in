#include "lem_in.h"

void    init_matrix(t_field *field)
{
    int i;
    int j;

    j = 0;
    field->matrix = (char**)malloc(sizeof(char*) * (field->size + 1));
    while (j < field->size)
    {
        i = 0;
        field->matrix[j] = (char*)malloc(sizeof(char) * (field->size + 1));
        ft_bzero(field->matrix[j], (size_t)(field->size + 1));
        j++;
    }
}

void validation_links(t_field *field, char *line)
{
    init_matrix(field); // create matrix

}
