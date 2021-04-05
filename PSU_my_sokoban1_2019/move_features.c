/*
** EPITECH PROJECT, 2019
** move_features.c
** File description:
** moving O and X
*/

int lenght_line(char *buffer);

void movements_features_to_right(char *buffer)
{

    int a = 0;
    char keep_position;

    while (buffer[a] != 'Z')
        a = a + 1;
    if (buffer[a + 1] == '#') {

    }
    else if (buffer[a + 1] == 'X' && buffer[a + 2] == ' ') {
        keep_position = buffer[a + 2];
        buffer[a + 2] = buffer[a + 1];
        buffer[a + 1] = keep_position;
    }
    else if (buffer[a + 1] == 'X' && buffer[a + 2] == 'O') {
        buffer[a + 2] = buffer[a + 1];
        buffer[a + 1] = buffer[a - 1];
    }
    else {
        keep_position = buffer[a + 1];
        buffer[a + 1] = buffer[a];
        buffer[a] = keep_position;
    }
}

void movements_features_to_left(char * buffer)
{
    int a = 0;
    char keep_position;

    while (buffer[a] != 'Z')
        a = a + 1;
  /*  if (buffer[a - 1] == '#') {

    }*/
    if (buffer[a - 1] == 'X' && buffer[a - 2] == ' ') {
        keep_position = buffer[a - 2];
        buffer[a - 2] = buffer[a - 1];
        buffer[a - 1] = keep_position;
    }
    else if (buffer[a - 1] == 'X' && buffer[a - 2] == 'O') {
        buffer[a - 2] = buffer[a - 1];
        buffer[a - 1] = buffer[a + 1];
    }
    else {
        keep_position = buffer[a - 1];
        buffer[a - 1] = buffer[a];
        buffer[a] = keep_position;
    }
}

void movements_features_to_down(char *buffer)
{
    int a = 0;
    char keep_position;
    char lenght;

    while(buffer[a] != 'Z')
        a = a + 1;
    lenght = lenght_line(buffer);
    /*if (buffer[lenght + a + 1] == '#') {

    }*/
    if(buffer[lenght + a + 1] == 'X' && buffer[lenght + a + 2] == ' ') {
        keep_position = buffer[lenght + a + 2];
        buffer[lenght + a + 2] = buffer[lenght + a + 1];
        buffer[lenght + a + 1] = keep_position;
    }
    else if (buffer[lenght + a + 1] == 'X' && buffer[lenght + a + 2] == 'O') {
        buffer[lenght + a + 2] = buffer[lenght + a + 1];
        buffer[lenght + a + 1] = ' ';
    }
    else {
        keep_position = buffer[a];
        buffer[a] = buffer[lenght + a + 1];
        buffer[lenght + a + 1] = keep_position;
    }
}

void movements_features_to_up(char *buffer)
{
    int a = 0;
    char keep_position;
    char lenght;

    while(buffer[a] != 'Z')
        a = a + 1;
    lenght = lenght_line(buffer);
    /*if (buffer[a - lenght - 1] == '#') {

    }*/
    if(buffer[a - lenght - 1] == 'X' && buffer[a - lenght - 1] == ' ') {
        keep_position = buffer[a - lenght - 2];
        buffer[a - lenght - 2] = buffer[a - lenght - 1];
        buffer[a - lenght - 1] = keep_position;
    }
    else if(buffer[a - lenght - 1] == 'X' && buffer[a - lenght - 2] == 'O') {
        buffer[a - lenght - 2] = buffer[a - lenght - 1];
        buffer[a - lenght - 1] = ' ';
    }
    else {
        keep_position = buffer[a];
        buffer[a] = buffer[a - lenght - 1];
        buffer[a - lenght - 1] = keep_position;
    }
}