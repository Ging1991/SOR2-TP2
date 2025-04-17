#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
 
void insert_substring(char*, char*, int);
char* substring(char*, int, int);
 
int main()
{
   char text[100], substring[100], position_str[50];
   int position;
   char *endptr;
 
   printf("Enter some text\n");
   fgets(text, sizeof(text), stdin);
   text[strcspn(text, "\n")] = '\0'; // Elimina el salto de línea si existe
 
   printf("Enter the string to insert\n");
   fgets(substring, sizeof(substring), stdin);
   substring[strcspn(substring, "\n")] = '\0'; // Elimina el salto de línea si existe
 
   printf("Enter the position to insert\n");
   fgets(position_str, sizeof(position_str), stdin);

   // Validar si se ingresó un número entero válido
   long pos_long = strtol(position_str, &endptr, 10);
   if (pos_long < INT_MIN || pos_long > INT_MAX) {
      printf("Error: El número entero está fuera del rango permitido.\n");
      return 1;
   }

   if (*endptr != '\n') {
      printf("Error: Lo ingresado no es un número entero válido.\n");
      return 1;
   }
   position = (int)pos_long;
   
   // Validación de la posición
   if (position < 1 || position > strlen(text)) {
      printf("Error: Posición inválida. Debe estar entre 1 y %ld.\n", strlen(text));
      return 1;  // Termina el programa con error
   }
 
   insert_substring(text, substring, position);
 
   printf("%s\n",text);
 
   return 0;
}
 
void insert_substring(char *a, char *b, int position)
{
   char *f, *e;
   int length;
 
   length = strlen(a);
 
   f = substring(a, 1, position - 1 );      
   e = substring(a, position, length-position+1);
 
   strcpy(a, "");
   strcat(a, f);
   free(f);
   strcat(a, b);
   strcat(a, e);
   free(e);
}
 
char *substring(char *string, int position, int length) 
{
   char *pointer;
   int c;
 
   pointer = malloc(length+1);
 
   if( pointer == NULL )
       exit(EXIT_FAILURE);
 
   for( c = 0 ; c < length ; c++ ) 
      *(pointer+c) = *((string+position-1)+c);       
 
   *(pointer+c) = '\0';
 
   return pointer;
}
