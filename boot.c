typedef void (*init_func)(void);
#define UFCON0 ((volatile unsigned int *)(0x50000020))

void helloworld(void) {
	const char *p = "helloworld\n";
	while (*p) {
		*UFCON0 = *p++;
	}
}

void timer_init(void) {

	#define TIMER_BASE		(0xd1000000)
	volatile unsigned int *TCFG0		=	(volatile unsigned int *)(TIMER_BASE + 0x0);
	volatile unsigned int *TCFG1		=	(volatile unsigned int *)(TIMER_BASE + 0x4);
	volatile unsigned int *TCON			=	(volatile unsigned int *)(TIMER_BASE + 0x8);
	volatile unsigned int *TCNTB4		=	(volatile unsigned int *)(TIMER_BASE + 0x3c);

	*TCFG0 |= 0x800;

	*TCON &= (~(7 << 20));
	*TCON |= (0 << 22);
	*TCON |= (1 << 21);

	*TCNTB4 = 10000;
	printk("*tcntb4: %d\n", *TCNTB4);

	*TCON |= (1 << 20);
	*TCON &= ~(1 << 21);

	umask_int(14);
	enable_irq();
}


static init_func init[] = { helloworld, 0 };

void plat_boot(void) {
	int i;
	for (i = 0; init[i]; i++) {
		init[i]();
	}

	init_sys_mmu();
	start_mmu();
	test_mmu();

	test_printk();

	timer_init();
	while (1) {
		;
	}
}
