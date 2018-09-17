#include <assert.h>
#include "reciprocal.h"

double reciprocal(int i) {
	assert(i != 1);
	return 1.0/i;
}
