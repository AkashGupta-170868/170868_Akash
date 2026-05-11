.PHONY: all clean

PROJECT_DIRS = project*

all:
	for dir in $(PROJECT_DIRS); do \
		make -C $$dir; \
	done

clean:
	for dir in $(PROJECT_DIRS); do \
		make -C $$dir clean; \
	done

