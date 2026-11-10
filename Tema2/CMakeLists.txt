cmake_minimum_required(VERSION 3.10)
project(tema2)
include_directories(inc)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT MSVC)
    add_compile_options(-Wall)
endif()

option(FARA_INIT "" OFF)
option(ORDINE_GRESITA "" OFF)
option(JURNAL_GLOBAL "" OFF)
option(INCEARCA_ATRIBUIRE "" OFF)
option(INCEARCA_COPIERE "" OFF)
option(COPIERE_DIN_MEMBRU "" OFF)
set(STIL_COPIERE "DELETE" CACHE STRING "DELETE, PRIVAT sau NECOPIABIL")

foreach(opt FARA_INIT ORDINE_GRESITA JURNAL_GLOBAL INCEARCA_ATRIBUIRE
            INCEARCA_COPIERE COPIERE_DIN_MEMBRU)
    if(${opt})
        add_definitions(-D${opt})
    endif()
endforeach()
add_definitions(-DSTIL_${STIL_COPIERE})

add_executable(${PROJECT_NAME}
    inc/tema2/jurnal.hpp
    inc/tema2/martor.hpp
    inc/tema2/inregistrare.hpp
    inc/tema2/senzor.hpp
    inc/tema2/pereche.hpp
    inc/tema2/obiect_numit.hpp
    inc/tema2/necopiabil.hpp
    inc/tema2/casa.hpp
    # JURNAL_GLOBAL: pornire.cpp inainte de jurnal.cpp
    src/pornire.cpp
    src/jurnal.cpp
    src/martor.cpp
    src/inregistrare.cpp
    src/senzor.cpp
    src/casa.cpp
    src/main.cpp
)
