// Version of Jacob Sorber
// https://www.youtube.com/watch?v=2Ti5yvumFTU

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct {
	char name[MAX_NAME];
	int birth_year;
} person;

person *hash_table[TABLE_SIZE];

unsigned int hash(char *name) {
	unsigned int hash_value = 0;
	int length = strnlen(name, MAX_NAME);
	for (int i = 0; i < length; i++) {
		//printf("\t%c ", name[i]);
		hash_value += name[i];
		hash_value = (hash_value * name[i]) % TABLE_SIZE;
	}

	return hash_value;
}

// Nullify the table
void init_hash_table() {
	for (int i = 0; i < TABLE_SIZE; i++) {
		hash_table[i] = NULL;
	}
}

void print_table() {
	for (int i = 0; i < TABLE_SIZE; i++) {
		if (hash_table[i] == NULL) {
			printf("\t%i\t---\n", i);
		} else {
			printf("\t%i\t%s\n", i, hash_table[i]->name);
		}
	}
	printf("\n");
}

bool hash_table_insert(person *p) {
	if (p == NULL) return false;
	int hash_code = hash(p->name);
	if (hash_table[hash_code] != NULL) {
		return false;
	}
	hash_table[hash_code] = p;
	return true;
}

int main() {
	
	init_hash_table();
	print_table();
	person alan = {.name="Alan", .birth_year=1982};
	hash_table_insert(&alan);
	person melanie = {.name="Melanie", .birth_year=1990};
	hash_table_insert(&melanie);
	person jacob = {.name="Jacob", .birth_year=1997};
	hash_table_insert(&jacob);

	print_table();

	/*
	printf("Tony => %u\n", hash("Tony"));
	printf("Alan => %u\n", hash("Alan"));
	printf("Markus => %u\n", hash("Markus"));
	printf("James => %u\n", hash("James"));
	printf("Amelia => %u\n", hash("Amelia"));
	*/
	return 0;
}
