cd ./${MAIN_TASK}/${SUB_TASK};

mkdir build && cd build;

cmake .. && make;

./${SUB_TASK}
