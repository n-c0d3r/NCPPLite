
#include <ncpp/.hpp>

using namespace ncpp;



int main() {
	
	mem::F_default_allocator allocator;



	// non-aligned allocation
	void* p = allocator.allocate(512);

    const F_alloc_debug_info& p_debug_info = get_alloc_debug_info(p);

    NCPP_INFO() << p_debug_info << std::endl;

	mem::log_memory_stats();

	allocator.deallocate(p, 512);

	mem::log_memory_stats();



	// aligned allocation
	void* aligned_p = allocator.allocate(512, 32, 6, 0);

    const F_alloc_debug_info& aligned_p_debug_info = get_alloc_debug_info(aligned_p);

    NCPP_INFO() << aligned_p_debug_info << std::endl;

	mem::log_memory_stats();

	allocator.deallocate(aligned_p, 512);

	mem::log_memory_stats();



	pause_console();

	return 0;
}