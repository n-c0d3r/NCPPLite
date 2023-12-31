#pragma once

/** @file ncpp/declare_eastl_container_operators.hpp
*	@brief Declares eastl container operators.
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

#include <ncpp/ostream_input.hpp>

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



#pragma region String
/**
 *	Streams out containers::F_string.
 */
template<class F_allocator__>
std::ostream& operator << (std::ostream& os, const eastl::basic_string<char, F_allocator__>& str);
/**
 *    Streams out containers::F_wstring.
 */
template<class F_allocator__>
std::ostream& operator << (std::ostream& os, const eastl::basic_string<wchar_t, F_allocator__>& str);
/**
 *    Streams out const wchar_t*.
 */
std::ostream& operator << (std::ostream& os, const wchar_t* str);

/**
 *	Streams out containers::F_wstring.
 */
template<class F_allocator__>
std::wostream& operator << (std::wostream& os, const eastl::basic_string<wchar_t, F_allocator__>& str);
/**
 *    Streams out containers::F_string.
 */
template<class F_allocator__>
std::wostream& operator << (std::wostream& os, const eastl::basic_string<char, F_allocator__>& str);
/**
 *    Streams out const char*.
 */
std::wostream& operator << (std::wostream& os, const char* str);
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



#pragma region Vector
/**
 *	Streams out eastl::vector with tabs.
 */
template<typename F_item__, class F_allocator__>
std::ostream& operator << (
	std::ostream& os,
	const ncpp::TF_ostream_input<
		eastl::vector<F_item__, F_allocator__>
	>& input
);

/**
 *	Streams out eastl::vector with no tab.
 */
template<typename F_item__, class F_allocator__>
std::ostream& operator << (std::ostream& os, const eastl::vector<F_item__, F_allocator__>& v);



/**
 *    Streams out eastl::vector with tabs.
 */
template<typename F_item__, class F_allocator__>
std::wostream& operator << (
    std::wostream& os,
    const ncpp::TF_ostream_input<
        eastl::vector<F_item__, F_allocator__>
    >& input
);

/**
 *    Streams out eastl::vector with no tab.
 */
template<typename F_item__, class F_allocator__>
std::wostream& operator << (std::wostream& os, const eastl::vector<F_item__, F_allocator__>& v);
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



#pragma region Initialier List
/**
 *	Streams out std::initialier_list<T> with tabs.
 */
template<typename F_item__>
std::ostream& operator << (
	std::ostream& os,
	const ncpp::TF_ostream_input<
		std::initializer_list<F_item__>
	>& input
);

/**
 *	Streams out std::initialier_list<T> with no tab.
 */
template<typename F_item__>
std::ostream& operator << (std::ostream& os, const std::initializer_list<F_item__>& v);



/**
 *    Streams out std::initialier_list<T> with tabs.
 */
template<typename F_item__>
std::wostream& operator << (
    std::wostream& os,
    const ncpp::TF_ostream_input<
        std::initializer_list<F_item__>
    >& input
);

/**
 *    Streams out std::initialier_list<T> with no tab.
 */
template<typename F_item__>
std::wostream& operator << (std::wostream& os, const std::initializer_list<F_item__>& v);
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



#pragma region Array
/**
 *	Streams out eastl::array<T, N> with tabs.
 */
template<typename F_item__, ncpp::sz size__>
std::ostream& operator << (
	std::ostream& os,
	const ncpp::TF_ostream_input<
		eastl::array<F_item__, size__>
	>& input
);

/**
 *	Streams out eastl::array<T, N> with no tab.
 */
template<typename F_item__, ncpp::sz size__>
std::ostream& operator << (std::ostream& os, const eastl::array<F_item__, size__>& v);



/**
 *    Streams out eastl::array<T, N> with tabs.
 */
template<typename F_item__, ncpp::sz size__>
std::wostream& operator << (
    std::wostream& os,
    const ncpp::TF_ostream_input<
        eastl::array<F_item__, size__>
    >& input
);

/**
 *    Streams out eastl::array<T, N> with no tab.
 */
template<typename F_item__, ncpp::sz size__>
std::wostream& operator << (std::wostream& os, const eastl::array<F_item__, size__>& v);
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



#pragma region Span
template<typename F_item__>
std::ostream& operator << (
	std::ostream& os,
	const ncpp::TF_ostream_input<
		eastl::span<F_item__>
	>& input
);

