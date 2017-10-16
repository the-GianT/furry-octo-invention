LList: LList.o
	gcc -o LList LList.o
LList.o: LList.c
	gcc -c LList.c
run: LList
	./LList
