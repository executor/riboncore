add_subdirectory(updates)
add_subdirectory(tools)
add_subdirectory(FULL)

########### install files ###############

FILE(GLOB _SQL *.sql)

install(FILES ${_SQL} DESTINATION share/ribon/sql)