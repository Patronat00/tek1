/*
** EPITECH PROJECT, 2019
** movements_left.c
** File description:
** move_left
*/

void movements_to_left(char *buffer)
{
    int a = 0;
    char keep_position;

    while (buffer[a] != 'P')
        a = a + 1;
    if (buffer[a - 1] == '#') {
		
    }
    else if (buffer[a - 1] == 'X' && buffer[a - 2] == ' ') {
        keep_position = buffer[a - 2];
        buffer[a - 2] = buffer[a - 1];
        buffer[a - 1] = keep_position;
    }
    else if (buffer[a - 1] != 'X' || buffer[a - 2] != 'O') {
        if (buffer[a - 1] == 'X' && buffer[a - 2] == '#') {

        }
        else if (buffer[a] == 'P' && buffer[a - 1] == 'O') {
            buffer[a - 1] = ' ';
        }
        else {
            keep_position = buffer[a - 1];
            buffer[a - 1] = buffer[a];
            buffer[a] = keep_position;
        }
    }
    else if (buffer[a] == 'P' && buffer[a - 1] == 'X' && buffer[a - 2] == 'X') {

    }
    else {
        buffer[a - 2] = buffer[a - 1];
        buffer[a - 1] = buffer[a + 1];
    }
}
