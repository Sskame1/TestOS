#include "ipc.h"
#include "drivers/video/screen.h"

static MessageQueue queues[32];  // 32 процесса максимум
static int queue_count = 0;

void ipc_init(void) {
    for (int i = 0; i < 32; i++) {
        queues[i].head = 0;
        queues[i].tail = 0;
        queues[i].count = 0;
    }
    queue_count = 0;
    
    print_on_screen("[IPC] Initialized\n");
}

int ipc_create_queue(int pid) {
    if (pid >= 32) return -1;
    
    queues[pid].head = 0;
    queues[pid].tail = 0;
    queues[pid].count = 0;
    
    if (pid >= queue_count) queue_count = pid + 1;
    
    return 0;
}

int ipc_send(int to_pid, Message* msg) {
    if (to_pid >= queue_count) return -1;
    
    MessageQueue* queue = &queues[to_pid];
    
    if (queue->count >= MAX_MESSAGES) {
        return -1;  // очередь полна
    }
    
    queue->messages[queue->tail] = *msg;
    queue->tail = (queue->tail + 1) % MAX_MESSAGES;
    queue->count++;
    
    return 0;
}

int ipc_receive(int from_pid, Message* msg) {
    if (from_pid >= queue_count) return -1;
    
    MessageQueue* queue = &queues[from_pid];
    
    if (queue->count == 0) {
        return -1;  // нет сообщений
    }
    
    *msg = queue->messages[queue->head];
    queue->head = (queue->head + 1) % MAX_MESSAGES;
    queue->count--;
    
    return 0;
}