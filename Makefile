CXX = g++
CXXFLAGS = \
	--std=c++17 \
	-DLOCAL \
	-pipe \
	-O2 \
	-Wall \
	-Wextra \
	-pedantic \
	-Wshadow \
	-Wformat=2 \
	-Wfloat-equal \
	-Wconversion \
	-Wlogical-op \
	-Wshift-overflow=2 \
	-Wduplicated-cond \
	-Wcast-qual \
	-Wcast-align \
	-D_GLIBCXX_DEBUG \
	-D_GLIBCXX_DEBUG_PEDANTIC \
	-D_FORTIFY_SOURCE=2 \
	-fsanitize=address \
	-fsanitize=undefined \
	-fno-sanitize-recover \
	-fstack-protector

SRCDIR = _work/cpp

a: $(SRCDIR)/$(x).o
	$(CXX) $(CXXFLAGS) $^