#pragma once

/** @file ncpp/containers/string_utilities.hpp
*	@brief Implements string utilities.
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

#include <ncpp/containers/eastl_bindings.hpp>
#include <ncpp/containers/eastl_views.hpp>

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

        template<typename F_string__>
        inline std::enable_if_t<T_is_same_container_v<F_string__, F_string>, F_string__> T_replace(const F_string__& source, V_string from, V_string to) {

            F_string__ result = source;

            size_t start_pos = result.find(from);

            if(start_pos == std::string::npos)
                return false;

            result.replace(start_pos, from->length(), to);

            return result;
        }

        template<typename F_string__>
        inline std::enable_if_t<T_is_same_container_v<F_string__, F_string>, F_string__> T_replace_all(const F_string__& source, V_string from, V_string to) {

            if(from->empty())
                return source;

            F_string__ result = source;

            size_t start_pos = 0;

            while((start_pos = result.find(from, start_pos)) != std::string::npos) {

                result.replace(start_pos, from->length(), to);

                start_pos += to->length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'

            }

            return result;
        }

        template<typename F_string__ = F_string>
        inline F_string__ T_decimal_to_hex(i64 decimal_in) {

            std::basic_stringstream<typename F_string__::value_type> stream;
            stream << std::hex << decimal_in;

            return stream.str().c_str();
        }

    }

}