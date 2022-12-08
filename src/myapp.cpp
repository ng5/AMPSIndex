#include <myapp.h>
void MyApp::handleMessage(const AMPS::Message &m) {
    if (m.getCommand() == "oof") {
        _data.erase(m.getSowKey());
    } else if (m.getCommand() == "sow" || m.getCommand() == "publish") {
        _data[m.getSowKey()] = m.getData();
        std::cout << m.getData() << "\n";
    }
}
MyApp::MyApp(AMPS::Client *client, std::string topic)
    : _client(client), _topic(std::move(topic)) {}

void MyApp::run() {
    auto messageHandler = [&](const AMPS::Message &m) { handleMessage(m); };
    _client->executeAsync(
            AMPS::Command("sow_and_subscribe").setTopic(_topic).setOptions("oof"),
            messageHandler);
}

void MyApp::generateSample() {
    const auto json = R"({"orderId":1,"customerName":"test1"})";
    _client->publish(_topic, json);
}