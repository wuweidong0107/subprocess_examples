CROSS_COMPILE?=
TARGET=example1 example2

all: $(TARGET)

%: %.c
	$(CROSS_COMPILE)gcc $^ -o $@

clean:
	rm -f example