libft.a: 

a.out: main.o text.o
	gcc main.o text.o -o a.out	
main.o: main.c
	gcc -c main.c
text.o: text.c text.h
	gcc -c text.c
clean:
	rm *.o
fclean:	
	rm *.o a.out
