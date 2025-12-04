#ifndef IPC_H
#define IPC_H

#define MAX_MESSAGES 64
#define MESSAGE_SIZE 256

typedef struct {
    int from_pid;
    int to_pid;
    int type;
    char data[MESSAGE_SIZE];
    int size
} Message;

typedef struct {
    Message messages[MAX_MESSAGES];
    int head;
    int tail;
    int count;
} MessageQueue;

void ipc_init(void);
int ipc_send(int to_pid, Message *msg);
int ipc_receive(int from_pid, Message *msg);
int ipc_create_queue(int pid);
void ipc_destroy_queue(int pid);

#endif