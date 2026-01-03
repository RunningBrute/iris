#pragma once

#include <coroutine>

namespace iris
{

class Task
{
public:
    struct promise_type
    {
        Task get_return_object() noexcept
        {
            return {};
        }

        std::suspend_never initial_suspend() noexcept
        {
            return {};
        }

        std::suspend_never final_suspend() noexcept
        {
            return {};
        }

        void return_void() noexcept
        {}

        void unhandled_exception() noexcept
        {
            std::terminate();
        }
    };
};

} // namespace iris
