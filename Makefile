CC := g++
CC_FLAGS := -Wall -Werror -std=c++11

targets = bfs dfs

all: $(targets)

bfs: bfs.cc
	$(CC) $(CC_FLAGS) $< -o $@

dfs: dfs.cc
	$(CC) $(CC_FLAGS) $< -o $@

clean:
	rm -f $(targets)

remake:
	make clean \
		&& make
