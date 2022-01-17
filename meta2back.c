#include <stdio.h>
#include <stdlib.h>
#include <linux/input.h>

int main(int argc, char *argv[]) {
	setbuf(stdin, NULL);
	setbuf(stdout, NULL);

	// codes via https://github.com/torvalds/linux/blob/master/include/uapi/linux/input-event-codes.h
	const __u16 find = argc >= 2 ? atoi(argv[1]) : KEY_LEFTMETA;
	// didn't do anything: BTN_BACK, 0x116
	// worked as expected: BTN_SIDE, 0x113
	const __u16 replace = argc >= 3 ? atoi(argv[2]) : BTN_SIDE;

	struct input_event event;
	while (fread(&event, sizeof(event), 1, stdin) == 1) {
		if (event.type == EV_KEY && event.code == find) {
			event.code = replace;
		}

		fwrite(&event, sizeof(event), 1, stdout);
	}
}
