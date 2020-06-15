CXX = g++
CXXFLAGS = \
	-DLOCAL \
	--std=c++17 \
	-pipe \
	-O2 \
	-Winvalid-pch \
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
	-fstack-protector-strong

SRCDIR = _work/cpp

a: $(SRCDIR)/$(x).cc
	$(CXX) $(CXXFLAGS) $^