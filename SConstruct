env = Environment(
    CC='g++',
    CCFLAGS='-g -O2 -static -std=gnu++0x',
    CPPPATH=['src']
)

source = ['src/unionfind.cpp', 'src/disjoint_sets.cpp']
program = env.Program(target='bin/unionfind', source=source);

env.Append(LIBS=['gmock', 'pthread'])
source = ['test/disjoint_sets_test.cpp', 'src/disjoint_sets.cpp']
test = env.Program(target='bin/run_all_tests', source=source);
