#pragma once

/** @file ncpp/containers/concurrent_ring_buffer.hpp
*	@brief Implements concurrent ring buffer.
*/



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#pragma region Includes

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <ncpp/prerequisites.hpp>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <ncpp/utilities/.hpp>
#include <ncpp/mem/default_allocator.hpp>
#include <ncpp/mem/general_allocator.hpp>
#include <ncpp/mem/ephemeral_allocator.hpp>
#include <ncpp/containers/eastl_containers.hpp>
#include <ncpp/containers/eastl_bindings.hpp>
#include <ncpp/containers/binding_helper.hpp>
#include <ncpp/containers/view.hpp>
#include <ncpp/colorized_log.hpp>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <ncpp/pac/srsw_spin_lock.hpp>

#pragma endregion



 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



namespace ncpp {

	namespace containers {

		template<typename F_item__, class F_allocator__ = mem::F_default_allocator, class F_lock__ = pac::F_srsw_spin_lock>
		class TF_concurrent_ring_buffer {

		public:
			using F_item = F_item__;
			using F_allocator = F_allocator__;
			using F_lock = F_lock__;

			using F_item_vector = TF_vector<F_item, F_allocator>;



		protected:
			F_item_vector item_vector_;
			ai64 begin_index_ = 0;
			ai64 end_index_ = 0;
			
		private:
			i64 capacity_ = 0;
			F_lock reader_lock_;
			F_lock writer_lock_;


		public:
			NCPP_FORCE_INLINE i64 size() const { return end_index_.load(eastl::memory_order_acquire) - begin_index_.load(eastl::memory_order_acquire); }
			NCPP_FORCE_INLINE i64 capacity() const { return capacity_; }
			NCPP_FORCE_INLINE bool is_empty() const { return !size(); }
			NCPP_FORCE_INLINE bool is_null() const { return !capacity_; }
            NCPP_FORCE_INLINE i64 begin_index() const { return begin_index_.load(eastl::memory_order_acquire); }
            NCPP_FORCE_INLINE i64 end_index() const { return end_index_.load(eastl::memory_order_acquire); }
            NCPP_FORCE_INLINE TF_view<F_item_vector> item_vector() const { return item_vector_; }



		public:
			inline TF_concurrent_ring_buffer() {



			}
			inline TF_concurrent_ring_buffer(sz capacity) :
				capacity_(capacity),
				item_vector_(capacity)
			{

				

			}

			inline TF_concurrent_ring_buffer(const TF_concurrent_ring_buffer& x) :
				item_vector_(x.item_vector_),
				capacity_(x.capacity_),
				begin_index_(x.begin_index_.load(eastl::memory_order_acquire)),
				end_index_(x.end_index_.load(eastl::memory_order_acquire))
			{



			}
			inline TF_concurrent_ring_buffer& operator = (const TF_concurrent_ring_buffer& x) {

				item_vector_ = x.item_vector_;
				capacity_ = x.capacity_;
				begin_index_.store(x.begin_index_.load(eastl::memory_order_acquire), eastl::memory_order_release);
				end_index_.store(x.end_index_.load(eastl::memory_order_acquire), eastl::memory_order_release);

                return *this;
			}

			inline TF_concurrent_ring_buffer(TF_concurrent_ring_buffer&& x) :
				item_vector_(std::move(x.item_vector_)),
				capacity_(x.capacity_),
				begin_index_(x.begin_index_.load(eastl::memory_order_acquire)),
				end_index_(x.end_index_.load(eastl::memory_order_acquire))
			{



			}
			inline TF_concurrent_ring_buffer& operator = (TF_concurrent_ring_buffer&& x) {

				item_vector_ = std::move(x.item_vector_);
				capacity_ = x.capacity_;
                begin_index_.store(x.begin_index_.load(eastl::memory_order_acquire), eastl::memory_order_release);
                end_index_.store(x.end_index_.load(eastl::memory_order_acquire), eastl::memory_order_release);

                return *this;
			}



		private:
			template<typename F_passed_item__>
			void T_push(F_passed_item__&& item) {

				writer_lock_.lock();

				NCPP_ASSERT(size() < capacity()) << "out of capacity";

				item_vector_[(end_index_.fetch_add(1, eastl::memory_order_release)) % capacity_] = std::forward<F_passed_item__>(item);

				writer_lock_.unlock();

			}



		public:
			NCPP_FORCE_INLINE void push(F_item const& item) {

				T_push(std::forward<F_item const&>(item));
			}
			NCPP_FORCE_INLINE void push(F_item&& item) {

				T_push(std::forward<F_item>(item));
			}

			inline b8 try_pop(F_item& item) {

				reader_lock_.lock();

				i64 end = end_index_.load(eastl::memory_order_acquire);
				i64 begin = begin_index_.load(eastl::memory_order_acquire);

				if ((end - begin)> 0) {
				
					begin_index_.fetch_add(1, eastl::memory_order_acq_rel);

					item = std::move(item_vector_[begin % capacity_]);

					reader_lock_.unlock();

					return true;
				}

				reader_lock_.unlock();
				
				return false;
			}

			NCPP_FORCE_INLINE void reset() {

				begin_index_.store(0, eastl::memory_order_release);
				end_index_.store(0, eastl::memory_order_release);
			}



