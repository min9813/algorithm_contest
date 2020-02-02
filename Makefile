FNAME = none
CFLAGS = std=c++17

main:  ${FNAME}
	g++ -o main ${FNAME} ${CFLAGS}

run: main
	./main