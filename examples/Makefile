all: test_01 test_02 test_03 test_04
%: %.nim
	nim c $<
clean:
	$(RM) test_01 test_02 test_03 test_04 output.png
