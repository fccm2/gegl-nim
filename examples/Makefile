all: test_01 test_02 test_03 test_04 test_05
%: %.nim
	nim c $<
clean:
	$(RM) test_01 test_02 test_03 test_04 test_05 output.png
