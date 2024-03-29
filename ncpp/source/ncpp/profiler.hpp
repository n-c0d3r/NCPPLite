#pragma once

/** @file ncpp/profiler.hpp
*	@brief Contains the memory management utilities.
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

#include <ncpp/utilities/unique_lock.hpp>
#include <ncpp/log.hpp>
#include <ncpp/iostream.hpp>

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

	class F_profiler_sample {

	public:
		using F_output_function = void(
            std::ostream& ostream,
            const eastl::string& name,
            const char* file_path_p,
            const char* function_name_p,
            u32 line,
            u64 nanoseconds
        );



	private:
        std::ostream& ostream_;

		eastl::string content_;
		F_output_function* output_function_p_ = 0;
		eastl::chrono::system_clock::time_point start_;

        const char* file_path_p_ = 0;
        const char* function_name_p_ = 0;
        u32 line_ = 0;



	public:
		NCPP_FORCE_INLINE const eastl::string& content() const { return content_; }
		NCPP_FORCE_INLINE F_output_function* output_function_p() const { return output_function_p_; }

        NCPP_FORCE_INLINE const char* file_path_p() const { return file_path_p_; }
        NCPP_FORCE_INLINE const char* function_name_p() const { return function_name_p_; }
        NCPP_FORCE_INLINE u32 line() const { return line_; }



	public:
		NCPP_FORCE_INLINE F_profiler_sample(
            std::ostream& ostream,
			const eastl::string& content = "",
            const char* file_path_p = 0,
            const char* function_name_p = 0,
            u32 line = 0,
			F_output_function* output_function_p = [](
                std::ostream& ostream,
                const eastl::string& content,
                const char* file_path_p,
                const char* function_name_p,
                u32 line,
                u64 nanoseconds
            ) {

                ostream

                << std::endl

                << E_log_color::V_FOREGROUND_BRIGHT_BLUE
                << "| SCOPED PROFILER SAMPLE | " << E_log_color::V_FOREGROUND_BRIGHT_MAGNETA << "END" << E_log_color::V_FOREGROUND_BRIGHT_BLUE << " |"

                << std::endl
                << T_cout_lowlight("| ")

                << content.c_str()

                << T_cout_lowlight(" |")
                << std::endl
                << T_cout_lowlight("| ")

                << T_cout_field_name("file") << T_cout_lowlight(" -> ") << T_cout_value(file_path_p)

                << T_cout_lowlight(" |")
                << std::endl
                << T_cout_lowlight("| ")

                << T_cout_field_name("function") << T_cout_lowlight(" -> ") << T_cout_value(function_name_p)

                << T_cout_lowlight(" |")
                << std::endl
                << T_cout_lowlight("| ")

                << T_cout_field_name("line") << T_cout_lowlight(" -> ") << T_cout_value(line)

                << T_cout_lowlight(" |")
                << std::endl
                << T_cout_lowlight("| ")

                << T_cout_field_name("nanoseconds") << T_cout_lowlight(" -> ") << F_cout_nanoseconds{nanoseconds}

                << T_cout_lowlight(" |")

                << E_log_color::RESET

                << std::endl
                << std::endl;

			}
		) :
			ostream_(ostream),
			content_(content),
			output_function_p_(output_function_p),
            file_path_p_(file_path_p),
            function_name_p_(function_name_p),
            line_(line)
		{

            ostream

            << E_log_color::V_FOREGROUND_BRIGHT_BLUE
            << "| SCOPED PROFILER SAMPLE | " << E_log_color::V_FOREGROUND_BRIGHT_YELLOW << "BEGIN" << E_log_color::V_FOREGROUND_BRIGHT_BLUE << " |"

            << std::endl
            << T_cout_lowlight("| ")

            << content.c_str()

            << T_cout_lowlight(" |")

            << std::endl;

			start_ = eastl::chrono::high_resolution_clock::now();

		}
		~F_profiler_sample() {

            u64 nanoseconds = eastl::chrono::duration_cast<eastl::chrono::nanoseconds>(
                eastl::chrono::high_resolution_clock::now() - start_
            ).count();

			output_function_p_(
                ostream_,
				content_,
                file_path_p_,
                function_name_p_,
                line_,
                nanoseconds
			);

		}

	};



#ifdef NCPP_ENABLE_SCOPED_PROFILER_SAMPLE
#define NCPP_SCOPED_PROFILER_SAMPLE_ADVANCED(OptionalOStream, Content) ncpp::F_profiler_sample NCPP_GLUE(___ncpp_profiler_sample___, __LINE__)(OptionalOStream, Content, NCPP_FILE, NCPP_FUNCTION, NCPP_LINE);
#else
#define NCPP_SCOPED_PROFILER_SAMPLE_ADVANCED(OptionalOStream, Content)
#endif

#define NCPP_SCOPED_PROFILER_SAMPLE(Content) NCPP_SCOPED_PROFILER_SAMPLE_ADVANCED(std::cout, Content)

}

