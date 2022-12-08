#pragma once
#include <HAClient.hpp>
class Client {
public:
    [[nodiscard]] AMPS::HAClient get() const;
};