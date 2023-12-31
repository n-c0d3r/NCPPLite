#pragma once

/** @file ncpp/declare_alloc_debug_info_operators.hpp
*	@brief Declares alloc debug info
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



#ifdef NCPP_HAS_ALLOC_DEBUG_INFO
namespace ncpp::mem {

    struct NCPP_ALIGN(EASTL_ALLOCATOR_MIN_ALIGNMENT) F_alloc_debug_info;

}

std::ostream& operator << (std::ostream& os, const ncpp::TF_ostream_input<ncpp::mem::F_alloc_debug_info>& debug_info);
std::ostream& operator << (std::ostream& os, const ncpp::mem::F_alloc_debug_info& debug_info);
std::wostream& operator << (std::wostream& os, const ncpp::TF_ostream_input<ncpp::mem::F_alloc_debug_info>& debug_info);
std::wostream& operator << (std::wostream& os, const ncpp::mem::F_alloc_debug_info& debug_info);
#endif