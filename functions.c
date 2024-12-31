#include "functions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//logic ham
void printMenu(){
	system("cls");
	printf("***QUAN LY THU VIEN***\n");
	printf("\n");
	printf("\t-Menu-\n");
	printf("1.Nhap so luong va thong tin sach\n");
	printf("2.Hien thi sach\n");
	printf("3.Them sach\n");
	printf("4.Sua thong tin sach\n") ;
	printf("5.Xoa sach\n");
	printf("6.Tim kiem sach theo ten \n");
	printf("7.Sap xep theo gia tien\n");
	printf("8.Thoat\n");
} 
void saveBookToFile(struct Book book[], int n){
	getchar();
	int choice;
	FILE *fptr = fopen("libraryData.bin", "wb");
	if(fptr == NULL){
		printf("\033[31mError open file!!!\n");
		printf("PLEASE ENTER RANDOM KEYBOARD TO EXIT!!!\033[0m");
		getchar();
		return;
	}
	fwrite(book,sizeof(struct Book),n,fptr);
//	printf("\033[32mSave the file successfully!!!\033[0m");
	fclose(fptr);
//	printf("\nEnter '0' to Exit: ");
//	scanf("%d", &choice);
}
void format(char *name){
	size_t len=strlen(name);
	int newword=1;
	int i;
	for(i=0;i<len;i++){
		if(isspace(*(name+i))){
			newword=1;
		}
		else if(newword==1){
			*(name+i)=toupper(*(name+i));
			newword=0;
		}
		else{
			*(name+i)=tolower(*(name+i));
		}
	}
}

void libraryInput(struct Book **book,int *n){
	int back;
	do{
	system("cls");
	if(*book!=NULL){
		free(*book);
	}
	
	printf("Enter the number of books :");
	scanf("%d",n);
	if(*n<1){
		printf("Invalid number of book !\n");
		exit(1);
	}
	getchar();
	*book=(struct Book*)malloc(*n*sizeof(struct Book));
	if(*book==NULL){
		printf("Memory allocation failed !\n");
		exit(1);
	}
	int i;
	for (i=0;i<*n;i++){
		printf("Enter book %d-N:\n",i+1);
		printf("Enter book ID: ");
		scanf("%d", &(*book)[i].bookId);
		getchar(); 
		printf("Enter title book :");
		fgets((*book)[i].title,30,stdin);
		(*book)[i].title[strcspn((*book)[i].title,"\n")]='\0';
		format((*book)[i].title);
		printf("Enter price book:");
		scanf("%d",&(*book)[i].price);
		getchar();
		printf("Enter author book:");
		fgets((*book)[i].author,30,stdin);
		(*book)[i].author[strcspn((*book)[i].author,"\n")]='\0';
		format((*book)[i].author);
		printf("Enter publication date (dd mm yyyy): ");
        scanf("%d %d %d", &(*book)[i].publication.day, &(*book)[i].publication.month, &(*book)[i].publication.year);
		getchar();
		printf("\n");
		
	}
	printf("Press 0 to go back the main menu\n");
	scanf("%d",&back);
}while(back!=0);
	
}

void showLibrary(struct Book *book, int n) {
	int back;
	do{

	system("cls");
    printf("--------LIBRARY--------\n");
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    printf("| Book ID    | Title                        | Price           | Author                       | Publication Date    |\n");
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    int i;
    for (i = 0; i < n; i++) {
        printf("| %-10d | %-28s | %-15d | %-28s | %02d/%02d/%04d          |\n", 
               book[i].bookId, 
               book[i].title, 
               book[i].price, 
               book[i].author,
               book[i].publication.day, 
               book[i].publication.month, 
               book[i].publication.year);
        printf("--------------------------------------------------------------------------------------------------------------------\n");
    }
    printf("Press 0 to go back the main menu\n");
	scanf("%d",&back); 
	}while(back!=0);
}

void updateBook(struct Book *book,int n){
	int back;
	do{
	system("cls");   
	int flag=0;
	int i;
	int bookId;
	do{
	printf("Enter the ID of book:",n);
	scanf("%d",&bookId);
	getchar();
	flag=0;
	for(i=0;i<n;i++){
		if(book[i].bookId==bookId){
			flag=1;	
			printf("BOOK INFORMATION\n");
			printf("----------------\n");
			printf("Book ID:%d\n",book[i].bookId);
			printf("Book Title:%s\n",book[i].title);
			printf("Book price:%d\n",book[i].price);
			printf("Book author:%d/%d/%d\n",book[i].publication.day,book[i].publication.month,book[i].publication.year);
			printf("\n");
			printf("Update book:\n");
			printf("Update title of book :");
			fgets(book[i].title,30,stdin);
			book[i].title[strcspn(book[i].title,"\n")]='\0';
			format(book[i].title);
			printf("Enter price of book:");
			scanf("%d",&book[i].price);
			getchar();
			printf("Enter author book:");
			fgets(book[i].author,30,stdin);
			book[i].author[strcspn(book[i].author,"\n")]='\0';
			format(book[i].author);
			printf("Update book successfully!\n");
			break;
		}
	}
	if(flag==0){
		printf("This book does not exist!\n");
	}
	} while (flag==0);
	printf("Press 0 to go back the main menu\n");
	scanf("%d",&back);
}while (back!=0);
}

