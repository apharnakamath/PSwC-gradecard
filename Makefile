CC = gcc

all: gradecard

gradecard: gradecard.c
    $(CC) -o gradecard gradecard.c

clean:
    rm -f gradecard

