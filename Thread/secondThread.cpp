#include <thread>
#include <iostream>

void do_something() {
    printf("do_something\n");
}
void do_something_else() {
    printf("do_something_else");
}

class background_test {
    public:
        void operator()() const{
            do_something();
            do_something_else();
        }
};


int main(int argc, char **argv) {
    background_test f;
    std::thread thread2(f);
    std::thread thread3(background_test());
    std::thread thread4((background_test()));
}