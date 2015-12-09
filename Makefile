.PHONY: clean All

All:
	@echo "----------Building project:[ ErikTest23 - Debug ]----------"
	@cd "ErikTest23" && "$(MAKE)" -f  "ErikTest23.mk"
clean:
	@echo "----------Cleaning project:[ ErikTest23 - Debug ]----------"
	@cd "ErikTest23" && "$(MAKE)" -f  "ErikTest23.mk" clean
