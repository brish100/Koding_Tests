#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Memento{
	char* state;
} Memento;

struct Memento* init_memento(char* state){
	Memento *memento = malloc(sizeof(Memento));
	memento->state = state;
	return memento;	
}

typedef struct CareTaker {
	int arraysize;
	Memento** mementos;
	int (*save) (struct CareTaker*, struct Memento*);
	Memento* (*restore) (struct CareTaker*, int);
} CareTaker;

int save(CareTaker* caretaker, Memento* memento){
	if(caretaker->arraysize == 0){
		caretaker->mementos = malloc(sizeof(Memento));
		caretaker->mementos[0] = memento;
	} else {
		Memento** mementos_copy = malloc(sizeof(Memento)*(caretaker->arraysize+1));
		for (int i = 0; i < caretaker->arraysize; i++){
			mementos_copy[i] = caretaker->mementos[i];
			caretaker->mementos[i] = NULL;
		}
		mementos_copy[caretaker->arraysize] = memento;
		caretaker->mementos = realloc(caretaker->mementos, (sizeof(Memento)*(caretaker->arraysize+1)));
		for (int i = 0; i < caretaker->arraysize+1; i++){
			caretaker->mementos[i] = mementos_copy[i];
		}
		free(mementos_copy);
	}
	return caretaker->arraysize++;
}

struct Memento* restore(CareTaker* caretaker, int mem_index){
	return caretaker->mementos[mem_index];
}

struct CareTaker* init_caretaker(){
	CareTaker *caretaker = malloc(sizeof(CareTaker));
	caretaker->arraysize = 0;
	caretaker->save = save;
	caretaker->restore = restore;
	return caretaker;
}

typedef struct Orignator {
	Memento* mem;
	void (*setMemento) (struct Orignator*, char* state);
	void (*restoreMemento) (struct Orignator*, Memento* memento);
	Memento* (*returnMemento) (struct Orignator*);
} Orignator;

void setMemento(Orignator* originator, char* state){
	Memento *memento = init_memento(state);
	originator->mem = memento;
	printf("State is set to: %s\n", state);
}

void restoreMemento(Orignator* originator, Memento* memento){
	printf("State is reverted back from: %s to %s\n", originator->mem->state, memento->state);
	originator->mem = memento;
}

Memento* returnMemento(Orignator* originator){
	return originator->mem;
}

struct Orignator* init_originator(){
	Orignator *originator = malloc(sizeof(Orignator));
	originator->setMemento = setMemento;
	originator->restoreMemento = restoreMemento;
	originator->returnMemento = returnMemento;
	return originator;
}

int main(){
	Orignator* originator = init_originator();
	CareTaker* caretaker = init_caretaker();
	originator->setMemento(originator, "State1");
	int ind_1 = caretaker->save(caretaker, originator->returnMemento(originator));
	originator->setMemento(originator, "State2");
	int ind_2 = caretaker->save(caretaker, originator->returnMemento(originator));
	originator->setMemento(originator, "State3");
	int ind_3 = caretaker->save(caretaker, originator->returnMemento(originator));
	originator->setMemento(originator, "State4");
	int ind_4 = caretaker->save(caretaker, originator->returnMemento(originator));
	originator->restoreMemento(originator, caretaker->restore(caretaker,ind_1));
	originator->restoreMemento(originator, caretaker->restore(caretaker,ind_2));
	originator->restoreMemento(originator, caretaker->restore(caretaker,ind_3));
	originator->restoreMemento(originator, caretaker->restore(caretaker,ind_4));
	for (int i = 0; i < caretaker->arraysize; ++i){
		free(caretaker->mementos[i]);
	}
	free(caretaker->mementos);
	free(caretaker);
	free(originator);
	return 0;
}
