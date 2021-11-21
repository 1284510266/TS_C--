#include <thread>

void do_some_work(){
    printf("hello my first thread");
}

int main(int argc, char **argv){
    std::thread firstThread(do_some_work);
}