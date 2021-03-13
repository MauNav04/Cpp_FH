#include<iostream>

struct AllocationMetrics{
    uint32_t TotalAllocated = 0;
    uint32_t TotalFreed = 0;

    uint32_t CurrentUsage(){return TotalAllocated-TotalFreed;}
};

static AllocationMetrics s_AllocationMetrics;

void* operator new(size_t size){
    //std::cout << "ellolove";
    s_AllocationMetrics.TotalAllocated += size;

    return malloc(size);
}

void operator delete(void * memory, size_t size){
    //std::cout << "baibailove";
    s_AllocationMetrics.TotalFreed += size;
    
    free(memory);
}

struct node{
    int data;
    node* next;

    node(){
        std::cout << "[Constr.] empty node\n";
    }

    node(int number){
        data = number;
        next = NULL;
    }

    void set_data(int info){
        data = info;
    }

    void set_next(node* node){
        next = node;
    }

    int get_data(){return data;}

    node get_next(){return *next;}

};


struct linked_list{
    node *head, *tail;
    int size;

    linked_list(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void add_value(int value){
        node* tmp = new node(value);

        if(head == NULL){
            head = tmp;
            tail = tmp;
            size += 1;
        }

        else{
            tail->set_next(tmp);
            tail = tmp;
            size += 1;
        }
    }

    int delete_last(){
        node* myPtr;

        *myPtr = &tail;

    }