       public:
			friend std::ostream& operator << (
				std::ostream& os,
				const ncpp::TF_ostream_input<
                    TF_concurrent_ring_buffer
				>& input
			)
			{

				if (input.second > (ncpp::u32)NCPP_MAX_TAB_COUNT) {

					os << ncpp::T_cout_lowlight(L"...");

					return os;
				}

				os << NCPP_FOREGROUND_YELLOW << "concurrent_ring_buffer"
					<< ncpp::T_cout_lowlight("(")
					<< ncpp::T_cout_lowlight("size: ")
					<< ncpp::T_cout_value(input.first.size())
					<< ncpp::T_cout_lowlight(")")
					<< " ";

				os << ncpp::T_cout_lowlight("{") << std::endl;

				for (ncpp::u32 j = 0; j < (input.second + 1) * NCPP_TAB_SIZE; ++j) {

					os << " ";

				}
        		os << ncpp::T_cout_field_name("begin_index") << ncpp::T_cout_lowlight(" -> ") << ncpp::T_cout_value(input.first.begin_index()) << ncpp::T_cout_lowlight(",") << std::endl;

				for (ncpp::u32 j = 0; j < (input.second + 1) * NCPP_TAB_SIZE; ++j) {

					os << " ";

				}
        		os << ncpp::T_cout_field_name("end_index") << ncpp::T_cout_lowlight(" -> ") << ncpp::T_cout_value(input.first.end_index()) << ncpp::T_cout_lowlight(",") << std::endl;

				for (ncpp::u32 j = 0; j < (input.second + 1) * NCPP_TAB_SIZE; ++j) {

					os << " ";

				}
        		os << ncpp::T_cout_field_name("item_vector") << ncpp::T_cout_lowlight(" -> ");
				ncpp::T_safe_ostream_with_tab<
					ncpp::F_ostream,
					ncpp::TF_ostream_input<
						ncpp::TF_cout_value<F_item_vector>
					>
				>(
					os,
					ncpp::TF_ostream_input<
						ncpp::TF_cout_value<F_item_vector>
					> {
						ncpp::T_cout_value(input.first.item_vector_),
						input.second + 1
					}
				);

				os << std::endl;

				for (ncpp::u32 j = 0; j < (input.second) * NCPP_TAB_SIZE; ++j) {

					os << " ";

				}
				os << ncpp::T_cout_lowlight("}");

				return os;
			}

           	friend std::ostream& operator << (std::ostream& os, const TF_concurrent_ring_buffer& v)
			{

				os << ncpp::TF_ostream_input<TF_concurrent_ring_buffer> { v, 0 };

				return os;
			}



           	friend std::wostream& operator << (
				std::wostream& os,
				const ncpp::TF_ostream_input<
                    TF_concurrent_ring_buffer
				>& input
			)
			{

				if (input.second > (ncpp::u32)NCPP_MAX_TAB_COUNT) {

					os << ncpp::T_cout_lowlight(L"...");

					return os;
				}

				os << NCPP_FOREGROUND_YELLOW_TEXT << L"concurrent_ring_buffer"
					<< ncpp::T_cout_lowlight("(")
					<< ncpp::T_cout_lowlight("size: ")
					<< ncpp::T_cout_value(input.first.size())
					<< ncpp::T_cout_lowlight(")")
					<< L" ";

				os << ncpp::T_cout_lowlight(L"{") << std::endl;

				for (ncpp::u32 j = 0; j < (input.second + 1) * NCPP_TAB_SIZE; ++j) {

					os << L" ";

				}
        		os << ncpp::T_cout_field_name("begin_index") << ncpp::T_cout_lowlight(" -> ") << ncpp::T_cout_value(input.first.begin_index()) << ncpp::T_cout_lowlight(",") << std::endl;

				for (ncpp::u32 j = 0; j < (input.second + 1) * NCPP_TAB_SIZE; ++j) {

					os << L" ";

				}
        		os << ncpp::T_cout_field_name("end_index") << ncpp::T_cout_lowlight(" -> ") << ncpp::T_cout_value(input.first.end_index()) << ncpp::T_cout_lowlight(",") << std::endl;

				for (ncpp::u32 j = 0; j < (input.second + 1) * NCPP_TAB_SIZE; ++j) {

					os << L" ";

				}
        		os << ncpp::T_cout_field_name("item_vector") << ncpp::T_cout_lowlight(" -> ");
				ncpp::T_safe_ostream_with_tab<
					ncpp::F_wostream,
					ncpp::TF_ostream_input<
						ncpp::TF_cout_value<F_item_vector>
					>
				>(
					os,
					ncpp::TF_ostream_input<
						ncpp::TF_cout_value<F_item_vector>
					> {
						ncpp::T_cout_value(input.first.item_vector_),
						input.second + 1
					}
				);

				os << std::endl;

				for (ncpp::u32 j = 0; j < (input.second) * NCPP_TAB_SIZE; ++j) {

					os << L" ";

				}
				os << ncpp::T_cout_lowlight(L"}");

				return os;
			}

           	friend std::wostream& operator << (std::wostream& os, const TF_concurrent_ring_buffer& v)
			{

				os << ncpp::TF_ostream_input<TF_concurrent_ring_buffer> { v, 0 };

				return os;
			}

		};

        template<typename F_item__>
        using TG_concurrent_ring_buffer = TF_concurrent_ring_buffer<F_item__, mem::F_general_allocator>;
        template<typename F_item__>
        using TM_concurrent_ring_buffer = TF_concurrent_ring_buffer<F_item__, mem::F_ephemeral_allocator>;

        template<typename F_item__>
        using TV_concurrent_ring_buffer = TF_view<TG_concurrent_ring_buffer<F_item__>>;

	}

}

NCPP_CONTAINERS_DEFINE_ALLOCATOR_BINDING(
    NCPP_MA(ncpp::containers::TF_concurrent_ring_buffer<F_item__, F_allocator__>),
    NCPP_MA(F_allocator__),
    NCPP_MA(ncpp::containers::TF_concurrent_ring_buffer<F_item__, F_new_allocator__>),
    typename F_item__,
    typename F_allocator__
);

