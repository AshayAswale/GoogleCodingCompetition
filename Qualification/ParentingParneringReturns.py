import linecache


def isAvailable(person, time):
    for slot in person:
        start_overlap = (int(time[0]) > int(slot[0])
                         and int(time[0]) < int(slot[1]))
        end_overlap = (int(time[1]) > int(slot[0])
                       and int(time[1]) < int(slot[1]))
        if start_overlap or end_overlap:
            return False
    return True


def main():
    T = int(input())
    for t in range(T):
        c = []
        j = []
        schedule = ""
        N = int(input())
        for _ in range(N):
            time = input().split(" ")
            if isAvailable(c, time):
                schedule += "C"
                c.append(time)
            elif isAvailable(j, time):
                schedule += "J"
                j.append(time)
            else:
                schedule = "IMPOSSIBLE"
                break
        print_statement = "Case #" + str(t+1) + ": " + schedule
        print(print_statement)


if __name__ == "__main__":
    main()
