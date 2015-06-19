
find_library(Rational_LIBRARY Rational
    PATHS "@CMAKE_INSTALL_PREFIX@/lib"
    NO_DEFAULT_PATH
)
find_library(Rational_LIBRARIES Rational
    PATHS "@CMAKE_INSTALL_PREFIX@/lib"
    NO_DEFAULT_PATH
)

find_path(Rational_INCLUDE_DIR Rational.hpp
    PATHS "@CMAKE_INSTALL_PREFIX@/include"
    NO_DEFAULT_PATH
)
find_path(Rational_INCLUDE_DIRS Rational.hpp
    PATHS "@CMAKE_INSTALL_PREFIX@/include"
    NO_DEFAULT_PATH
)

