.PHONY: clean All

All:
	@echo "----------Building project:[ HelloTestErik - Debug ]----------"
	@cd "HelloTestErik" && "$(MAKE)" -f  "HelloTestErik.mk"
clean:
	@echo "----------Cleaning project:[ HelloTestErik - Debug ]----------"
	@cd "HelloTestErik" && "$(MAKE)" -f  "HelloTestErik.mk" clean
