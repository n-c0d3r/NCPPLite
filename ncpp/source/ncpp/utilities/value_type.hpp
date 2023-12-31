#pragma once

/**
 *  @file ncpp/utilities/value_type.hpp
 *  @brief Implements value_type.
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

        namespace internal {

            template<class F__>
            concept T_is_has_eastl_value_type = requires { typename F__::value_type; };

            template<class F__>
            concept T_is_has_ncpp_value_type = requires { typename F__::F_value; };

            template<class F__, i32 = 0>
            struct TF_value_helper {

                using F = void;

            };

            template<class F__>
            struct TF_value_helper<F__, 1> {

                using F = typename F__::value_type;

            };

            template<class F__>
            struct TF_value_helper<F__, 2> {

                using F = typename F__::F_value;

            };

        }
        


        template<class F__>
        using TF_value = typename internal::TF_value_helper<
            F__,
            internal::T_is_has_eastl_value_type<F__> * 1
            + internal::T_is_has_ncpp_value_type<F__> * 2
        >::F;

        template<class F__>
        static constexpr b8 T_is_has_value = (
            internal::T_is_has_eastl_value_type<F__>
            || internal::T_is_has_ncpp_value_type<F__>
        );

    }

}