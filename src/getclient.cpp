#include <DefaultServerChooser.hpp>
#include <HAClient.hpp>
#include <climits>
#include <getclient.h>
#include <iostream>
#include <map>
#include <unistd.h>


using namespace std::chrono_literals;
constexpr auto PRIMARY_URL = "tcp://localhost:9007/amps/json";

AMPS::HAClient Client::get() const {
    char hostname[HOST_NAME_MAX];
    char username[LOGIN_NAME_MAX];
    gethostname(hostname, HOST_NAME_MAX);
    getlogin_r(username, LOGIN_NAME_MAX);
    const auto clientId = std::string(hostname) + ":" + username + ":AMPSIndex";
    AMPS::HAClient client{clientId};
    AMPS::ServerChooser chooser(new AMPS::DefaultServerChooser());
    chooser.add(PRIMARY_URL);
    client.setServerChooser(chooser);
    client.connectAndLogon();
    return client;
}
