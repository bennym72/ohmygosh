#include <stdlib.h>
#include <stdio.h>

typedef struct {
	char* name;
	int mark;
} Course;

void Course_Init(Course* c, char* n, int m) {
	c->name = n;
	c->mark = m;
}


typedef struct {
	char* studentName;
	int maxNoCourses;
	int noCourses;
	Course* courses;
} Transcript;

void Transcript_Init(Transcript* t, int n) {
	t->courses = (int*) malloc(n*sizeof(Course));
	t->maxNoCourses = n;
	t->noCourses = 0;
}

void setName(Transcript* t, char* newName) {
	t->studentName = newName;
}

char* getName(Transcript* t) {
	return t->studentName;
}

int getnoCourses(Transcript* t) {
	return t->noCourses;
}

void addCourse(Transcript* t, Course c) {
	if ((t->noCourses) < (t->maxNoCourses)) {
		t->courses[t->noCourses] = c;
		t->noCourses++;
	}
}


float average(Transcript *t) {
	float sum = 0;
	int i;
	for (i = 0; i < t->noCourses; i++) {
		sum += t->courses[i].mark;
	}
	return (sum/(t->noCourses));
}


int main() {
	Transcript t;
	Transcript_Init(&t, 10);
	setName(&t, "John Too");
	
	Course c;
	Course_Init(&c, "CPSC 121", 75);
	addCourse(&t, c);
	
	Course c1;
	Course_Init(&c1, "CPSC 210", 85);
	addCourse(&t, c1);
	
	Course c2;
	Course_Init(&c2, "CPSC 213", 90);
	addCourse(&t, c2);

	printf("%s's marks are: \n", getName(&t));
	int i;
	for (i = 0; i < getnoCourses(&t); i++) {
		printf("    %s: %d\n", t.courses[i].name, t.courses[i].mark);
	}
	printf("%s's average is: %f", getName(&t), average(&t));
	return 0;
}
















