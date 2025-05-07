//Author: Melinda Liu
//Date: 4/24/25
//Purpose: final project

#include <stdio.h>

#define WORD_LEN 6
#define MAX_GUESSES 6

void getWord(char word[WORD_LEN]);
void getGuess(char guess[WORD_LEN], int guessNum);
void changeLower(char guess[]);
int checkCorrectInput(char guess[]);
void evaluateGuess(char guess[], char word[], char result[][WORD_LEN], char positionMarker[][WORD_LEN], int guessNum);
void displayResult(char result[][WORD_LEN], char positionMarker[][WORD_LEN], int guessNum);
int isCorrectWord(char guess[], char word[]);

int main() {
	char word[WORD_LEN];
	char guess[WORD_LEN];
	char result[MAX_GUESSES][WORD_LEN];
	char positionMarker[MAX_GUESSES][WORD_LEN];
	int guessNum = 0;
	
	getWord(word);
	
	while (guessNum < MAX_GUESSES) {
		getGuess(guess, guessNum + 1);
		changeLower(guess);
		evaluateGuess(guess, word, result, positionMarker, guessNum);
		displayResult(result, positionMarker, guessNum + 1);
		
		if (isCorrectWord(guess, word)) {
			printf("You won in %d guesses!", guessNum + 1);
		}
		
		guessNum++;
	}
	
	if (guessNum >= MAX_GUESSES) {
		printf("You lost, better luck next time!");
	}
	
	return 0;

}
	
void getWord(char word[]) {
	FILE* fptr = fopen("word.txt", "r");
	if(fptr == NULL){
		printf("Unable to open file\n");	
	}
	fscanf(fptr, "%s", word);
	fclose(fptr);
}

void getGuess(char guess[], int guessNum) {
	int correctInput;
	int counter;
	do {
		printf("GUESS %d! Enter your guess: ", guessNum);
		scanf("%5s", guess);
		changeLower(guess);
		while (guess[counter] != '\0') {
			counter++;
		}
		if (counter < WORD_LEN || counter > WORD_LEN) {
			printf("Your guess must be 5 letters long.");
			correctInput = 1;
		}
		else if (checkCorrectInput(guess) = 1) {
			printf("Your guess must be 5 letters long. Your guess must contain letters.");
			correctInput = 1;
		}
	} while (correctInput = 1);
	;
}

int checkCorrectInput(char guess[]) {
	for (int i = 0; i < WORD_LEN; i++) {
		if ((guess[i] < 'A' || guess[i] > 'Z') && (guess[i] < 'a' || guess[i] > 'z')) {
		}
	}
	return 1;
}

void changeLower(char guess[]) {
	for (int i = 0; guess[i]; i++) {
		if (guess[i] >= 'A' && guess[i] <= 'Z') {
			guess[i] += 'a' - 'A';
		}
	}
}

void evaluateGuess(char guess[], char word[], char result[][WORD_LEN], char positionMarker[][WORD_LEN], int guessNum) {
	for (int i = 0; i < WORD_LEN; i++) {
		result[guessNum][i] = guess[i];
		positionMarker[guessNum][i] = ' ';
	}
	result[guessNum][WORD_LEN] = '\0';
	positionMarker[guessNum][WORD_LEN] = '\0';
	int matching[WORD_LEN];
	for (int i = 0; i < WORD_LEN; i++) {
		if (guess[i] == word[i]) {
			result[guessNum][i] = guess[i] - ('a' - 'A');
			matching[i] = 1;
		}
	}
	for (int i = 0; i < WORD_LEN; i++) {
		for (int j = 0; j < WORD_LEN; j++) {
			if (matching[j] != 1 && guess[i] == word[j]) {
				positionMarker[guessNum][i] = '^';
				matching[j] = 1;
			}
		}
	}
}

void displayResult(char result[][WORD_LEN], char positionMarker[][WORD_LEN], int guessNum) {
	for (int i = 0; i < 33; i++){
		printf("=");
	}
	for (int i = 0; i < guessNum; i++) {
		printf("%s\n%s\n", result[i], positionMarker[i]);
	}
}


int isCorrectWord(char guess[], char word[]) {
	for (int i = 0; i < WORD_LEN; i++) {
		if (guess[i] != word[i]) {
		}
	}
	return 1;
}

