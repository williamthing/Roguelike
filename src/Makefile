CC=g++
CFLAGS=-g -Wall -std=c++11
LDFLAGS=-g -Wall -std=c++11

main = rgame

obj = PerlinNoise.o Character.o Frame.o Screen.o Player.o Monster.o Sense.o Terrain.o MapEntity.o Scorecard.o Treasure.o Directions.o Log.o BabyMonster.o $(main).o

$(main): $(obj)
	$(CC) $(LDFLAGS) -o $@ $^ -lncurses

$(main).o: $(main).cpp
	$(CC) $(CFLAGS) -c -o $@ $<

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c -o $@ $<

SUB_FILE=hw7-soln.tar
SUBS=answers.txt BabyMonster.cpp BabyMonster.h rgame.cpp
build-submit:
	rm -f $(SUB_FILE)
	tar cvf $(SUB_FILE) $(SUBS)

clean:
	rm -f $(obj) $(main) $(SUB_FILE)


