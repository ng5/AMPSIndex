#pragma once
#include <ampsplusplus.hpp>
class MyApp {
private:
    AMPS::Client *_client;
    std::string _topic;
    std::map<std::string, std::string> _data;

    void handleMessage(const AMPS::Message &m);

public:
    MyApp(AMPS::Client *client, std::string topic);
    void run();
    void generateSample();
};