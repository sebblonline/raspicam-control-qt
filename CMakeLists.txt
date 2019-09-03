cmake_minimum_required(VERSION 3.0)
project(raspicam-control-qt)

# debug build
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")

# Set Qt path here
# set(CMAKE_PREFIX_PATH "/opt/Qt/5.12.3/gcc_64")

# TODO test windows
IF(WIN32)
    #set (CMAKE_PREFIX_PATH ${QT_DIR})
        set(CMAKE_PREFIX_PATH $ENV{WIN_SDK_LIBS})
    #set (CMAKE_PREFIX_PATH "C:/Qt/Qt5.2.0/5.2.0/msvc2010_opengl")
    #set (CMAKE_PREFIX_PATH "C:/Program Files (x86)/Microsoft SDKs/Windows/v7.0A/Lib")
ENDIF(WIN32)

# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Widgets finds its own dependencies.
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Network REQUIRED)

SET(SOURCES
    main.cpp
    MainWindow.cpp
    StreamInterface.cpp
    ControlInterface.cpp
    )
SET(HEADERS
    MainWindow.h
    StreamInterface.h
    ControlInterface.h
    )

SET(MOC_HEADERS
    MainWindow.h
)

SET(UIS
    MainWindow.ui
)

QT5_WRAP_UI(UI_HEADERS ${UIS})

# Set include directories
SET(INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${QT_QTOPENGL_INCLUDE_DIR}
)

INCLUDE_DIRECTORIES(${INCLUDE_DIRS})

add_executable(raspicam-control-qt
                ${SOURCES}
                ${HEADERS}
                ${MOC_HEADERS}
                ${UI_HEADERS})

target_link_libraries (raspicam-control-qt
                ${OpenCV_LIBS}
                Qt5::Widgets
                Qt5::Network
)
