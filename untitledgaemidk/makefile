compiler = g++
filename = ugi
src = main.cpp
flags = -lm -lraylib
winflags = -Iwin32/include -Lwin32/lib -lraylibdll -lopengl32 -lgdi32 -lwinmm -lshell32 -luser32 -lkernel32 -lm
ccwin = x86_64-w64-mingw32-gcc
outwin = ugiwindows.exe
releasewin = 1
all:
	$(compiler) -o $(filename) $(src) $(flags) && $(ccwin) -o $(outwin) $(src) $(winflags)

clean:
	rm -rf $(filename) && rm -rf $(outwin)
run:
	./$(filename)

win:
	$(ccwin) -o $(outwin) $(src) $(winflags)

packagewin:
	mkdir -p $(releasewin) release/win32/ && cp $(outwin) release/win32/$(releasewin) && cp win32/lib/raylib.dll release/win32/$(releasewin)