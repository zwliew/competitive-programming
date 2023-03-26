CXX = g++
CXXFLAGS = \
	-DLOCAL \
	--std=c++20 \
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
	-Wlong-long \
#	-Wlogical-op \
	-Wshift-overflow \
#	-Wshift-overflow=2 \
#	-Wduplicated-cond \
	-Wcast-qual \
	-Wcast-align \
	-D_GLIBCXX_DEBUG \
	-D_GLIBCXX_DEBUG_PEDANTIC \
	-D_FORTIFY_SOURCE=2 \
	-fsanitize=undefined \
	-fsanitize-undefined-trap-on-error \
	-fno-sanitize-recover \
	-fstack-protector-strong

SRCDIR = _work/cc

a: $(SRCDIR)/$(x).o
	$(CXX) $(CXXFLAGS) $^
