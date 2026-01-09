#include <fit_decode.hpp>
#include <fit_mesg.hpp>

#include <fstream>
#include <iostream>

#include "iris/iris.hpp"
#include "iris/task.hpp"

iris::Task run()
{
    std::cout << "Hello from coroutine\n";
    co_return;
}

struct DummyListener : fit::MesgListener
{
    void OnMesg(fit::Mesg&) override {}
};

int main()
{
    std::cout << "Iris starting...\n";
    run();

    std::ifstream file("data/sample.fit", std::ios::binary);
    if (!file)
    {
        std::cerr << "Cannot open FIT file\n";
        return 1;
    }

    fit::Decode decoder;
    DummyListener listener;

    std::cout << "Decoding FIT file...\n";

    if (!decoder.Read(file, listener))
    {
        std::cerr << "FIT decode failed\n";
        return 1;
    }

    std::cout << "FIT decode OK\n";
    return 0;
}
