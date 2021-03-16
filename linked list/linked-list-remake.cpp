#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// ==================== EDITOR ========================
/** 
 * Clone dari : https://github.com/fwwzali/data-structure.git
 * 
 * Mahasiswa :
 * 		Hamdan Yuwafi Mastu Wijaya
 * 		(19081010092 - Struktur Data B)
 * 
 * Riwayat Perubahan :
 * 		- Penulisan ulang source-code;
 * 		- Penambahan fitur:
 * 			- Tambah data di akhir list;
 * 			- Hapus data di akhir list;
 * 			- Cetak dengan reversi (pembalikan);
 *			- Hitung jumlah node.
 * 
 */

// ================= DECLARATIONS =====================

struct node {
	int data;
	struct node *next;
}; 
typedef struct node node;

// application interface.
int appMenu();
int addIntegerData();

// node operations.
node *createNode(void);
void addNode(node **head, node *previous, node *atarashii);
void deleteNode(node **head, node *previous, node *current);
void traverse(node *head);

// application feature.
void addStart(node **head);
void addMiddle(node **head);
void addEnd(node **head);
void deleteData(node **head);
void deleteEnd(node **head);
void printReversed(node *head);
void countNodes(node *head);

// will run while closing this app.
void deleteList(node *head);


// ============= APPLICATION MAIN APP =================
// ================= APPLICATIONS =====================

int main(int argc, char const *argv[])
{
	node *head;
	head = NULL;
	char option;

	Opties:
		option = appMenu();
		switch (option)
		{
			case 1:
				addStart(&head);
				printf("\n");
				goto Opties;
				break;

			case 2:
				addMiddle(&head);
				printf("\n");
				goto Opties;
				break;
			
			case 3:
				addEnd(&head);
				printf("\n");
				goto Opties;
				break;
			
			case 4:
				deleteData(&head);
				printf("\n");
				goto Opties;
				break;
			
			case 5:
				deleteEnd(&head);
				printf("\n");
				goto Opties;
				break;
			
			case 6:
				printf("\n");
				printReversed(head);
				printf("NULL\n\n");
				goto Opties;
				break;

			case 7:
				traverse(head);
				printf("\n");
				goto Opties;
				break;
			
			case 8:
				countNodes(head);
				printf("\n");
				goto Opties;
				break;
			
			default:
				goto Exit;
				break;
		}

	Exit:
		deleteList(head);	
		return 0;
}

// ============ APPLICATION INTERFACES ================
int appMenu() {
	int option;
	printf("Daftar pilihan\n");
	printf("1. Tambah data di awal\n");
	printf("2. Tambah data di tengah list\n");
	printf("3. Tambah data di akhir list\n");
	printf("4. Hapus data\n");
	printf("5. Hapus data di akhir list\n");
	printf("6. Cetak dengan reversi\n");
	printf("7. Cetak isi list\n");
	printf("8. Cetak panjang list\n");
	printf("Masukkan Pilihan [Pilih 1 s.d. 8] : ");
	// fflush(stdin);
	scanf("%d", &option);

	return option;
}

int addIntegerData() {
	int number;
	printf("Masukkan bilangan bulat: ");
	fflush(stdin);
	scanf("%d", &number);
	return number;
}


// ================ NODE OPERATIONS ===================
node *createNode(void) {
	node *pointer;

	pointer = (node *)malloc(sizeof(node));
	return pointer;
}

void addNode(node **head, node *previous, node *atarashii) {
	if (previous == NULL) {
		// Add new chain at the beginning.
		atarashii->next = *head;
		*head = atarashii;
	} else {
		// Add new chain at the end.
		atarashii->next = previous->next;
		previous->next = atarashii;
	}
}

void deleteNode(node **head, node *previous, node *current) {
	if (previous == NULL)
		*head = current->next;
	else
		previous->next = current->next;
	
	// Remove current node.
	free(current);
}

