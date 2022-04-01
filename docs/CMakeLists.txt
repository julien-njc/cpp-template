set(DOXYGEN_EXTRACT_ALL YES)
set(DOXYGEN_BUILTIN_STL_SUPPORT YES)
set(DOXYGEN_GENERATE_TREEVIEW YES)
set(DOXYGEN_HTML_EXTRA_STYLESHEET   "${CMAKE_CURRENT_SOURCE_DIR}/doxygen-awesome.css"
                                    "${CMAKE_CURRENT_SOURCE_DIR}/doxygen-awesome-sidebar-only.css")
set(DOXYGEN_USE_MDFILE_AS_MAINPAGE "${CMAKE_CURRENT_SOURCE_DIR}/mainpage.md")

set(TO_DOCUMENT utilities.h)

doxygen_add_docs(docs 
                ${TO_DOCUMENT} "${CMAKE_CURRENT_SOURCE_DIR}/mainpage.md"
                WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}/include")
