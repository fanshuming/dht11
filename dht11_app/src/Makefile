all: dht11_app
OBJS = dht11_app.o

CC = gcc
CCFLAGS = -Wall -c -o

%.o: %.c
	$(CC) $(CCFLAGS) $@ $< $(LDFLAGS)

fbtest: $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

clean:
	rm -f rbcfg *.o
