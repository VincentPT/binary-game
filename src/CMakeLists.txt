cmake_minimum_required (VERSION 3.2)
project(BinaryGame C CXX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

SET (GAME_ENGINE_SRC
    GameEngine/GameEngine.cpp GameEngine/GameEngine.h
    GameEngine/BinarySequence.h GameEngine/BinarySequence.cpp
    GameEngine/Player.h GameEngine/Player.cpp
    GameEngine/GameResult.h GameEngine/GameResult.cpp
)

SET (ALGORITHMS_SRC algorithms.cpp algorithms.h)

SET (BINARY_GAME_SRC
    ${GAME_ENGINE_SRC}
    ${ALGORITHMS_SRC}
    main.cpp
)

include_directories(AFTER ${CMAKE_CURRENT_SOURCE_DIR})

source_group(GameEngine FILES ${GAME_ENGINE_SRC})
source_group(algorithms FILES ${ALGORITHMS_SRC})


add_executable(${PROJECT_NAME} ${BINARY_GAME_SRC})

#set_target_properties(<ProjectName> PROPERTIES FOLDER <folder name>)