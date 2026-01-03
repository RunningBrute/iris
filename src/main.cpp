#include <iostream>
#include "iris/iris.hpp"
#include "iris/task.hpp"

iris::Task run()
{
    std::cout << "Hello from coroutine\n";
    co_return;
}

int main()
{
    std::cout << "Iris starting...\n";
    run();

    return 0;
}
