LIBDIR := lib
LIBSODIR := lib.so
OBJDIR := obj
OBJSODIR := objso
EXEDIR := bin
TEST_RESULTS := test_results

EXE := $(EXEDIR)/out
LIBS := $(addprefix $(LIBDIR)/,libmatrixmath.a libimage.a)
LIBSOS := $(addprefix $(LIBSODIR)/,libmatrixmath.so libimage.so)
SRCS := $(wildcard src/*.c)
INCS := $(wildcard include/*.h)
OBJS := $(addprefix $(OBJDIR)/, $(patsubst src/%.c,%.o, $(SRCS)))
OBJSOS := $(addprefix $(OBJSODIR)/, $(patsubst src/%.c,%.o, $(SRCS)))
TESTS := $(wildcard tests/*.ppm)
TEST_NAMES := $(patsubst tests/%.ppm,%, $(TESTS))

vpath %.c src
vpath %.h include

define my_prepare =
	@echo "Enter the input (path)"
	read input
	filename=$(basename -- "$input")
	extension="${filename##*.}"
	filename="${filename%.*}"
	final=$(echo $input | cut -d'.' -f 1)
	if [ "$extension" != "ppm" ]; then
		convert "$input" "$final.ppm"
	fi
	echo "Enter the output (path)"
	read output
	echo "$input $output" > .config.txt
	echo "Preparation done!"
endef

all: $(EXE)
	@echo "Compile Done !"

build: $(EXE)
	@echo "Compile Done !"

run: | $(EXE)
	./$(EXE)
	@echo "Executed !"

.ONESHELL: prepare
prepare: ; $(value my_prepare)

T1: $(EXE)
	./$(EXE) T1
	@echo "Executed !"

T2: $(EXE)
	./$(EXE) T2
	@echo "Executed !"

tests: $(TEST_NAMES)
	@echo "All Tests ran! see in test_results dir"

test%: $(EXE) | $(TEST_RESULTS)
	./$(EXE) tests/$@.ppm $(TEST_RESULTS)/$@.ppm

liba: $(LIBS)
	@echo "Static Libraries generated, check lib dir"

libso: $(LIBSOS)
	@echo "Dynamic Libraries generated, check libso dir"

buildso: libso | $(EXE)
	gcc -o $(EXE) -I include src/main.c -L $(LIBSODIR) -limage -lmatrixmath

$(EXE): obj/main.o $(LIBS) | $(EXEDIR)
	gcc -o $@ -I include $< -L $(LIBDIR) -limage -lmatrixmath

$(LIBDIR)/libmatrixmath.a: obj/matrixmath.o | $(LIBDIR)
	ar rcs $@ $^

$(LIBDIR)/libimage.a: obj/image.o obj/helper.o obj/ppm.o | $(LIBDIR)
	ar rcs $@ $^

$(OBJDIR)/%.o: %.c $(INCS) | $(OBJDIR)
	gcc -o $@ -c -I ./include $<

$(LIBSODIR)/libmatrixmath.so: objso/matrixmath.o | $(LIBSODIR)
	gcc -shared -o $@ $^
	
$(LIBSODIR)/libimage.so: objso/image.o objso/helper.o objso/ppm.o | $(LIBSODIR)
	gcc -shared -o $@ $^

$(OBJSODIR)/%.o: %.c $(INCS) | $(OBJSODIR)
	gcc -fPIC -o $@ -c -I ./include $<

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJSODIR):
	mkdir -p $(OBJSODIR)

$(LIBDIR):
	mkdir -p $(LIBDIR)

$(LIBSODIR):
	mkdir -p $(LIBSODIR)

$(EXEDIR):
	mkdir -p $(EXEDIR)

$(TEST_RESULTS):
	mkdir -p $(TEST_RESULTS)

.PHONY: clean
clean:
	rm -rf $(EXEDIR) $(OBJDIR) $(OBJSODIR) $(LIBDIR) $(LIBSODIR) $(LIBSODIR) $(TEST_RESULTS) *.ppm
	echo "tests/test1.ppm output.ppm" > .config.txt