template<typename F_item__>
std::ostream& operator << (std::ostream& os, const eastl::span<F_item__>& v);



template<typename F_item__>
std::wostream& operator << (
    std::wostream& os,
    const ncpp::TF_ostream_input<
        eastl::span<F_item__>
    >& input
);

template<typename F_item__>
std::wostream& operator << (std::wostream& os, const eastl::span<F_item__>& v);
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



#pragma region List
template<typename F_item__, typename F_allocator__>
std::ostream& operator << (
	std::ostream& os,
	const ncpp::TF_ostream_input<
		eastl::list<F_item__, F_allocator__>
	>& input
);

template<typename F_item__, typename F_allocator__>
std::ostream& operator << (std::ostream& os, const eastl::list<F_item__, F_allocator__>& v);



template<typename F_item__, typename F_allocator__>
std::wostream& operator << (
    std::wostream& os,
    const ncpp::TF_ostream_input<
        eastl::list<F_item__, F_allocator__>
    >& input
);

template<typename F_item__, typename F_allocator__>
std::wostream& operator << (std::wostream& os, const eastl::list<F_item__, F_allocator__>& v);
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



#pragma region Deque
template<typename F_item__, typename F_allocator__, unsigned subarray_size__ = DEQUE_DEFAULT_SUBARRAY_SIZE(F_item__)>
std::ostream& operator << (
	std::ostream& os,
	const ncpp::TF_ostream_input<
		eastl::deque<F_item__, F_allocator__, subarray_size__>
	>& input
);

template<typename F_item__, typename F_allocator__, unsigned subarray_size__ = DEQUE_DEFAULT_SUBARRAY_SIZE(F_item__)>
std::ostream& operator << (std::ostream& os, const eastl::deque<F_item__, F_allocator__, subarray_size__>& v);



template<typename F_item__, typename F_allocator__, unsigned subarray_size__ = DEQUE_DEFAULT_SUBARRAY_SIZE(F_item__)>
std::wostream& operator << (
    std::wostream& os,
    const ncpp::TF_ostream_input<
        eastl::deque<F_item__, F_allocator__, subarray_size__>
    >& input
);

template<typename F_item__, typename F_allocator__, unsigned subarray_size__ = DEQUE_DEFAULT_SUBARRAY_SIZE(F_item__)>
std::wostream& operator << (std::wostream& os, const eastl::deque<F_item__, F_allocator__, subarray_size__>& v);
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



#pragma region List
template<typename F_item__, typename F_allocator__>
std::ostream& operator << (
	std::ostream& os,
	const ncpp::TF_ostream_input<
		eastl::list<F_item__, F_allocator__>
	>& input
);

template<typename F_item__, typename F_allocator__>
std::ostream& operator << (std::ostream& os, const eastl::list<F_item__, F_allocator__>& v);



template<typename F_item__, typename F_allocator__>
std::wostream& operator << (
    std::wostream& os,
    const ncpp::TF_ostream_input<
        eastl::list<F_item__, F_allocator__>
    >& input
);

template<typename F_item__, typename F_allocator__>
std::wostream& operator << (std::wostream& os, const eastl::list<F_item__, F_allocator__>& v);
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



#pragma region Set
template<typename F_item__, typename F_compare__, typename F_allocator__>
std::ostream& operator << (
	std::ostream& os,
	const ncpp::TF_ostream_input<
		eastl::set<F_item__, F_compare__, F_allocator__>
	>& input
);

template<typename F_item__, typename F_compare__, typename F_allocator__>
std::ostream& operator << (std::ostream& os, const eastl::set<F_item__, F_compare__, F_allocator__>& v);



template<typename F_item__, typename F_compare__, typename F_allocator__>
std::wostream& operator << (
    std::wostream& os,
    const ncpp::TF_ostream_input<
        eastl::set<F_item__, F_compare__, F_allocator__>
    >& input
);

template<typename F_item__, typename F_compare__, typename F_allocator__>
std::wostream& operator << (std::wostream& os, const eastl::set<F_item__, F_compare__, F_allocator__>& v);
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



#pragma region Map
template<typename F_key__, typename F_value__, typename F_compare__, typename F_allocator__>
std::ostream& operator << (
	std::ostream& os,
	const ncpp::TF_ostream_input<
		eastl::map<F_key__, F_value__, F_compare__, F_allocator__>
	>& input
);

