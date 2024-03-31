CC = gcc

all: gradecard

gradecard: gradecard.c
    $(CC) -o gradecard gradecard.c

clean:
    rm -f gradecard

zip: grade_card
    zip -r gradecard.zip gradecard
