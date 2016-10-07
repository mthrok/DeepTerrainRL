include(ExternalProject)

# This function is used to force a build on a dependant project at cmake configuration phase.
# See: http://stackoverflow.com/a/23570741
function (build_external_project target prefix url) #FOLLOWING ARGUMENTS are the CMAKE_ARGS of ExternalProject_Add  
  set(CMAKE_LIST_CONTENT "
    cmake_minimum_required(VERSION 2.8)

    include(ExternalProject)
    ExternalProject_add(${target}
            PREFIX ${prefix}
            GIT_REPOSITORY ${url}
            CMAKE_ARGS ${ARGN}
            )
  ")
  set(TMP_DIR "${prefix}/tmp")
  file(MAKE_DIRECTORY "${TMP_DIR}")
  file(WRITE "${TMP_DIR}/CMakeLists.txt" "${CMAKE_LIST_CONTENT}")

  MESSAGE("***** Building ${target} as a part of original cmake call *****")
  execute_process(COMMAND ${CMAKE_COMMAND}         . WORKING_DIRECTORY ${TMP_DIR})
  execute_process(COMMAND ${CMAKE_COMMAND} --build . WORKING_DIRECTORY ${TMP_DIR})
  MESSAGE("***** Finished building ${target} *****")
endfunction()
