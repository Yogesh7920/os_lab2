LIBDIR := lib
OBJDIR := obj
EXEDIR := bin


EXE := $(EXEDIR)/out
LIBS := $(addprefix $(LIBDIR)/,libmatrixmath.a libimage.a)
SRCS := $(wildcard src/*.c)
INCS := $(wildcard include/*.h)
OBJS := $(addprefix $(OBJDIR)/, $(patsubst src/%.c,%.o, $(SRCS)))
TESTS := $(wildcard tests/*.ppm)
TEST_NAMES := $(patsubst tests/%.ppm,%, $(TESTS))

vpath %.c src
vpath %.h include


all: $(EXE)
	@echo "Compile Done !"

build: $(EXE)
	@echo "Compile Done !"

run: | $(EXE)
	./$(EXE) input.ppm output.ppm
	@echo "Executed !"

T1: | $(EXEDIR)
	./$(EXE) input.ppm output.ppm T1
	@echo "Executed !"

T2: | $(EXEDIR)
	./$(EXE) input.ppm output.ppm T2
	@echo "Executed !"

check:
    @read -p "Enter Module Name:" module; \  
    module_dir=./modules/$$module; \
    mkdir -p $$module_dir/build

tests: $(TEST_NAMES)
	@echo "All Tests ran !"

test%: $(EXE)
	./$(EXE) tests/$@.ppm test_results/$@.ppm

liba: $(LIBS)
	@echo "Static Libraries generated, check lib dir"

$(EXE): obj/main.o $(LIBS) | $(EXEDIR)
	gcc -o $@ -I include $< -L $(LIBDIR) -limage -lmatrixmath

$(LIBDIR)/libmatrixmath.a: obj/matrixmath.o | $(LIBDIR)
	ar rcs $@ $^

$(LIBDIR)/libimage.a: obj/image.o obj/helper.o obj/ppm.o | $(LIBDIR)
	ar rcs $@ $^

$(OBJDIR)/%.o: %.c $(INCS) | $(OBJDIR)
	gcc -o $@ -c -I ./include $<

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBDIR):
	mkdir -p $(LIBDIR)

$(EXEDIR):
	mkdir -p $(EXEDIR)

.PHONY: clean
clean:
	rm -rf $(EXEDIR) $(OBJDIR) $(LIBDIR) output.ppm
