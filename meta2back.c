#include <stdio.h>
#include <stdlib.h>
#include <linux/input.h>

int main(int argc, char *argv[]) {
	setbuf(stdin, NULL);
	setbuf(stdout, NULL);

	const int find = argc >= 2 ? atoi(argv[1]) : KEY_LEFTMETA;
	const int replace = argc >= 3 ? atoi(argv[2]) : KEY_BACK;

	struct input_event event;
	while (fread(&event, sizeof(event), 1, stdin) == 1) {
		// https://github.com/torvalds/linux/blob/master/include/uapi/linux/input-event-codes.h
		if (event.type == EV_KEY && event.code == find)
			event.code = replace;

		fwrite(&event, sizeof(event), 1, stdout);
	}
}

