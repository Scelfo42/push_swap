all:
	$(MAKE) -C ../../42cursus/push_swap all
	@echo "\nCommands are:\nmake m <-- to check moves are correctly done under limit\nmake e <-- to check if errors are handled properly\nmake v <-- to check that memory is always freed\n"

m:
	./main.sh

e:
	./errors.sh

v:
	./memory.sh

.PHONY: all m e v
.SILENT:
