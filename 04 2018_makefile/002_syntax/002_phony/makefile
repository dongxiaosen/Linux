test : a.o b.o c.o
	gcc -o test $^
%.c : %.o
	gcc -c -o $@ $<

clean : 
	rm *.o test

