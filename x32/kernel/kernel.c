void print(const char* str) {
    volatile char* video_memory = (volatile char*)0xB8000;

    for(int i = 0; str[i] != '\0'; i++) {
        video_memory[i * 2] = str[i];
    }
}

void kernel(void) {
    const char* hello_msg = "Hello World! from testOS 32 bit kernel";

    volatile char* video_momery = (volatile char*)0xB8000;
    for(int i = 0; i < 80 * 25 * 2; i += 2) {
        video_momery[i] = ' ';
        video_momery[i + 1] = 0x07; //серый фон
    }

    print(hello_msg);

    while(1);
}