/*Faysal Khatri*/
/*06-19-2017*/


#include "map.h"
#include "mapobject.h"


/*accepts a pointer to an object_t and reads in data 
	from user to populate data of that object_t */
void get_object(object_t * obj) {
	char label[LABEL_LEN];  /*buffers for user input strings*/
	char xloc[5], yloc[5], speed[5], direction[5];  
	char type[8]; /*OBSTACLE is the longest type*/

	printf("Enter name of object: ");  fgets(label, LABEL_LEN, stdin);
	printf("Enter x location: ");  fgets(xloc, 15, stdin);
	printf("Enter y location: ");  fgets(yloc, 15, stdin);
	printf("Enter speed: ");  		fgets(speed, 15, stdin);
	printf("Enter direction: "); fgets(direction, 15, stdin);
	printf("Enter type: ");  	fgets(type, 9, stdin);
    
	strncpy(obj->label, label, LABEL_LEN);
	obj->xloc=atoi(xloc);
	obj->yloc=atoi(yloc);
	obj->speed=atof(speed);
	obj->direction=atoi(direction);
	obj->type=string_to_type(type); 
    
    print_object(obj);
}



void print_object(const object_t * obj){
	printf("%s", obj->label);
	printf("  Location: (%d, %d)", obj->xloc, obj->yloc);
	printf("  Speed: %3.2f", obj->speed);
	printf("  Direction: %d", obj->direction);
	printf("  Type: %s\n", stringFromType(obj->type));
}


char get_map_representation(object_type_t type) {
	char ret;
	char* str = stringFromType(type);
	
	if (strcmp(str, "CAR") == 0)
		ret = 'O';
	else if (strcmp(str, "TREE") == 0)
		ret = '*';
	else if (strcmp(str, "POLICE") == 0)
		ret = '#';
	else if (strcmp(str, "OBSTACLE") == 0)
		ret = 'X';
	else
		ret = -1;
	
	return ret;
}

object_type_t string_to_type(const char * type_string) {
	object_type_t ret;

	if ( (strncmp(type_string, "CAR", 3) == 0) || (strncmp(type_string, "car", 3) == 0) )
		ret = CAR;
	else if ( (strncmp(type_string, "TREE", 4) == 0) || (strncmp(type_string, "tree", 4) == 0) )
		ret = TREE;
	else if ( (strncmp(type_string, "POLICE", 6) == 0)  || (strncmp(type_string, "police", 6) == 0) ) 
		ret = POLICE;
	else if ( (strncmp(type_string, "OBSTACLE", 8) == 0) || (strncmp(type_string, "obstacle", 8) == 0) )
		ret = OBSTACLE;
	else
		ret = EMPTY;
	return ret;
}

	

char* stringFromType(object_type_t type)
{
	
	int intType = (int) type;
	
	switch (intType) {
		case 0: return "CAR"; break;
		case 1: return "TREE"; break;
		case 2: return "POLICE"; break;
		case 3: return "OBSTACLE"; break;
		default: return "EMPTY";
	}
	
}


