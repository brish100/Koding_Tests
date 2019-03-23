#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Receiver_3{
	void (*command) ();
} Receiver_3;

void command_3(Receiver_3* receiver){
	printf("%s\n", "Command is triggered!");
}

struct Receiver_3* init_receiver_3 (){
	Receiver_3 *rec_3 = malloc(sizeof(Receiver_3));
	rec_3->command = command_3;
	return rec_3;
}

typedef struct Receiver_2{
	Receiver_3 rec_3;
	void (*command) ();
} Receiver_2;

void command_2(Receiver_3* receiver){
	receiver->command();
}

struct Receiver_2* init_receiver_2 (Receiver_3* receiver){
	Receiver_2 *rec_2 = malloc(sizeof(Receiver_2));
	rec_2->rec_3 = *receiver;
	rec_2->command = command_2;
	return rec_2;
}

typedef struct Receiver{
	Receiver_2 rec_2;
	void (*command) ();
} Receiver;

void command_1(Receiver_2* receiver) {
	receiver->command();
}

struct Receiver* init_receiver (Receiver_2* receiver){
	Receiver *rec = malloc(sizeof(Receiver));
	rec->rec_2 = *receiver;
	rec->command = command_1;
	return rec;
}

typedef struct Invoker{
	Receiver rec;
	void (*command) ();
} Invoker;

void command (Receiver* receiver){
	receiver->command();
}

struct Invoker* init_invoker (Receiver* receiver){
	Invoker *inv = malloc(sizeof(Invoker));
	inv->rec = *receiver;
	inv->command = command;
	return inv;
}

int main(){
	Receiver_3* rec_3 = init_receiver_3();
	Receiver_2* rec_2 = init_receiver_2(rec_3);
	Receiver* rec = init_receiver(rec_2);
	Invoker* inv = init_invoker(rec);
	inv->command();
	free(rec_3);
	free(rec_2);
	free(rec);
	free(inv);
	return 0;
}
