CXX        := g++-4.8
CXXFLAGS   := -pedantic -std=c++11 -Wall
LDFLAGS    := -lgtest -lgtest_main -pthread
GCOV       := gcov-4.8
GCOVFLAGS  := -fprofile-arcs -ftest-coverage
GPROF      := gprof
GPROFFLAGS := -pg
VALGRIND   := valgrind

clean:
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f RunAustralia_voting
	rm -f RunAustralia_voting.tmp
	rm -f TestAustralia_voting
	rm -f TestAustralia_voting.tmp
	rm -f solution
	rm -f *~

config:
	git config -l

scrub:
	make  clean
	rm -f  Australia_voting.log
	rm -rf australia_voting-tests
	rm -rf html
	rm -rf latex

status:
	make clean
	@echo
	git branch
	git remote -v
	git status

test: RunAustralia_voting.tmp TestAustralia_voting.tmp

solution: solution.cpp
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) solution.cpp -o solution

shi: shi.cpp
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) shi.cpp -o shi

RunAustralia_voting: Australia_voting.h Australia_voting.c++ RunAustralia_voting.c++
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) Australia_voting.c++ RunAustralia_voting.c++ -o RunAustralia_voting

RunAustralia_voting.tmp: RunAustralia_voting
	./RunAustralia_voting < RunAustralia_voting.in > RunAustralia_voting.tmp
	diff -w RunAustralia_voting.tmp RunAustralia_voting.out

TestAustralia_voting: Australia_voting.h Australia_voting.c++ TestAustralia_voting.c++
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) Australia_voting.c++ TestAustralia_voting.c++ -o TestAustralia_voting $(LDFLAGS)

TestAustralia_voting.tmp: TestAustralia_voting
	$(VALGRIND) ./TestAustralia_voting                                       >  TestAustralia_voting.tmp 2>&1
	$(GCOV) -b Australia_voting.c++     | grep -A 5 "File 'Australia_voting.c++'"     >> TestAustralia_voting.tmp
	$(GCOV) -b TestAustralia_voting.c++ | grep -A 5 "File 'TestAustralia_voting.c++'" >> TestAustralia_voting.tmp
	cat TestAustralia_voting.tmp
