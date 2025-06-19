.PHONY: clean
clean:
	git clean -Xdf

.PHONY: commit
commit:
	python3 scripts/commit.py
