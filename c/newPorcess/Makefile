
CC=gcc

CFLAGS += -I./include
LDFLAGS += -L.
BUILD = ./build
SRC = ./src

TARGET = newProcess
SOURCE = $(wildcard $(SRC)/*.c)
DEST = $(patsubst %.c, $(BUILD)/%.o, $(notdir $(SOURCE)))

$(TARGET):$(DEST)
	$(CC) $^ -o $@

$(BUILD)/%.o:$(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
	
.PHONY:clean
clean:
	rm -rf $(DEST) $(TARGET)
