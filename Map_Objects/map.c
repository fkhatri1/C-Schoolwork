/*Faysal Khatri*/
/*06-19-2017*/

#include<stdio.h>
#include<stdlib.h>

#include"map.h"
#include"mapobject.h"

int * map;
int width;
int height;

void add_to_map(int x, int y, char value) {
   map[(y * width) + x] = value;
}

void add_objects_to_map(const node_t * list)
{
    const node_t * curr;
    object_t * object;
    curr = list;

    while (curr != NULL) 
    {
      object = (object_t *) curr->data;
      add_to_map(
              object->xloc,
              object->yloc,
              object->type);
      curr = curr->next;
    }
}

void new_map(const node_t * list, int x, int y) {
    int rr, cc;

    width = x;
    height = y;
    map = malloc(sizeof(int) * width * height);
    for (rr=0;rr<height;rr++) 
        for (cc=0;cc<width;cc++) 
            map[(rr * width) + cc] = ' ';
    add_objects_to_map(list);
}


void print_map() {
    int rr, cc;
    char output;

    printf("Printing map:\n");
    for (rr=0;rr<height;rr++)  {
        for (cc=0;cc<width;cc++)  {
            output = get_map_representation(map[(rr * width) + cc]);
            if (output != -1) {
                printf("%c", output);
            }
            else {
                if ( (cc % 5 == 0) && (rr % 5 == 0)) {
                    printf("+");
                }
                else if (cc % 5 == 0) {
                    printf("|");
                }
                else if (rr % 5 == 0) {
                    printf("-");
                }
                else {
                    printf("%c", map[(rr * width) + cc]);
                }
            }
        }
        if (rr % 5 == 0) {
            printf("+\n");
        }
        else {
            printf("|\n");
        }
    }
}

