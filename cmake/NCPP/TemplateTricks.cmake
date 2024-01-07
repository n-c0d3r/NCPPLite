
message(STATUS "<NCPP::TemplateTricks> Start generating template tricks")



#####################################################################################
#   Includes
#####################################################################################
include(NCPP/Utilities/SetGlobal)



#####################################################################################
#   Setup global variables
#####################################################################################
set(NCPP_TEMPLATE_TRICKS_MAX_ARG_COUNT 128 CACHE STRING "Max argument count of template tricks")



#####################################################################################
#   Setup the generated file
#####################################################################################
set(NCPP_TEMPLATE_TRICKS_FILE "${NCPP_GENERATED_FILES_DIR}/template_tricks.hpp")
file(WRITE ${NCPP_TEMPLATE_TRICKS_FILE} "\n
    #pragma once
    #include <ncpp/prerequisites.hpp>\n
    namespace ncpp::utilities {
")



#####################################################################################
#   N-th template argument
#####################################################################################
function(NCPP_TemplateTricks_CreateTemplate_NthTemplateArg MaxArgCount)

    set(fileContent " namespace internal { \n")

    set(fileContent "${fileContent} template<sz index__, typename... F_args__> struct TF_nth_template_targ_getter_helper; \n")

    MATH(EXPR maxIndex "${MaxArgCount} - 1")

    set(template_targs "typename arg_0__")
    set(pass_template_targs "arg_0__")

    foreach(index RANGE 0 ${maxIndex})

        if(NOT index EQUAL 0)
            set(template_targs "${template_targs}, typename arg_${index}__")
            set(pass_template_targs "${pass_template_targs}, arg_${index}__")
        endif()

        set(fileContent "${fileContent} template<${template_targs}, typename... F_rest_args__>
            struct TF_nth_template_targ_getter_helper<${index}, ${pass_template_targs}, F_rest_args__...> { using F = arg_${index}__; };
        ")

    endforeach()

    set(fileContent "${fileContent} template<sz index__, typename... F_args__>
        struct TF_nth_template_targ_helper {
            static_assert((index__ < sizeof...(F_args__)), \"out of bound\");
            using F = typename TF_nth_template_targ_getter_helper<index__, F_args__...>::F;
         };
    ")

    set(fileContent "${fileContent} } \n")

    set(fileContent "${fileContent}
        template<sz index__, typename... F_args__>
        using TF_nth_template_targ = typename internal::TF_nth_template_targ_helper<index__, F_args__...>::F;
         \n
    ")

    file(APPEND ${NCPP_TEMPLATE_TRICKS_FILE} "${fileContent}")

endfunction()

NCPP_TemplateTricks_CreateTemplate_NthTemplateArg(${NCPP_TEMPLATE_TRICKS_MAX_ARG_COUNT})



#####################################################################################
#   Remove head template args
#####################################################################################
function(NCPP_TemplateTricks_CreateTemplate_RemoveHeadTemplateArgs MaxArgCount)

    set(fileContent "
        template<typename... F_args__> struct TF_template_targ_list;

        namespace internal {
        \n
    ")

    set(fileContent "${fileContent} template<sz count__, typename... F_args__> struct TF_remove_head_template_targs_getter_helper; \n")

    MATH(EXPR maxIndex "${MaxArgCount} - 1")

    set(template_targs "")
    set(pass_template_targs "")

    foreach(index RANGE 0 ${maxIndex})

        set(fileContent "${fileContent} template<${template_targs} typename... F_rest_args__>
            struct TF_remove_head_template_targs_getter_helper<${index}, ${pass_template_targs} F_rest_args__...> { using F = TF_template_targ_list<F_rest_args__...>; };
        ")

        set(template_targs "${template_targs} typename arg_${index}__,")
        set(pass_template_targs "${pass_template_targs} arg_${index}__,")

    endforeach()

    set(fileContent "${fileContent} template<sz count__, typename... F_args__>
        struct TF_remove_head_template_targs_helper {
            static_assert((count__ <= sizeof...(F_args__)), \"out of bound\");
            using F = typename TF_remove_head_template_targs_getter_helper<count__, F_args__...>::F;
         };
    ")

    set(fileContent "${fileContent} } \n")

    set(fileContent "${fileContent}
        template<sz count__, typename... F_args__>
        using TF_remove_head_template_targs = typename internal::TF_remove_head_template_targs_helper<count__, F_args__...>::F;
         \n
    ")

    file(APPEND ${NCPP_TEMPLATE_TRICKS_FILE} "${fileContent}")

endfunction()

NCPP_TemplateTricks_CreateTemplate_RemoveHeadTemplateArgs(${NCPP_TEMPLATE_TRICKS_MAX_ARG_COUNT})



#####################################################################################
#   Remove tail template args
#####################################################################################
function(NCPP_TemplateTricks_CreateTemplate_RemoveTailTemplateArgs MaxArgCount)

    set(fileContent "
        template<typename... F_args__> struct TF_template_targ_list;

        namespace internal {
        \n
    ")

    set(fileContent "${fileContent} template<sz remain_count__, typename... F_args__> struct TF_remove_tail_template_targs_getter_helper; \n")

    MATH(EXPR maxIndex "${MaxArgCount} - 1")

    set(template_targs "")
    set(pass_template_targs "")

    foreach(index RANGE 0 ${maxIndex})

        set(template_targs_2 "${template_targs}")
        set(pass_template_targs_2 "${pass_template_targs}")

        if(NOT index EQUAL 0)
            set(template_targs_2 "${template_targs_2},")
            set(pass_template_targs_2 "${pass_template_targs_2},")
        endif()

        set(fileContent "${fileContent} template<${template_targs_2} typename... F_rest_args__>
            struct TF_remove_tail_template_targs_getter_helper<${index}, ${pass_template_targs_2} F_rest_args__...> { using F = TF_template_targ_list<${pass_template_targs}>; };
        ")

        if(NOT index EQUAL 0)
            set(template_targs "${template_targs},")
            set(pass_template_targs "${pass_template_targs},")
        endif()

        set(template_targs "${template_targs} typename arg_${index}__")
        set(pass_template_targs "${pass_template_targs} arg_${index}__")

    endforeach()

    set(fileContent "${fileContent} template<sz count__, typename... F_args__>
        struct TF_remove_tail_template_targs_helper {
            static_assert((count__ <= sizeof...(F_args__)), \"out of bound\");
            using F = typename TF_remove_tail_template_targs_getter_helper<(sizeof...(F_args__)) - count__, F_args__...>::F;
         };
    ")

    set(fileContent "${fileContent} } \n")

    set(fileContent "${fileContent}
        template<sz count__, typename... F_args__>
        using TF_remove_tail_template_targs = typename internal::TF_remove_tail_template_targs_helper<count__, F_args__...>::F;
         \n
    ")

    file(APPEND ${NCPP_TEMPLATE_TRICKS_FILE} "${fileContent}")

endfunction()

NCPP_TemplateTricks_CreateTemplate_RemoveTailTemplateArgs(${NCPP_TEMPLATE_TRICKS_MAX_ARG_COUNT})



#####################################################################################
#   Finalize the generated file
#####################################################################################
file(APPEND ${NCPP_TEMPLATE_TRICKS_FILE} "\n
    }
")



message(STATUS "<NCPP::TemplateTricks> Generate template tricks done")