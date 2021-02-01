#ifndef __LOG_H__
#define __LOG_H__

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

#include <string>
#include <memory>

class Log {
  public:
	static void init();

	// Possible copying
	inline static std::shared_ptr<spdlog::logger> &GetCoreLogger()
	{
		return s_main_logger;
	}

	inline static std::shared_ptr<spdlog::logger> &GetTestLogger()
	{
		return s_test_logger;
	}

  private:
	static std::shared_ptr<spdlog::logger> s_main_logger;
	static std::shared_ptr<spdlog::logger> s_test_logger;
};

#define LOG_CORE_TRACE(...) ::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LOG_CORE_INFO(...) ::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LOG_CORE_WARN(...) ::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LOG_CORE_ERROR(...) ::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LOG_CORE_CRITICAL(...) ::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define LOG_TEST_TRACE(...) ::Log::GetTestLogger()->trace(__VA_ARGS__)
#define LOG_TEST_INFO(...) ::Log::GetTestLogger()->info(__VA_ARGS__)
#define LOG_TEST_WARN(...) ::Log::GetTestLogger()->warn(__VA_ARGS__)
#define LOG_TEST_ERROR(...) ::Log::GetTestLogger()->error(__VA_ARGS__)
#define LOG_TEST_CRITICAL(...) ::Log::GetTestLogger()->critical(__VA_ARGS__)

#endif // __LOG_H__