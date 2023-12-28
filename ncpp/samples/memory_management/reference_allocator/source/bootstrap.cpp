
#include <ncpp/.hpp>

using namespace ncpp;



int main() {

	{

		mem::F_default_reference_allocator default_reference_allocator;
		mem::F_incremental_chunk_allocator incremental_chunk_allocator;
		mem::TF_reference_allocator<mem::F_incremental_chunk_allocator> reference_allocator(incremental_chunk_allocator);

		mem::F_default_allocator default_allocator;

		eastl::allocator eastl_allocator;

		const u32 allocation_count = 4096;
		const u32 allocation_size = 1024;

		TG_vector<void*> pointers(allocation_count);

        {

            {

                NCPP_SCOPED_PROFILER_SAMPLE("ncpp::mem::F_default_reference_allocator::allocate ");

                for (u32 i = 0; i < allocation_count; ++i) {

                    pointers[i] = default_reference_allocator.allocate(allocation_size, 0);

                }

            }

            mem::log_memory_stats();

            {

                NCPP_SCOPED_PROFILER_SAMPLE("ncpp::mem::F_default_reference_allocator::deallocate ");

                for (u32 i = 0; i < allocation_count; ++i) {

                    default_reference_allocator.deallocate(pointers[i]);

                }

            }

            mem::log_memory_stats();

        }

		{

			{

				NCPP_SCOPED_PROFILER_SAMPLE("ncpp::mem::F_incremental_chunk_allocator::allocate ");

				for (u32 i = 0; i < allocation_count; ++i) {

					pointers[i] = incremental_chunk_allocator.allocate(allocation_size, 0);

				}

			}

			mem::log_memory_stats();

			{

				NCPP_SCOPED_PROFILER_SAMPLE("ncpp::mem::F_incremental_chunk_allocator::deallocate ");

				for (u32 i = 0; i < allocation_count; ++i) {

					incremental_chunk_allocator.deallocate(pointers[i]);

				}

			}

			mem::log_memory_stats();

		}

		{

			{

				NCPP_SCOPED_PROFILER_SAMPLE("ncpp::mem::TF_reference_allocator<ncpp::mem::F_incremental_chunk_allocator>::allocate ");

				for (u32 i = 0; i < allocation_count; ++i) {

					pointers[i] = reference_allocator.allocate(allocation_size, 0);

				}

			}

			mem::log_memory_stats();

			{

				NCPP_SCOPED_PROFILER_SAMPLE("ncpp::mem::TF_reference_allocator<ncpp::mem::F_incremental_chunk_allocator>::deallocate ");

				for (u32 i = 0; i < allocation_count; ++i) {

					reference_allocator.deallocate(pointers[i]);

				}

			}

			mem::log_memory_stats();

		}

		{

			{

				NCPP_SCOPED_PROFILER_SAMPLE("ncpp::mem::F_default_allocator::allocate ");

				for (u32 i = 0; i < allocation_count; ++i) {

					pointers[i] = default_allocator.allocate(allocation_size, 0);

				}

			}

			mem::log_memory_stats();

			{

				NCPP_SCOPED_PROFILER_SAMPLE("ncpp::mem::F_default_allocator::deallocate ");

				for (u32 i = 0; i < allocation_count; ++i) {

					default_allocator.deallocate(pointers[i]);

				}

			}

			mem::log_memory_stats();

		}

		{

			{

				NCPP_SCOPED_PROFILER_SAMPLE("eastl::allocator::allocate ");

				for (u32 i = 0; i < allocation_count; ++i) {

					pointers[i] = eastl_allocator.allocate(allocation_size, 0);

				}

			}

			mem::log_memory_stats();

			{

				NCPP_SCOPED_PROFILER_SAMPLE("eastl::allocator::deallocate ");

				for (u32 i = 0; i < allocation_count; ++i) {

					eastl_allocator.deallocate(pointers[i], 0);

				}

			}

			mem::log_memory_stats();

		}

		{

			{

				NCPP_SCOPED_PROFILER_SAMPLE("malloc ");

				for (u32 i = 0; i < allocation_count; ++i) {

					pointers[i] = malloc(allocation_size);

				}

			}

			{

				NCPP_SCOPED_PROFILER_SAMPLE("free ");

				for (u32 i = 0; i < allocation_count; ++i) {

					free(pointers[i]);

				}

			}

		}

	}

	mem::log_memory_stats();

	pause_console();

	return 0;
}