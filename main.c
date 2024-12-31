#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include "functions.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int choice;
	int n=0;
	struct Book *book=NULL;
	do{
		printMenu();
		printf("Enter yout choice: ");
		scanf("%d",&choice);
		switch(choice){
		case 1:
			libraryInput(&book,&n);
			saveBookToFile(book,n);
			printf("Add books to library successfully...\n");
			break;
		case 2:
			showLibrary(book,n);
			printf("Change book information complete...\n");
			break;
		case 3:
			addBook(&book,&n);
			saveBookToFile(book,n);
			break;
		case 4:
			updateBook(book,n);
			saveBookToFile(book,n);
			printf("Update information of books succesfully...\n");
			break;
		case 5:
			deleteBook(&book,&n);
			saveBookToFile(book,n);
			printf("Remove book succesfully...\n");
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			printf("DONE!!!");
			break;
			default:
				printf("Choose again!!!\n");
	}
	}while(choice!=8);
	return 0;
}
