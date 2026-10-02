CC = cc
CFLAGS = -pthread

.PHONY: all clean

all: alphabet threads threads2 thread th_arg th_return th_order data_race mutex_counter critical_section critical_section_variant multiple_mutexes deadlock deadlock_fixed

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

th_order: revisions/thread_order.c
	$(CC) $(CFLAGS) $< -o $@

data_race: revisions/data_race.c
	$(CC) $(CFLAGS) $< -o $@

mutex_counter: revisions/mutex_counter.c
	$(CC) $(CFLAGS) $< -o $@

critical_section: revisions/critical_section.c
	$(CC) $(CFLAGS) $< -o $@

critical_section_variant: revisions/critical_section_variant.c
	$(CC) $(CFLAGS) $< -o $@

multiple_mutexes: revisions/multiple_mutexes.c
	$(CC) $(CFLAGS) $< -o $@

deadlock: revisions/deadlock.c
	$(CC) $(CFLAGS) $< -o $@

deadlock_fixed: revisions/deadlock_fixed.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f alphabet threads threads2 thread th_arg th_return th_order data_race mutex_counter critical_section critical_section_variant multiple_mutexes deadlock deadlock_fixed