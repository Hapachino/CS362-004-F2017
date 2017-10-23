#include "assertTrue.h"

int assertTrue(char* function, char* message, int status) {
	if (status) {
		printf("%s: PASS %s", function, message);
	} else {
		printf("%s: FAIL %s", function, message);
	}
}