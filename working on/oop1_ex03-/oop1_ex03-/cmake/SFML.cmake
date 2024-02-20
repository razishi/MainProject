# Copy SFML-related DLLs to the target folder

configure_file ("${SFML_LOCATION}/bin/openal32.dll" ${CMAKE_BINARY_DIR} COPYONLY)

add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_RUNTIME_DLLS:${CMAKE_PROJECT_NAME}> $<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>
  COMMAND_EXPAND_LISTS
)
