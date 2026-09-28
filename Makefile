CC = cc
CFLAGS = -pthread

.PHONY: all clean

all: alphabet threads threads2 thread th_arg th_return

alphabet: lab1/alphabet.c
	$(CC) $(CFLAGS) $< -o $@

threads: lab1/threads.c
	$(CC) $(CFLAGS) $< -o $@

threads2: lab1/threads2.c
	$(CC) $(CFLAGS) $< -o $@

thread: revisions/thread.c
	$(CC) $(CFLAGS) $< -o $@
th_arg: revisions/thread_argument.c
	$(CC) $(CFLAGS) $< -o $@

th_return: revisions/thread_return.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f alphabet threads threads2 thread th_arg th_return