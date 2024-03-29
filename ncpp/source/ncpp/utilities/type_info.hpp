#pragma once

/**
 *  @file ncpp/utilities/type_info.hpp
 *  @brief Implements type info.
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

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#include <ncpp/prerequisites.hpp>

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#include <ncpp/rtti/security_helper.hpp>

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

    namespace utilities {



        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



        namespace internal {

            template<typename F__>
            constexpr u64 T_type_hash_code(){

                u64 result{0};

#ifdef _MSC_VER
#define CURRENT_FUNCTION_SIGNATURE __FUNCSIG__
#else
#define CURRENT_FUNCTION_SIGNATURE __PRETTY_FUNCTION__
#endif

                for (const auto &c : CURRENT_FUNCTION_SIGNATURE)
                    (result ^= c) <<= 1;

#undef CURRENT_FUNCTION_SIGNATURE

                return result;
            }

        }

        template<typename F__>
        constexpr u64 T_type_hash_code = internal::T_type_hash_code<F__>();



        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



        namespace internal {

            template <std::size_t...Idxs>
            constexpr auto substring_as_array(std::string_view str, std::index_sequence<Idxs...>)
            {
                return std::array{str[Idxs]...};
            }

            template <typename T>
            constexpr auto type_name_array()
            {
#if defined(__clang__)
                constexpr auto prefix   = std::string_view{"[T = "};
                constexpr auto suffix   = std::string_view{"]"};
                constexpr auto function = std::string_view{__PRETTY_FUNCTION__};
#elif defined(__GNUC__)
                constexpr auto prefix   = std::string_view{"with T = "};
                constexpr auto suffix   = std::string_view{"]"};
                constexpr auto function = std::string_view{__PRETTY_FUNCTION__};
#elif defined(_MSC_VER)
                constexpr auto prefix   = std::string_view{"type_name_array<"};
                constexpr auto suffix   = std::string_view{">(void)"};
                constexpr auto function = std::string_view{__FUNCSIG__};
#else
                # error Unsupported compiler
#endif

                constexpr auto start = function.find(prefix) + prefix.size();
                constexpr auto end = function.rfind(suffix);

                NCPP_STATIC_ASSERT(start < end);

                constexpr auto name = function.substr(start, (end - start));
                return substring_as_array(name, std::make_index_sequence<name.size()>{});
            }

            template <typename T>
            struct type_name_holder {
                static inline constexpr auto value = type_name_array<T>();
            };

            template <typename T>
            constexpr auto type_name() -> std::string_view
            {
                constexpr auto& value = type_name_holder<T>::value;
                return std::string_view{value.data(), value.size()};
            }

            template<typename F_char__>
            struct F_type_name_char_flag {};
            NCPP_FORCE_INLINE std::string type_name_char_convert(std::string&& str, F_type_name_char_flag<char>){

                return str;
            }
            NCPP_FORCE_INLINE std::string type_name_char_convert(std::wstring&& str, F_type_name_char_flag<char>){

                std::string value;
                value.resize(str.size());

                for(sz i = 0; i < str.length(); ++i)
                    value[i] = static_cast<char>(str[i]);

                return value;
            }
            NCPP_FORCE_INLINE std::wstring type_name_char_convert(std::wstring&& str, F_type_name_char_flag<wchar_t>){

                return str;
            }
            NCPP_FORCE_INLINE std::wstring type_name_char_convert(std::string&& str, F_type_name_char_flag<wchar_t>){

                std::wstring value;
                value.resize(str.size());

                for(sz i = 0; i < str.length(); ++i)
                    value[i] = static_cast<wchar_t>(str[i]);

                return value;
            }

        }



#ifdef NCPP_RTTI_SECURED_NAME
        template<typename F__, typename F_char__ = char>
        const F_char__* T_type_fullname() {

            static std::basic_string<F_char__> static_str = ((F_char__)'_') + (std::basic_stringstream<F_char__>() << T_type_hash_code<F__>).str();

            return static_str.c_str();
        }
#else
        template<typename F__, typename F_char__ = char>
        const F_char__* T_type_fullname() {

            static std::basic_string<F_char__> static_str = (std::basic_stringstream<F_char__>() << internal::type_name<F__>()).str();

            return static_str.c_str();
        }
#endif

    }

}
