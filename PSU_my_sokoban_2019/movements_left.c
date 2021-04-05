/*
** EPITECH PROJECT, 2019
** movements_left.c
** File description:
** move_left
*/

void movements_to_left(char *buffer)
{
    int a = 0;
    int b = 0;
    static int c = 0;
    char keep_position;

    while (buffer[a] != 'P')
        a = a + 1;
    while (buffer[b] != 'O') {
        b = b + 1;
    }
    c = b;
    if (buffer[a - 1] == '#') {

    }
    else if (buffer[a - 1] == buffer[b]) {
        buffer[a] = ' ';
        buffer[a - 1] = 'P';
    }
    else if (buffer[a - 1] == 'X' && buffer[a - 2] == 'O') {
        buffer[a - 2] = buffer[a-+ 1];
        buffer[a - 1] = 'P';
        buffer[a] = ' ';
    }
    else if (buffer[a - 1] == 'X' && buffer[a - 2] == ' ') {
        keep_position = buffer[a - 2];
        buffer[a - 2] = buffer[a - 1];
        buffer[a - 1] = buffer[a];
        buffer[a] = keep_position;
    }
    else if (buffer[a - 1] == 'X' && buffer[a - 2] == 'X') {

    }
    else if (buffer[a - 1] != 'X' || buffer[a - 2] != 'O') {
        if (buffer[a - 1] == 'X' && buffer[a - 2] == '#') {

        }
        else {
            keep_position = buffer[a - 1];
            buffer[a - 1] = buffer[a];
            buffer[a] = keep_position;
        }
    }
    else {
        buffer[a - 2] = buffer[a - 1];
        buffer[a - 1] = buffer[a + 1];
    }
/*    if (buffer[a] == buffer[c])
      buffer[c] = 'P';
      if (buffer[a] != buffer[c])
      buffer[c] = 'O';*/
    // ne marche pas.
    // Il faut trouver un moyen de remettre 'O' quand
    // j'enlève 'P' de sa place initiale.
}