void traverse(node *head) {
	node *walkerPointer;
	walkerPointer = head;
	printf("\n");
	while (walkerPointer != NULL) {
		printf("%d -> ", walkerPointer->data);
		walkerPointer = walkerPointer->next;
	}
	printf("NULL\n");
}

// ============= APPLICATION FEATURES =================
void addStart(node **head) {
	int number;
	node *newPointer;
	number = addIntegerData();
	newPointer = (node *)malloc(sizeof(node));

	if (newPointer != NULL) {
		newPointer->data = number;
		newPointer->next = NULL;
		addNode(head, NULL, newPointer);
	} else {
		printf("\nAlokasi memori gagal.\n");
	}
}

void addMiddle(node **head) {
	int position, number;
	node *newPointer, *currentPointer;

	traverse(*head);
	printf("\nSisipkan sesudah data bernilai: ");
	fflush(stdin);
	scanf("%d", &position);

	number = addIntegerData();
	currentPointer = *head;
	
	while (currentPointer != NULL 
		&& currentPointer->data != position)
	{
		currentPointer = currentPointer->next;
	}

	newPointer = (node *)malloc(sizeof(node));

	if (currentPointer == NULL) {
		printf("\nNode tidak ditemukan.\n");
	} else if (newPointer == NULL) {
		printf("\nAlokasi memori gagal.\n");
	} else {
		newPointer->data = number;
		newPointer->next = NULL;
		addNode(head, currentPointer, newPointer);
	}
}

void addEnd(node **head) {
	int number;
	node *newPointer, *currentPointer;

	printf("Tambahkan data pada akhir chain.\n");
	number = addIntegerData();

	currentPointer = *head;
	newPointer = (node *)malloc(sizeof(node));

	newPointer->data = number;
	newPointer->next = NULL;

	if (currentPointer == NULL) {
		currentPointer = newPointer;
		return;
	}

	while (currentPointer->next != NULL)
		currentPointer = currentPointer->next;
		
	currentPointer->next = newPointer;
	return;
}

void deleteData(node **head) {
	int number;
	node *previousPointer, *currentPointer;

	traverse(*head);
	printf("Penelusuran data yang akan dihapus.\n");
	number = addIntegerData();

	currentPointer = *head;

	while (currentPointer != NULL
		&& currentPointer->data != number)
	{
		previousPointer = currentPointer;
		currentPointer = currentPointer->next;
	}
	
	if (currentPointer == NULL) {
		printf("\nNode tidak ditemukan.\n");
	} else {
		deleteNode(head, previousPointer, currentPointer);
	}
}

void deleteEnd(node **head) {
	node *currentPointer, *doubleNextPointer;

	printf("Menghapus chain terakhir...\n");

	currentPointer = *head;
	doubleNextPointer = currentPointer->next->next;

	while (doubleNextPointer != NULL) {
		currentPointer = currentPointer->next;
		doubleNextPointer = currentPointer->next->next;
	}

	delete doubleNextPointer;
	currentPointer->next = NULL;
}

void printReversed(node *head) {
	if (head == NULL) return;

	printReversed(head->next);
	printf("%d -> ", head->data);
	
	// node *currentPointer = head, 
	// 	*previousPointer = NULL, 
	// 	*nextPointer = NULL;
	
	// while (currentPointer != NULL) {
	// 	nextPointer = currentPointer->next;
	// 	currentPointer->next = previousPointer;
	// 	previousPointer = currentPointer;
	// 	currentPointer = nextPointer;
	// }
	
	// head = previousPointer;
	// return head;
}

void countNodes(node *head) {
	node *walkerPointer;
	int length = 0;
	walkerPointer = head;
	printf("\n");
	while (walkerPointer != NULL) {
		length++;
		walkerPointer = walkerPointer->next;
	}
	printf("%d\n", length);
}

// ============= APPLICATION CLOSING ==================
void deleteList(node *head) {
	node *temporaryPointer;

	while (head != NULL) {
		temporaryPointer = head;
		head = head->next;
		free(temporaryPointer);
	}
}
