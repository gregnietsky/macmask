#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char *todo, *token, *ptr;
	int cnt = 5, bits, blank;
	int mbyte[6];

	ptr = argv[1];
	bits = atoi(argv[2]);

	if (strlen(ptr) != 17) {
		exit(-1);
	}

	while ((cnt >= 0) && (token = strtok_r(ptr, ":", &todo))) {
		sscanf(token, "%x", &mbyte[cnt]);
		ptr = todo;
		cnt --;
	}

	if ((cnt != -1) || (bits > 48) || (bits < 0)) {
		exit(-1);
	}

	blank = (bits - (bits % 8)) / 8;
	bits = bits % 8;
	for(cnt=0;cnt < blank;cnt++) {
		mbyte[cnt] = 0;
	}

	mbyte[blank] = (mbyte[blank] >> bits) << bits;

	for(cnt=5;cnt > 0;cnt--) {
		printf("%02x:", mbyte[cnt]);
	}
	mbyte[0] = (mbyte[0] >> bits) << bits;
	printf("%02x\n", mbyte[0]);
}
