
set(NCPP_ROOT_DIR "${CMAKE_CURRENT_LIST_DIR}/../../..")

if(NOT NCPP_LITE_DISTRIBUTION_DIR)
    set(NCPP_LITE_DISTRIBUTION_DIR "${NCPP_ROOT_DIR}/build/generated_distributions/ncpp_lite")
endif()



file(REMOVE_RECURSE "${NCPP_LITE_DISTRIBUTION_DIR}")



# Define the list of files and directories to copy
set(FILES_TO_COPY
    "cmake"
    "documentations"
    "ncpp"
    "scripts"
    ".project_name"
    "CMakeLists.txt"
    "README.md"
)

# Iterate over the list and copy each file/directory
foreach(FILE ${FILES_TO_COPY})
    file(COPY "${NCPP_ROOT_DIR}/${FILE}" DESTINATION "${NCPP_LITE_DISTRIBUTION_DIR}")
endforeach()

file(WRITE "${NCPP_LITE_DISTRIBUTION_DIR}/.project_name" ncpp_lite)



# Read the file contents
file(READ "${NCPP_LITE_DISTRIBUTION_DIR}/CMakeLists.txt" ROOT_CMAKELISTS_FILE_CONTENTS)

# Replace all occurrences of A with B
string(REPLACE "if(NCPP_LITE) # <REPLACER::NCPP_LITE>" "if(ON) # <REPLACER::NCPP_LITE>" MODIFED_ROOT_CMAKELISTS_FILE_CONTENTS "${ROOT_CMAKELISTS_FILE_CONTENTS}")

# Write the modified contents back to the file
file(WRITE "${NCPP_LITE_DISTRIBUTION_DIR}/CMakeLists.txt" "${MODIFED_ROOT_CMAKELISTS_FILE_CONTENTS}")



# Define the list of files and directories to copy
set(FILES_TO_DELETE

    # cmake
    "cmake/NCPP/RTTIMacros.cmake"

    # mem
    "ncpp/source/ncpp/mem/smart_chunk_allocator.hpp"
    "ncpp/source/ncpp/mem/clusafi_allocator.hpp"
    "ncpp/source/ncpp/mem/garbage_collection.hpp"

    # rtti
    "ncpp/source/ncpp/rtti/rcontainer.hpp"
    "ncpp/source/ncpp/rtti/robject.hpp"
    "ncpp/source/ncpp/rtti/robject_flag.hpp"
    "ncpp/source/ncpp/rtti/robject_type_info.hpp"
    "ncpp/source/ncpp/rtti/robject_member_info.hpp"
    "ncpp/source/ncpp/rtti/traits_defs.hpp"
    "ncpp/source/ncpp/rtti/traits.hpp"

    # samples/rtti
    "ncpp/samples/rtti/robject"

)

# Iterate over the list and copy each file/directory
foreach(FILE ${FILES_TO_DELETE})
    if(IS_DIRECTORY "${NCPP_LITE_DISTRIBUTION_DIR}/${FILE}")
        file(REMOVE_RECURSE "${NCPP_LITE_DISTRIBUTION_DIR}/${FILE}")
    else()
        file(REMOVE "${NCPP_LITE_DISTRIBUTION_DIR}/${FILE}")
    endif()
endforeach()