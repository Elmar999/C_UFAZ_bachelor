#include <stdio.h>
#define NBMAX 100

typedef struct {
	int number;
	char author[30];
	char editor[30];
	char title[100];
	int stock;
} Typebook;

/*void newBook(FILE *db) {
	int order;
	Typebook blank = {0, "", "", "", 0};
	scanf ("%d", &order);
	if(order > 0 || order <= 100) {
		fseek(db, (order - 1) * sizeof(Typebook), SEEK_SET);
		fread (&blank, sizeof(Typebook), 1, db);
		if (blank.number != 0) printf("Account exists");
		else {
			scanf ("%s%s%s%d", blank.author, blank.editor, blank.title, &blank.stock);
			blank.number = order;
			fseek(db, (blank.number - 1) * sizeof(Typebook), SEEK_SET);
			fwrite(&blank, sizeof(blank), 1, db);
		}
	}
}*/

void printData( FILE *readPtr )
{  FILE *writePtr; /* accounts.txt file pointer */
   /* create clientData with default information */
   Typebook client = { 0, "", "", "", 0.0 };
   /* fopen opens the file; exits if file cannot be opened */
   if ( ( writePtr = fopen( "UFAZBooks.txt", "w" ) ) == NULL ) {
      printf( "File could not be opened.\n" );
   } /* end if */
   else { 
      rewind( readPtr ); /* sets pointer to beginning of file */
      /* copy all records from random-access file into text file */
      while ( !feof( readPtr ) ) { 
         fread( &client, sizeof( Typebook ), 1, readPtr );
         /* write single record to text file */
         if ( client.number != 0 ) {
            fprintf( writePtr, "%-6d%-16s%-11s%s%d\n",
               client.number, client.author,
               client.editor, client.title, client.stock );
         } /* end if */
      } /* end while */
      fclose( writePtr ); /* fclose closes the file */
   } /* end else */
} /* end function textFile */

/*void printData(FILE *db) {
	FILE *test;
	Typebook data = {0, "", "", "", 0};
	if((test = fopen("UFAZBooks.txt", "w"))==NULL) printf("File couldn't be open!");
	else {
		rewind(db);
		while(!feof(db)) {
			fread(&data, sizeof(data), 1, db);
			if (data.number != 0)
			fprintf(test, "%d%s%s%s%d\n", data.number, data.author, data.editor, data.title, data.stock);
		}
		fclose(db);
	}
}*/

void createData(FILE *db) {
		Typebook blank = {0, "", "", "", 0};
		for (int i = 1; i <= 100; ++i) {
			fwrite(&blank, sizeof(Typebook), 1, db);
		}
}

int main() {
	FILE *db;
	unsigned int option;
	printf("Option (1 to create a new database, 2 to use existing dtabase, 3 to exit) = ");
	scanf("%d", &option);
	if((db = fopen("UFAZLib.dat", "ab"))==NULL) printf("File couldn't be open!");
	else {
		while (option != 3) {
			if (option == 1)
				createData(db);
			if (option == 2) {
				printf("Option (1 to enter a new book, 2 delete a book, 3 to order a book, 4 to update information of a book, 5 to print all database in readable file, 6 to end options) = ");
				scanf("%d", &option);
				if (option == 5)
					printData(db);
				/*if (option == 1)
					newBook(db);
				if (option == 6)break;*/
			}
			printf("Option (1 to create a new database, 2 to use existing dtabase, 3 to exit) = ");
			scanf("%d", &option);
		}
	}
	return 0;
}
