#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Request{
	int amount;
	void (*get) (struct Request* req, int a);
} Request;

void getfunc (Request* request, int bill){
	int count = floor(request->amount/bill);
	request->amount = request->amount - (count * bill);
	printf("Dispense %d $%d bills\n", count, bill);
}

struct Request* init (int start){
	Request *req = malloc(sizeof(Request));
	printf("Requested: $%d\n", start);
	req->amount = start;
	req->get = getfunc;
	return req;
}

int main(int argc, char const *argv[]){
	Request* request = init(378);
	request->get(request,100);
	request->get(request,50);
	request->get(request,20);
	request->get(request,10);
	request->get(request,5);
	request->get(request,1);
	free(request);
	return 0;
}
