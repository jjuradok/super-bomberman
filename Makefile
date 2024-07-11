GPP=mingw32-g++
CXXFLAGS= --show-column   -g2 -Wall -O0    -D_DEBUG -std=c++14
LDFLAGS= -static-libgcc -static-libstdc++   
OBJS=Build.w32\Box.o Build.w32\Disparo.o Build.w32\Game.o Build.w32\Ganador.o Build.w32\Level.o Build.w32\Match.o Build.w32\Player.o Build.w32\ScreenPosition.o Build.w32\Settings.o Build.w32\main.o 

all: Build.w32 Build.w32\Project.exe

clean:
	del ${OBJS} Build.w32\Project.exe

Build.w32\Project.exe: ${OBJS}
	${GPP} ${OBJS} ${LDFLAGS} -o $@

Build.w32:
	mkdir Build.w32

Build.w32\Box.o: include\Box.cpp include\Box.h include\config\ResourcesLocation.h include\config\Config.h include\ScreenPosition.h include\utils\MatrixPosition.h
	${GPP} ${CXXFLAGS} -c include\Box.cpp -o $@

Build.w32\Disparo.o: include\Disparo.cpp include\Disparo.h
	${GPP} ${CXXFLAGS} -c include\Disparo.cpp -o $@

Build.w32\Game.o: include\Game.cpp include\Game.h include\Scene.h include\Settings.h include\Level.h include\Box.h include\utils\MatrixPosition.h
	${GPP} ${CXXFLAGS} -c include\Game.cpp -o $@

Build.w32\Ganador.o: include\Ganador.cpp include\Ganador.h include\Scene.h include\Match.h include\Disparo.h include\Level.h include\Box.h include\utils\MatrixPosition.h include\Player.h include\Game.h
	${GPP} ${CXXFLAGS} -c include\Ganador.cpp -o $@

Build.w32\Level.o: include\Level.cpp include\Level.h include\Box.h include\utils\MatrixPosition.h include\config\Config.h include\config\Constants.h include\utils\Vector.h include\ScreenPosition.h
	${GPP} ${CXXFLAGS} -c include\Level.cpp -o $@

Build.w32\Match.o: include\Match.cpp include\Match.h include\Disparo.h include\Scene.h include\Level.h include\Box.h include\utils\MatrixPosition.h include\Player.h include\Game.h include\Ganador.h include\config\ResourcesLocation.h include\config\Config.h include\config\Constants.h include\utils\Vector.h include\ScreenPosition.h
	${GPP} ${CXXFLAGS} -c include\Match.cpp -o $@

Build.w32\Player.o: include\Player.cpp include\Player.h include\Disparo.h include\Level.h include\Box.h include\utils\MatrixPosition.h include\config\Config.h include\config\ResourcesLocation.h include\config\Constants.h
	${GPP} ${CXXFLAGS} -c include\Player.cpp -o $@

Build.w32\ScreenPosition.o: include\ScreenPosition.cpp include\ScreenPosition.h include\utils\MatrixPosition.h include\config\Config.h include\Settings.h
	${GPP} ${CXXFLAGS} -c include\ScreenPosition.cpp -o $@

Build.w32\Settings.o: include\Settings.cpp include\Settings.h include\config\Config.h
	${GPP} ${CXXFLAGS} -c include\Settings.cpp -o $@

Build.w32\main.o: src\main.cpp include\Game.h include\Scene.h include\Match.h include\Disparo.h include\Level.h include\Box.h include\utils\MatrixPosition.h include\Player.h
	${GPP} ${CXXFLAGS} -c src\main.cpp -o $@