//void deleteBook(struct Book **book, int *n) {
//    int back;
//    do {
//        system("cls");
//        printf("Enter the ID of the book to delete: ");
//        int bookId;
//        scanf("%d", &bookId);
//        getchar();
//        int flag = 0;
//        int i, j;
//        for (i = 0; i < *n; i++) {
//            if ((*book)[i].bookId == bookId) {
//                for (j=i;j<*n - 1; j++) {
//                    (*book)[j]=(*book)[j + 1];
//                }
//                flag = 1;
//                (*n)--; 
//                *book = (struct Book*)realloc(*book, (*n) * sizeof(struct Book));
//                if (*book == NULL && *n > 0) {
//                    printf("Memory reallocation failed!\n");
//                    exit(1);
//                }
//                printf("Delete book successfully!\n");
//                break; 
//            }
//        }
//        if(flag==0) {
//            printf("This book does not exist.\n");
//        }
//        printf("Press 0 to go back to the main menu: ");
//        scanf("%d", &back);
//    } while (back != 0);
//}
void deleteBook(struct Book **book, int *n) {
    int back;
    do {
        system("cls");
        printf("Enter the ID of the book to delete: ");
        int bookId;
        scanf("%d", &bookId);
        getchar();
        int flag = 0;
        int i, j;
        for (i = 0; i < *n; i++) {
            if ((*book)[i].bookId == bookId) {
                flag = 1;
                printf("Are you sure you want to delete the book with ID %d? (y/n): ", bookId);
                char confirmation;
                scanf(" %c", &confirmation);
                if (confirmation=='y'||confirmation=='Y') {
                    for (j = i;j<*n-1;j++) {
                    (*book)[j] = (*book)[j + 1];
                    }
                    (*n)--;
                    *book = (struct Book*)realloc(*book, (*n) * sizeof(struct Book));
                    if (*book == NULL && *n > 0) {
                    printf("Memory reallocation failed!\n");
                    exit(1);
                    }
                    printf("Delete book successfully!\n");
                } else {
                    printf("Book deletion canceled.\n");
                }
                break;
            }
        }
        if (flag == 0) {
            printf("This book does not exist.\n");
        }
        printf("Press 0 to go back to the main menu or any other key to delete another book: ");
        scanf("%d", &back);
    } while (back != 0);
}

//void add_book(struct Book **book,int *n){
//	*n+=1;
//	*book=(struct Book *)realloc(*book,*n*sizeof(struct Book));
//	printf("Enter the location(0-%d):",*n);
//	int pos;
//	scanf("%d",&pos);
//	getchar();
//	if(pos==0){
//		pos=1;
//	}
//	if(pos<1||pos>*n){
//		printf("Invalid location!\n");
//		return;
//	}
//	for(int i=*n;i>=pos;i--){
//		book[i]=book[i-1];
//	}
//	printf("New book:\n");
//	(*book)[pos-1].code=*n+1000-1;
//	printf("Enter title of book :");
//	fgets((*book)[pos-1].title,30,stdin);
//	(*book)[pos-1].title[strcspn((*book)[pos-1].title,"\n")]='\0';
//	format((*book)[pos-1].title);
//	printf("Enter price of book:");
//	scanf("%d",&(*book)[pos-1].price);
//	getchar();
//	printf("Enter author book:");
//	fgets((*book)[pos-1].author,30,stdin);
//	(*book)[pos-1].author[strcspn((*book)[pos-1].author,"\n")]='\0';
//	format((*book)[pos-1].author);
//	printf("Add book successfully!\n");
//}

void addBook(struct Book **book, int *n) {
    int back;
    int i;
    do {
        system("cls");
        *n += 1;
        *book = (struct Book *)realloc(*book, *n * sizeof(struct Book));
        if (*book == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
        printf("Enter the location or 0 to go back to the main menu: ", *n);
        int pos;
        scanf("%d", &pos);
        getchar();
        if (pos == 0) {
            printf("Returning to the main menu...\n");
            return;
        }
        if (pos < 1 || pos > *n) {
            printf("Invalid location!\n");
            (*n)--;
            return;
        }
        for (i = *n - 1; i >= pos; i--) {
            (*book)[i] = (*book)[i - 1];
        }
        printf("New book:\n");
        (*book)[pos - 1].bookId = *n + 1000 - 1;
        printf("Enter title of book: ");
        fgets((*book)[pos - 1].title, 30, stdin);
        (*book)[pos-1].title[strcspn((*book)[pos - 1].title, "\n")] = '\0';
        format((*book)[pos-1].title);
        printf("Enter price of book: ");
        scanf("%d", &(*book)[pos-1].price);
        getchar();
        printf("Enter author book: ");
        fgets((*book)[pos-1].author,30,stdin);
        (*book)[pos - 1].author[strcspn((*book)[pos-1].author, "\n")] = '\0';
        format((*book)[pos - 1].author);
        printf("Add book successfully!\n");
        printf("Press 0 to go back to the main menu or any other key to add another book: ");
        scanf("%d", &back);
    } while (back != 0);
}

//void sortByPrice(struct Book)

