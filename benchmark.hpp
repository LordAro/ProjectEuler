#include <iostream>
#include <chrono>

/**
 * Benchmark a function's runtime, with answer stability checking.
 * @tparam F Function type to benchmark.
 * @tparam Args Argument types of #F.
 * @param iterations
 * @param func Function to benchmark.
 * @param args Arguments of #func.
 * @return If the answer is stable.
 */
template<typename F, typename... Args>
bool benchmark(uint64_t iterations, F func, Args... args)
{
	/* high_res_clock not always monotonic :/ */
	using steadyclock_t = typename std::conditional<std::chrono::high_resolution_clock::is_steady,
		  std::chrono::high_resolution_clock, std::chrono::steady_clock>::type;
	using ret_t = typename std::result_of<F(Args...)>::type;
	ret_t stable_ans = -1;

	double time_count = 0;
	for (uint64_t c = 0; c < iterations; c++) {
		auto t1 = steadyclock_t::now();
		ret_t ans = func(args...);
		auto t2 = steadyclock_t::now();

		/* Checking the answer is stable */
		if (stable_ans != -1 && stable_ans != ans) {
			std::cout << "Answer '" << ans << "' not the same as previous '" << stable_ans << "'\n";
			return false;
		}
		stable_ans = ans;

		auto time_span = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1);
		time_count += time_span.count();
	}
	std::cout << "Average time taken: " << time_count / iterations << "ms" << std::endl;
	return true;
}
