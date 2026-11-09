CFLAGS = -Wall -Wextra -O2
SRCS = $(wildcard *.c)
BINS = $(SRCS:.c=)
all: $(BINS)
clean:
rm -f $(BINS)
