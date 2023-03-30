#include <kernel/idt.h>
#include <stdio.h>
#include <util.h>
#include <stdbool.h>
#include "keys.h"
unsigned char typed[1024];
int counter=0;
bool printrn=false;
void keyboard_handler_main(void)
{
	unsigned char status;
	char keycode;
	write_port(0x20, 0x20);

	status = read_port(KEYBOARD_STATUS_PORT);
	if (status & 0x01) {
		keycode = read_port(KEYBOARD_DATA_PORT);
		if(keycode < 0)
			return;

		else if(keycode == ENTER_KEY_CODE) {
			mse_nl();
			printf("\n");
			for (int y=0;y<1024;y++) {
				typed[y]=0;
			}
			return;
		} else if(keycode==0x20) {
			
		} else {
			typed[counter]=keyboard_map[(unsigned char) keycode];
			counter++;
			if (printrn==true) {
				printf(keys(keycode));
			}
		} 
		
		vidptr[current_loc++] = keyboard_map[(unsigned char) keycode];
		vidptr[current_loc++] = 0x07;
	}
}
// int enter(char code[]) {
// 	printf("\n");
// 	putchar(code);
// 	printf("pressed;");
// 	mse_nl();
// }
void kmain(void)
{
	#include <kernel/kernel.h>
	term_init();
	/*
	setclr colors
		BLACK = 0
		DARK_BLUE = 1
		DARK_GREEN = 2
		DARK_CYAN = 3
		DEEP_RED = 4
		MAGENTA = 5
		BROWN = 6
		LIGHT_GREY = 7
		DARK_GREY = 8
		BLUE = 9
		GREEN = 10
		CYAN = 11
		LIGHT_RED = 12
		LILAC = 13
		YELLOW = 14
		WHITE = 15
	*/
	setclr(2,0);
	printf(" _   _                  _  _____  _____           \n| \\ | |                | ||  _  |/  ___|          \n|  \\| |  ___  _ __   __| || | | |\\ `--.           \n| . ` | / _ \\| '__| / _` || | | | `--. \\          \n| |\\  ||  __/| |   | (_| |\\ \\_/ //\\__/ /          \n\\_| \\_/ \\___||_|    \\__,_| \\___/ \\____/           \n\n\n  ___                 _____   ____   _____  _____ ");
	printf("\n / _ \\               |  _  | / ___| |  _  |/  ___|\n/ /_\\ \\ _ __   __  __ \\ V / / /___  | | | |\ `--. \n|  _  || '_ \\  \\ \\/ / / _ \\ | ___ \\ | | | | `--. \n| | | || | | |  >  < | |_| || \\_/ | \\\\_/ //\\__/ /\n\\_| |_/|_| |_| /_/\\_\\_____/\\_____/  \\___/ \\____/ ");
	setclr(15,0);
	printf("\n\n\nWelcome to NerdOS. Enjoy your stay :)");
	int i=0;
	while (i<100000000) {
		i++;
		printf("\0");
	}
	
	clear();
	kprintd("Boot into kernel: ",1);

	idt_init();
	kb_init();
	nprintf("\n");
	kprintd("Initialise IDT and keyboard input: ",1);
	mse_nl();
	mse_nl();
	printf("\n");
	printrn=true;
	while(1);
}