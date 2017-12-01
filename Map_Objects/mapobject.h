/*Faysal Khatri*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LABEL_LEN 10

typedef enum {CAR, TREE, POLICE, OBSTACLE, EMPTY} object_type_t;

typedef struct {
	char label[LABEL_LEN];
	int xloc;
	int yloc;
	float speed;
	int direction;
	object_type_t type;
} object_t;

void get_object(object_t * obj);
void print_object(const object_t * obj);
char get_map_representation(object_type_t type);
object_type_t string_to_type(const char * type_string);
char* stringFromType(object_type_t type);