template<typename F_key__, typename F_value__, typename F_compare__, typename F_allocator__>
std::ostream& operator << (std::ostream& os, const eastl::map<F_key__, F_value__, F_compare__, F_allocator__>& v);



template<typename F_key__, typename F_value__, typename F_compare__, typename F_allocator__>
std::wostream& operator << (
    std::wostream& os,
    const ncpp::TF_ostream_input<
        eastl::map<F_key__, F_value__, F_compare__, F_allocator__>
    >& input
);

template<typename F_key__, typename F_value__, typename F_compare__, typename F_allocator__>
std::wostream& operator << (std::wostream& os, const eastl::map<F_key__, F_value__, F_compare__, F_allocator__>& v);
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



#pragma region Unordered Set
template<typename F_item__, typename F_hash__, typename F_predicate__, typename F_allocator__>
std::ostream& operator << (
	std::ostream& os,
	const ncpp::TF_ostream_input<
		eastl::unordered_set<F_item__, F_hash__, F_predicate__, F_allocator__>
	>& input
);

template<typename F_item__, typename F_hash__, typename F_predicate__, typename F_allocator__>
std::ostream& operator << (std::ostream& os, const eastl::unordered_set<F_item__, F_hash__, F_predicate__, F_allocator__>& v);



template<typename F_item__, typename F_hash__, typename F_predicate__, typename F_allocator__>
std::wostream& operator << (
    std::wostream& os,
    const ncpp::TF_ostream_input<
        eastl::unordered_set<F_item__, F_hash__, F_predicate__, F_allocator__>
    >& input
);

template<typename F_item__, typename F_hash__, typename F_predicate__, typename F_allocator__>
std::wostream& operator << (std::wostream& os, const eastl::unordered_set<F_item__, F_hash__, F_predicate__, F_allocator__>& v);
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



#pragma region Unordered Map
template<typename F_key__, typename F_value__, typename F_hash__, typename F_predicate__, typename F_allocator__>
std::ostream& operator << (
	std::ostream& os,
	const ncpp::TF_ostream_input<
		eastl::unordered_map<F_key__, F_value__, F_hash__, F_predicate__, F_allocator__>
	>& input
);

template<typename F_key__, typename F_value__, typename F_hash__, typename F_predicate__, typename F_allocator__>
std::ostream& operator << (std::ostream& os, const eastl::unordered_map<F_key__, F_value__, F_hash__, F_predicate__, F_allocator__>& v);



template<typename F_key__, typename F_value__, typename F_hash__, typename F_predicate__, typename F_allocator__>
std::wostream& operator << (
    std::wostream& os,
    const ncpp::TF_ostream_input<
        eastl::unordered_map<F_key__, F_value__, F_hash__, F_predicate__, F_allocator__>
    >& input
);

template<typename F_key__, typename F_value__, typename F_hash__, typename F_predicate__, typename F_allocator__>
std::wostream& operator << (std::wostream& os, const eastl::unordered_map<F_key__, F_value__, F_hash__, F_predicate__, F_allocator__>& v);
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



#pragma region Queue
template<typename F_item__, typename F_container__>
std::ostream& operator << (
	std::ostream& os,
	const ncpp::TF_ostream_input<
		eastl::queue<F_item__, F_container__>
	>& input
);

template<typename F_item__, typename F_container__>
std::ostream& operator << (std::ostream& os, const eastl::queue<F_item__, F_container__>& v);



template<typename F_item__, typename F_container__>
std::wostream& operator << (
    std::wostream& os,
    const ncpp::TF_ostream_input<
        eastl::queue<F_item__, F_container__>
    >& input
);

template<typename F_item__, typename F_container__>
std::wostream& operator << (std::wostream& os, const eastl::queue<F_item__, F_container__>& v);
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



#pragma region Stack
template<typename F_item__, typename F_container__>
std::ostream& operator << (
	std::ostream& os,
	const ncpp::TF_ostream_input<
		eastl::stack<F_item__, F_container__>
	>& input
);

template<typename F_item__, typename F_container__>
std::ostream& operator << (std::ostream& os, const eastl::stack<F_item__, F_container__>& v);



template<typename F_item__, typename F_container__>
std::wostream& operator << (
    std::wostream& os,
    const ncpp::TF_ostream_input<
        eastl::stack<F_item__, F_container__>
    >& input
);

template<typename F_item__, typename F_container__>
std::wostream& operator << (std::wostream& os, const eastl::stack<F_item__, F_container__>& v);
#pragma endregion


