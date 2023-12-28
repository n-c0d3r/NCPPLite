#pragma once

/** @file ncpp/iostream.hpp
*	@brief Implement iostream with custom allocators,...
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

#ifdef NCPP_ENABLE_MEMORY_COUNTING
#include <ncpp/mem/memory_counting.hpp>
#endif

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#include <ncpp/utilities/is_streamable.hpp>
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



namespace ncpp {



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

        template<typename F_char__ = char>
        struct TF_ostream_helper {
            
            using F = std::ostream;
            
            static NCPP_FORCE_INLINE F& cout() { return std::cout; }
            
        };
    
        template<>
        struct TF_ostream_helper<wchar_t> {
            
            using F = std::wostream;
            
            static NCPP_FORCE_INLINE F& cout() { return std::wcout; }
            
        };

        template<typename F_char__ = char>
        struct TF_istream_helper {
            
            using F = std::istream;
            
            static NCPP_FORCE_INLINE F& cin() { return std::cin; }
            
        };
    
        template<>
        struct TF_istream_helper<wchar_t> {
            
            using F = std::wistream;
            
            static NCPP_FORCE_INLINE F& cin() { return std::wcin; }
            
        };

    }

    template<typename F_char__ = char>
    using TF_ostream = typename internal::TF_ostream_helper<F_char__>::F;
    using F_ostream = TF_ostream<char>;
    using F_wostream = TF_ostream<wchar_t>;

    template<typename F_char__ = char>
    inline TF_ostream<F_char__>& T_cout = internal::TF_ostream_helper<F_char__>::cout();
    inline F_ostream& cout = internal::TF_ostream_helper<char>::cout();
    inline F_wostream& wcout = internal::TF_ostream_helper<wchar_t>::cout();

    template<typename F_char__ = char>
    using TF_istream = typename internal::TF_istream_helper<F_char__>::F;
    using F_istream = TF_istream<char>;
    using F_wistream = TF_istream<wchar_t>;

    template<typename F_char__ = char>
    inline TF_istream<F_char__>& T_cin = internal::TF_istream_helper<F_char__>::cin();
    inline F_istream& cin = internal::TF_istream_helper<char>::cin();
    inline F_wistream& wcin = internal::TF_istream_helper<wchar_t>::cin();



	// \cond INTERNAL
	template<typename F_stream__, typename F__, b8 is_streamable__>
	struct TF_safe_ostream_forwarder {

	};

	template<typename F_stream__, typename F__>
	struct TF_safe_ostream_forwarder<F_stream__, F__, true> {

		static NCPP_FORCE_INLINE F_stream__& forward(F_stream__& stream, const F__& data) {

			stream << data;

			return stream;
		}
	};

	template<typename F_stream__, typename F__>
	struct TF_safe_ostream_forwarder<F_stream__, F__, false> {

		static NCPP_FORCE_INLINE F_stream__& forward(F_stream__& stream, const F__& data) {



			return stream;
		}
	};
	// \endcond



	/**
	 *	Performs the out streaming operation safely.
	 *	If data is out streamable, stream out the data.
	 *	Otherwise, do nothing and wont cause any error.
	 */
	template<typename F_stream__, typename F__>
	NCPP_FORCE_INLINE F_stream__& T_safe_ostream(F_stream__& stream, const F__& data) {

		using safe_ostream_forward_type = TF_safe_ostream_forwarder<
			F_stream__,
			F__,
			utilities::T_is_ostreamable_v<
				F_stream__,
				F__
			>
		>;
			
		return safe_ostream_forward_type::forward(stream, data);
	}



	// \cond INTERNAL
	template<typename F_stream__, typename input_type__, b8 is_streamable__>
	struct TF_safe_ostream_with_tab_forwarder {

	};

	template<typename F_stream__, typename input_type__>
	struct TF_safe_ostream_with_tab_forwarder<F_stream__, input_type__, true> {

		static NCPP_FORCE_INLINE F_stream__& forward(F_stream__& stream, const input_type__& input) {

			stream << input;

			return stream;
		}
	};

	template<typename F_stream__, typename input_type__>
	struct TF_safe_ostream_with_tab_forwarder<F_stream__, input_type__, false> {

		static NCPP_FORCE_INLINE F_stream__& forward(F_stream__& stream, const input_type__& input) {

			T_safe_ostream(stream, input.first);

			return stream;
		}
	};
	// \endcond



	/**
	 *	Performs the out streaming operation safely with tabs.
	 *	If data is out streamable, stream out the data with tabs.
	 *	Otherwise, do nothing and wont cause any error.
	 */
	template<typename F_stream__, typename F__, typename input_type__ = TF_ostream_input<F__>>
	NCPP_FORCE_INLINE F_stream__& T_safe_ostream_with_tab(F_stream__& stream, const input_type__& input) {

		using safe_ostream_with_tab_forward_type = TF_safe_ostream_with_tab_forwarder<
			F_stream__,
			input_type__,
			utilities::T_is_ostreamable_v<
				F_stream__,
				input_type__
			>
		>;

		return safe_ostream_with_tab_forward_type::forward(stream, input);
	}



	// \cond INTERNAL
	template<typename F_stream__, typename F__, b8 is_streamable__>
	struct TF_safe_istream_forwarder {

	};

	template<typename F_stream__, typename F__>
	struct TF_safe_istream_forwarder<F_stream__, F__, true> {

		static NCPP_FORCE_INLINE F_stream__& forward(F_stream__& stream, F__&& data) {

			stream >> data;

			return stream;
		}
	};

	template<typename F_stream__, typename F__>
	struct TF_safe_istream_forwarder<F_stream__, F__, false> {

		static NCPP_FORCE_INLINE F_stream__& forward(F_stream__& stream, F__&& data) {



			return stream;
		}
	};
	// \endcond



	/**
	 *	Performs the in streaming operation safely.
	 *	If data is in streamable, stream in the data.
	 *	Otherwise, do nothing and wont cause any error.
	 */
	template<typename F_stream__, typename F__>
	NCPP_FORCE_INLINE F_stream__& T_safe_istream(F_stream__& stream, F__&& data) {

		using safe_istream_forward_type = TF_safe_istream_forwarder<
			F_stream__,
			F__,
			utilities::T_is_istreamable_v<
				F_stream__,
				F__
			>
		>;

		return safe_istream_forward_type::forward(stream, std::forward<F__>(data));
	}

}

