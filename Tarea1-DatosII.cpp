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

        *myPtr = *tail;

        return 0;
    }


    void show_list(){
        node* current = new node();

        current = head;

        if(head == NULL){
            std::cout << "No elements on the list" << std::endl;
        }

        else{
            for( int i = 0; i < size; i++){
                std :: string s = std::to_string(current->get_data());
                std::cout << s << std::endl;
                if((size - i) > 1){
                    *current = current->get_next();
                }   
            }
        }


    }

     void show_size(){
        std::string s = std::to_string(size);
        std::cout << size;
    }
};   

static void PrintMemoryUsage(){
    std::cout << "Mmemory Usage " << s_AllocationMetrics.CurrentUsage() << " bytes\n";
}

int main(){

    PrintMemoryUsage();
    
    linked_list* list = new linked_list();

    PrintMemoryUsage();

    list->add_value(50);

    //list->show_list();

    PrintMemoryUsage();
    
    delete list;

    PrintMemoryUsage();
    
}