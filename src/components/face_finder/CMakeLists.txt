include_directories(
    ${COMPONENTS_DIR}/face_finder/include
    ${COMPONENTS_DIR}/face_finder/impl/include
    ${COMPONENTS_DIR}/config/include
)


set(SOURCES
    impl/src/face_finder_impl.cpp
)

add_library(face_finder ${SOURCES})
