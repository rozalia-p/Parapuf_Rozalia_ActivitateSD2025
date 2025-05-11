#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StructuraFilm {
	int id;
	int anLansare;
	float rating;
	char* titlu;
	char* regizor;
	char gen;
};
typedef struct StructuraFilm Film;

void afisareFilm(Film f) {
	printf("ID: %d\n", f.id);
	printf("An lansare: %d\n", f.anLansare);
	printf("Rating: %.1f\n", f.rating);
	printf("Titlu: %s\n", f.titlu);
	printf("Regizor: %s\n", f.regizor);
	printf("Gen: %c\n\n", f.gen);
}

void afisareVectorFilme(Film* filme, int nrFilme) {
	for (int i = 0; i < nrFilme; i++) {
		afisareFilm(filme[i]);
	}
}

void adaugaFilmInVector(Film** filme, int* nrFilme, Film filmNou) {
	Film* aux = (Film*)malloc(sizeof(Film) * ((*nrFilme) + 1));
	for (int i = 0; i < *nrFilme; i++) {
		aux[i] = (*filme)[i];
	}
	aux[*nrFilme] = filmNou;
	free(*filme);
	*filme = aux;
	(*nrFilme)++;
}

Film citireFilmFisier(FILE* file) {
	Film f;
	char buffer[256];
	char sep[4] = ",;\n";

	fgets(buffer, 256, file);
	if (strlen(buffer) < 5) { // linie goală
		f.id = -1;
		return f;
	}

	f.id = atoi(strtok(buffer, sep));
	f.anLansare = atoi(strtok(NULL, sep));
	f.rating = atof(strtok(NULL, sep));

	char* aux = strtok(NULL, sep);
	f.titlu = (char*)malloc(strlen(aux) + 1);
	strcpy(f.titlu, aux);

	aux = strtok(NULL, sep);
	f.regizor = (char*)malloc(strlen(aux) + 1);
	strcpy(f.regizor, aux);

	f.gen = strtok(NULL, sep)[0];

	return f;
}

Film* citireVectorFilmeFisier(const char* numeFisier, int* nrFilmeCitite) {
	FILE* file = fopen(numeFisier, "r");
	if (!file) {
		printf("Eroare la deschiderea fisierului.\n");
		return NULL;
	}
	Film* filme = NULL;
	*nrFilmeCitite = 0;
	while (!feof(file)) {
		Film f = citireFilmFisier(file);
		if (f.id != -1)
			adaugaFilmInVector(&filme, nrFilmeCitite, f);
	}
	fclose(file);
	return filme;
}

void dezalocareVectorFilme(Film** filme, int* nrFilme) {
	for (int i = 0; i < *nrFilme; i++) {
		free((*filme)[i].titlu);
		free((*filme)[i].regizor);
	}
	free(*filme);
	*filme = NULL;
	*nrFilme = 0;
}

int main() {
	int nrFilme = 0;
	Film* filme = citireVectorFilmeFisier("filme.txt", &nrFilme);
	if (filme) {
		afisareVectorFilme(filme, nrFilme);
		dezalocareVectorFilme(&filme, &nrFilme);
	}
	return 0;
}
