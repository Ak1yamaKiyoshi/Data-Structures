from random import randint
import os


class TournamentTable:
    def __init__(self):
        self._table = self.tableGetter()  # self.tableGetter()

    # usage: tableGetter()
    # returns: int array with team score table
    def tableGetter(self):
        try:
            with open("tournamentTable.txt", "r") as file:
                data = [int(n) for n in file.read().rstrip().split(".")]
        except:  # if file doesn't exist creates a new one
            with open("tournamentTable.txt", "w") as file:
                file.write("0.0.0.0")
            data = [0, 0, 0, 0]
        return data

    # usage: clearResults()
    # do: deletes tournament data
    def clearTable(self):
        os.remove("tournamentTable.txt")

    # usage: tableSetter(int team, int value) team number(0 - 3)
    def tableSetter(self, team, value):
        self._table = self.tableGetter()
        self._table[team] = value
        for i in self._table:
            try:
                line += "."
                line += str(i)
            except:
                line = str(i)
        with open("tournamentTable.txt", "w") as file:
            file.write(line)

    # usage: tableAdder(int array[4]) array with resultsToAdd
    def tableAdder(self, resultsToAdd):
        table = self.tableGetter()
        for i in range(4):
            self.tableSetter(i, resultsToAdd[i]+table[i])


class Match:
    # usage: game()
    # returns: int array[2] with results of 2 team win/loose
    def game(self):
        team1Score = randint(0, 5)
        team2Score = randint(0, 5)
        if team1Score > team2Score:
            out = [3, 0]
        elif team1Score == team2Score:
            out = [1, 1]
        else:
            out = [0, 3]
        return out

    # usage: matchResults(int array[4])
    # returns: int array[4] with final results
    def matchResults(self, matchScore):
        if matchScore[0] > matchScore[1]:
            matchScore[0] = 3
            matchScore[1] = 0
        elif matchScore[0] == matchScore[1]:
            matchScore[0] = 1
            matchScore[1] = 1
        else:
            matchScore[0] = 0
            matchScore[1] = 3

        if matchScore[2] > matchScore[3]:
            matchScore[2] = 3
            matchScore[3] = 0
        elif matchScore[2] == matchScore[3]:
            matchScore[2] = 1
            matchScore[3] = 1
        else:
            matchScore[2] = 0
            matchScore[3] = 3

        return matchScore

    # usage: match()
    # returns: int array[4] with matchScore
    def matchCount(self):
        matchScore = [0, 0, 0, 0]
        for i in range(0, 4, 2):
            for _ in range(2):
                game = self.game()
                matchScore[i] += game[0]
                matchScore[i+1] += game[1]
        return matchScore

    # usage: match()
    # returns: counted results for match
    def match(self):
        return self.matchResults(self.matchCount())


class Tournament(TournamentTable, Match):
    def __init__(self):
        super().__init__()

    # usage:  stage(int stageNo)
    # do: sorts matchResults by teams 1 2 3 4 | 1 3 2 4 | 1 4 2 3
    # returns: int array[4] with sorted data
    def stage(self, stageNo):
        match(stageNo):
            case 1:
                # 1 2 3 4
                out = self.match()
            case 2:
                # 1 3 2 4
                rawMatch = self.match()
                rawMatch = [rawMatch[0], rawMatch[2], rawMatch[1], rawMatch[3]]
                out = rawMatch
            case 3:
                # 1 4 2 3
                rawMatch = self.match()
                rawMatch = [rawMatch[0], rawMatch[2], rawMatch[3], rawMatch[1]]
                out = rawMatch
        return out

    # usage: tournament()
    # do: adds result for each stage to team score
    def tournament(self):
        for i in range(1, 4):
            self.tableAdder(self.stage(i))

    # usage: printResults()
    # do: prints place, team and team's core
    def printResults(self):
        table = self.tableGetter()
        sortedTable = sorted(table, reverse=True)
        for i in range(4):
            print(f"{i+1} place takes", end=" ")
            for j in range(4):
                if table[j] == sortedTable[i]:
                    print(f"{j+1} team, with score {sortedTable[i]}")
                    table[j] = -1
                    break


tournament = Tournament()
tournament.tournament()
tournament.printResults()
tournament.clearTable()
