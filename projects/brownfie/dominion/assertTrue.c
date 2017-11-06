#include "assertTrue.h"

int assertTrue(char* function, char* message, int status) {
	if (status) {
		printf("%s: PASS %s", function, message);
	} else {
		printf("%s: FAIL %s", function, message);
	}
}

int reportError(char* message, int status) {
	if (!status) {
		printf("%s: FAIL", message);
		return 1;
	} else {
		return 0;
	}
}

int isError(int status) {
	if (!status) {
		return 1;
	} else {
		return 0;
	}
}