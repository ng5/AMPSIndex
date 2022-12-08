#include "getclient.h"
#include "myapp.h"
using namespace std::chrono_literals;
int main() {
    constexpr auto TOPIC = "/orders/specialHandling";
    Client client;
    auto c = client.get();
    MyApp myApp{&c, TOPIC};
    myApp.generateSample();
    return 0;
}
