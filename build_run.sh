cd ./${MAIN_TASK}/${SUB_TASK};

mkdir -p build && cd build;

cmake .. && make;

ls ./;

./${SUB_TASK}
