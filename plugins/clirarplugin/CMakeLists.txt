########### next target ###############

# TODO: drop application/x-rar alias once distributions ship shared-mime-info 1.7
set(SUPPORTED_CLIRAR_MIMETYPES "application/vnd.rar;application/x-rar;")

set(kerfuffle_clirar_SRCS cliplugin.cpp)

ecm_qt_declare_logging_category(kerfuffle_clirar_SRCS
                                HEADER ark_debug.h
                                IDENTIFIER ARK
                                CATEGORY_NAME ark.clirar)

# NOTE: the first double-quotes of the first mime and the last
# double-quotes of the last mime must NOT be escaped.
set(SUPPORTED_MIMETYPES
    "application/vnd.rar\",
    \"application/x-rar")

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/kerfuffle_clirar.json.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/kerfuffle_clirar.json)

kerfuffle_add_plugin(kerfuffle_clirar ${kerfuffle_clirar_SRCS})

set(SUPPORTED_ARK_MIMETYPES "${SUPPORTED_ARK_MIMETYPES}${SUPPORTED_CLIRAR_MIMETYPES}" PARENT_SCOPE)
set(INSTALLED_KERFUFFLE_PLUGINS "${INSTALLED_KERFUFFLE_PLUGINS}kerfuffle_clirar;" PARENT_SCOPE)

find_program(UNRAR unrar)
if(UNRAR)
    message(STATUS "Found unrar executable: ${UNRAR}")
else()
    message(WARNING "Could not find the unrar executable. Ark requires unrar or unar to extract RAR archives.")
endif()

find_program(RAR rar)
if(RAR)
    message(STATUS "Found rar executable: ${RAR}")
else()
    message(WARNING "Could not find the rar executable. Ark won't be able to create or edit RAR archives.")
endif()
