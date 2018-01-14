CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -Werror=vla -MMD
EXEC = cc3k
OBJECTS = dlcScoreBoard.o cell.o cellPassage.o enemyDragon.o enemyHuman.o floor.o goldNormal.o observer.o pcShade.o potionBA.o potionWA.o thing.o cellDoorWay.o cellStairWay.o random.o enemyDwarf.o enemyMerchant.o gold.o goldSmall.o pc.o pcTroll.o potionBD.o potionWD.o cellEmpty.o cellWall.o enemyElf.o enemyOrcs.o goldDragon.o item.o pcDrow.o pcVampire.o potionPH.o subject.o cellFloorTile.o enemy.o enemyHalfling.o figure.o goldMerchant.o main.o pcGoblin.o potion.o potionRH.o textdisplay.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean

