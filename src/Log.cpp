#include "Log.h"

std::shared_ptr<spdlog::logger> Log::s_main_logger;
std::shared_ptr<spdlog::logger> Log::s_test_logger;

void Log::init()
{
    spdlog::set_pattern("%^[%T] %n: %v%$");

    s_main_logger = spdlog::stdout_color_mt("MAIN");
    s_main_logger->set_level(spdlog::level::trace);

    s_test_logger = spdlog::stdout_color_mt("TEST");
    s_test_logger->set_level(spdlog::level::trace);
}