#include "getclient.h"
#include "myapp.h"
#include <chrono>
using namespace std::chrono_literals;
int main() {
    constexpr auto TOPIC = "/orders/specialHandling";
    Client client;
    auto c = client.get();
    MyApp myApp{&c, TOPIC};
    myApp.run();

    while (true) {
        std::this_thread::sleep_for(1s);
    }
    return 0;
}
