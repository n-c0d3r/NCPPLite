#pragma once

/** @file ncpp/rtti/subtype.hpp
*	@brief Implements subtype.
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

	namespace rtti {

        struct I_subtype_data {

            const char* fullname = 0;

            u64 hash_code = 0;

            u16 size = 0;
            u16 alignment = 0;

        };

        struct F_subtype_data final : public I_subtype_data {

            template<typename F__>
            static NCPP_FORCE_INLINE F_subtype_data T_default() noexcept {

                static constexpr u16 alignment = NCPP_ALIGNOF(NCPP_MA(utilities::TF_nth_template_arg<NCPP_MA(std::is_same_v<F__, void> || utilities::T_is_function<F__>), F__, u8>));

                return F_subtype_data {

                    {

                        utilities::T_type_fullname<F__>(),

                        utilities::T_type_hash_code<F__>,

                        utilities::T_sizeof<F__>,
                        alignment

                    }

                };
            }

        };

        template<typename F__, class F_subtype_data__ = F_subtype_data>
        static inline F_subtype_data__ T_default_subtype_data = F_subtype_data__::template T_default<F__>();



        template<typename F__ = void, typename F_subtype_data__ = F_subtype_data>
        class TF_subtype {

        public:
            template<typename F_other__, typename F_other_subtype_data__>
            friend class TF_subtype;

            template<typename F_other__>
            using TF_rebind = TF_subtype<F_other__, F_subtype_data__>;

            using F = F__;
            using F_subtype_data = F_subtype_data__;



        private:
            const F_subtype_data* data_p_ = 0;

        public:
            NCPP_FORCE_INLINE const F_subtype_data& data() const { return *data_p_; }

            NCPP_FORCE_INLINE b8 is_default() const { return (data_p_ == (&T_default_subtype_data<F__, F_subtype_data__>)); }



        public:
            NCPP_FORCE_INLINE TF_subtype() noexcept :
                data_p_(&T_default_subtype_data<F__, F_subtype_data__>)
            {

            }
            NCPP_FORCE_INLINE ~TF_subtype() noexcept {

                reset();
            }



        private:
            NCPP_FORCE_INLINE TF_subtype(const F_subtype_data* data_p) noexcept :
                data_p_(data_p_)
            {

            }



        public:
            template<typename F_other__, std::enable_if_t<std::is_convertible_v<F_other__, F__> || std::is_same_v<F__, void>, i32> = 0>
            NCPP_FORCE_INLINE TF_subtype(const TF_subtype<F_other__, F_subtype_data__>& x) noexcept :
                data_p_(x.data_p_)
            {

            }
            template<typename F_other__, std::enable_if_t<std::is_convertible_v<F_other__, F__> || std::is_same_v<F__, void>, i32> = 0>
            NCPP_FORCE_INLINE TF_subtype& operator = (const TF_subtype<F_other__, F_subtype_data__>& x) noexcept {

                data_p_ = x.data_p_;

                return *this;
            }



        public:
            template<typename F_other__, std::enable_if_t<std::is_convertible_v<F_other__, F__> || std::is_same_v<F__, void>, i32> = 0>
            NCPP_FORCE_INLINE TF_subtype(TF_subtype<F_other__, F_subtype_data__>&& x) noexcept :
                data_p_(x.data_p_)
            {

                x.reset();
            }
            template<typename F_other__, std::enable_if_t<std::is_convertible_v<F_other__, F__> || std::is_same_v<F__, void>, i32> = 0>
            NCPP_FORCE_INLINE TF_subtype& operator = (TF_subtype<F_other__, F_subtype_data__>&& x) noexcept {

                data_p_ = x.data_p_;

                x.reset();

                return *this;
            }



        public:
            template<typename F_other__, std::enable_if_t<std::is_convertible_v<F_other__, F__> || std::is_same_v<F__, void>, i32> = 0>
            NCPP_FORCE_INLINE b8 operator == (const TF_subtype<F_other__, F_subtype_data__>& x) const noexcept {

                return (((sz)data_p_) == ((sz)x.data_p_));
            }
            template<typename F_other__, std::enable_if_t<std::is_convertible_v<F_other__, F__> || std::is_same_v<F__, void>, i32> = 0>
            NCPP_FORCE_INLINE b8 operator != (const TF_subtype<F_other__, F_subtype_data__>& x) const noexcept {

                return (((sz)data_p_) != ((sz)x.data_p_));
            }



        public:
            NCPP_FORCE_INLINE void reset() noexcept {

                data_p_ = &T_default_subtype_data<F__, F_subtype_data__>;
            }
            template<typename F_other__>
            NCPP_FORCE_INLINE TF_subtype<F_other__, F_subtype_data> T_cast() const noexcept {

                if constexpr (std::is_convertible_v<F_other__, F__> || std::is_convertible_v<F__, F_other__> || std::is_same_v<F_other__, void>)
                    return data_p_;

                return &T_default_subtype_data<F_other__, F_subtype_data__>;
            }

        };

        using F_subtype = TF_subtype<>;

	}

}



namespace ncpp {

    namespace containers {

        template<typename F__, typename F_subtype_data__>
        struct TF_hash<rtti::TF_subtype<F__, F_subtype_data__>> {

            inline size_t operator()(rtti::TF_subtype<F__, F_subtype_data__> x) const
            {

                return x.data().hash_code;
            }

        };

    }

}