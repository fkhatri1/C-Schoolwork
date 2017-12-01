/*Faysal Khatri*/
/*06-19-2017*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"mapobject.h"
#include"map.h"
#include"basiclist.h"

#define BUFFERLEN 100

object_t * object_from_string(char * buff) {
    object_t * ret = malloc(sizeof(object_t));
    char * tok = strtok(buff, ",");
    printf("ENTRY : ");
    if(tok != NULL) {
        strncpy(ret->label, tok, LABEL_LEN);
        ret->xloc=atoi(strtok(NULL, ","));
        ret->yloc=atoi(strtok(NULL, ","));
        ret->speed=atof(strtok(NULL, ","));
        ret->direction=atof(strtok(NULL, ","));
        ret->type=string_to_type(strtok(NULL, ","));
    }
    print_object(ret);
    return ret;
}

void read_objects(node_t ** object_list) {

    FILE *fp;
    char buffer[BUFFERLEN];
    fp = fopen("objects.txt", "r");

    while (fgets(buffer, BUFFERLEN,fp)) {
        list_add(object_from_string(buffer), object_list);
    }
}

void print_objects(const node_t * start) {
	const node_t * curr;
    curr = start;

    while (curr != NULL)  {
		print_object((object_t *) curr->data);
		curr = curr->next;
    }
}

void find_all_of_type(const node_t * start, object_type_t target) {
	const node_t * curr;
	char *strTarget = stringFromType(target);
	object_t *currObj;
    curr = start;

    while (curr != NULL)  {
		currObj = (object_t *) curr->data;
		if (strcmp(strTarget, stringFromType(currObj->type)) == 0) {
			print_object(currObj);
		}
		curr = curr->next;
    }
}

void find_object(const node_t * start, const char * target) {
	const node_t * curr;
	object_t *currObj;
    curr = start;

    while (curr != NULL)  {
		currObj = (object_t *) curr->data;
		if (strcmp(target, currObj->label) == 0) {
			print_object(currObj);
			return;
		}
		curr = curr->next;
    }
	
	printf("Object with name %s not found\n", target);
}

int main ()
{
    
	node_t * object_list = NULL;
	int nObj = 0;
	
	printf("Student: Faysal Khatri\n");
	
	/* Read in Sample Data */
    read_objects(&object_list);
	
	/* Create some new objects from User input */
	for (nObj = 0; nObj < 2; nObj++) {
		object_t * newObj = malloc(sizeof(object_t));
		get_object(newObj);
		list_add(newObj, &object_list);
	}

    new_map(object_list, 30,16);
	
	
    print_map();

    printf("\nprint_objects():\n");
    print_objects(object_list);

    printf("\nfind_all_of_type(CAR):\n");
    find_all_of_type(object_list, CAR);

    printf("\nfind_object(RedCar):\n");
    find_object(object_list, "RedCar");
	printf("Student: Faysal Khatri\n");
    return 0;
}

