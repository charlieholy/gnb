#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;
std::mutex g_mutex;
std::condition_variable g_cond;

class C : public std::enable_shared_from_this<C> {
public:
    C() {
        std::cout << "C" << std::endl;
        msg = "Hello World";
    }

    ~C() {
        std::cout << "~C" << std::endl;
    }

    void init() {
        local = this->shared_from_this();
    }

    void thread_fun() {
        while(true) {
            std::unique_lock<std::mutex> lk(g_mutex);
            g_cond.wait(lk);
            std::cout << msg << std::endl;
        }
    }

    void print() {
        th = std::thread(&C::thread_fun, this);
        th.detach();
    }

private:
    std::shared_ptr<C> local;
    std::thread th;
    std::string msg;
};

void fun() {
    shared_ptr<C> c = std::make_shared<C>();
    c->init();
    c->print();
}


int main(int argc, char* argv[])
{
    fun();
    std::cout << "fun finish" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    for(int i = 0; i < 4; i++) {
        g_cond.notify_all();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    return 0;
}


///////////////////
g++ wuv.cpp -std=c++17 -lpthread
