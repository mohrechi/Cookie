#include<stdio.h>
#include<stdlib.h>

class Queue
{
    public:
        int startTime, endTime;

        Queue()
        {
            startTime = 0;
            endTime = 0;
        }

        void update(int start, int end)
        {
            startTime = start;
            endTime = end;
        }

        bool isBusy(int time)
        {
            return time>=startTime and time<endTime;
        }

        void extendBusyTime(int time)
        {
            endTime += time;
        }
}roomQueue[15][15], elevatorQueue[15];

class Agent
{
    public:
        char    priority;
        int     currentTime;
        int     targetNumber;
        int     waitTime;
        int     targetRoom[105];
        int     targetTime[105];
        int     currentTarget;
        int     currentFloor;
        int     timeTableNumber;
        char    timeTable[1000][100];

        bool    entered;
        bool    left;
        int     currentPosition;

        Agent()
        {
            timeTableNumber     = 0;
            entered             = false;
            left                = false;
            currentPosition     = 0;
            currentTarget       = 0;
            waitTime            = 0;
            currentFloor        = 1;
        }

        bool input()
        {
            char s[10];
            scanf("%s",s);
            if(s[0] == '.')
            {
                return false;
            }
            priority = s[0];
            int a,b,c;
            scanf("%d:%d:%d",&a,&b,&c);
            currentTime = a*3600 + b*60 + c;
            targetNumber = 0;
            while(scanf("%d",&targetRoom[targetNumber]),targetRoom[targetNumber])
            {
                scanf("%d",&targetTime[targetNumber]);
                ++targetNumber;
            }
            targetRoom[targetNumber] = 100;
            return true;
        }

        void output()
        {
            printf("%c\n",priority);
            for(int i=0;i<timeTableNumber;i++)
            {
                printf("%s\n",timeTable[i]);
            }
        }

        int getHour(int time)
        {
            return time / 3600;
        }

        int getMinute(int time)
        {
            return (time % 3600) / 60;
        }

        int getSecond(int time)
        {
            return time % 60;
        }

        void convertTimeToString(char target[10], int time)
        {
            target[0] = '0' + getHour(time) / 10;
            target[1] = '0' + getHour(time) % 10;
            target[2] = ':';
            target[3] = '0' + getMinute(time) / 10;
            target[4] = '0' + getMinute(time) % 10;
            target[5] = ':';
            target[6] = '0' + getSecond(time) / 10;
            target[7] = '0' + getSecond(time) % 10;
            target[8] = 0;
        }

        int getFloorNumber(int room)
        {
            return room/100;
        }

        int getRoomNumber(int room)
        {
            return room%100;
        }

        int getCurrentRoom()
        {
            return currentFloor * 100 + currentPosition;
        }

        int addFive(int time)
        {
            return time + 5 - time % 5;
        }

        void convertRoomToString(char target[10], int room)
        {
            target[0] = '0' + getFloorNumber(room) / 10;
            target[1] = '0' + getFloorNumber(room) % 10;
            target[2] = '0' + getRoomNumber(room) / 10;
            target[3] = '0' + getRoomNumber(room) % 10;
            target[4] = 0;
        }

        void entry()
        {
            char fromTime[10], toTime[10];
            convertTimeToString(fromTime, currentTime);
            convertTimeToString(toTime, currentTime += 30);
            sprintf(timeTable[timeTableNumber++],"%s %s Entry",fromTime,toTime);
            if(getFloorNumber(targetRoom[currentTarget])==1)
            {
                currentPosition = getRoomNumber(targetRoom[currentTarget]);
            }
            else
            {
                currentPosition = 100;
            }
            entered = true;
        }

        void stayInRoom()
        {
            char fromTime[10], toTime[10], inRoom[10];
            if(roomQueue[getFloorNumber(targetRoom[currentTarget])][getRoomNumber(targetRoom[currentTarget])].isBusy(currentTime))
            {
                convertTimeToString(fromTime, currentTime);
                convertTimeToString(toTime, currentTime = roomQueue[getFloorNumber(targetRoom[currentTarget])][getRoomNumber(targetRoom[currentTarget])].endTime);
                convertRoomToString(inRoom, targetRoom[currentTarget]);
                sprintf(timeTable[timeTableNumber++],"%s %s Waiting in front of room %s", fromTime, toTime, inRoom);
                roomQueue[getFloorNumber(targetRoom[currentTarget])][getRoomNumber(targetRoom[currentTarget])].extendBusyTime(targetTime[currentTarget]);
            }
            else
            {
                roomQueue[getFloorNumber(targetRoom[currentTarget])][getRoomNumber(targetRoom[currentTarget])].update(currentTime, currentTime + targetTime[currentTarget]);
            }
            convertTimeToString(fromTime, currentTime);
            convertTimeToString(toTime, currentTime += targetTime[currentTarget]);
            convertRoomToString(inRoom, targetRoom[currentTarget++]);
            sprintf(timeTable[timeTableNumber++],"%s %s Stay in room %s", fromTime, toTime, inRoom);
        }

        void transferFromElevatorToRoom()
        {
            char fromTime[10], toTime[10], inRoom[10];
            convertTimeToString(fromTime, currentTime);
            convertTimeToString(toTime, currentTime += 10);
            convertRoomToString(inRoom, targetRoom[currentTarget]);
            sprintf(timeTable[timeTableNumber++],"%s %s Transfer from elevator to room %s", fromTime, toTime, inRoom);
            currentPosition = getRoomNumber(targetRoom[currentTarget]);
        }

        void transferFromRoomToRoom()
        {
            char fromTime[10], toTime[10], fromRoom[10], toRoom[10];
            convertTimeToString(fromTime, currentTime);
            convertTimeToString(toTime, currentTime += 10);
            convertRoomToString(fromRoom, getCurrentRoom());
            convertRoomToString(toRoom, targetRoom[currentTarget]);
            sprintf(timeTable[timeTableNumber++],"%s %s Transfer from room %s to room %s", fromTime, toTime, fromRoom, toRoom);
            currentPosition = getRoomNumber(targetRoom[currentTarget]);
        }

        void transferFromRoomToElevator()
        {
            char fromTime[10], toTime[10], inRoom[10];
            convertTimeToString(fromTime, currentTime);
            convertTimeToString(toTime, currentTime += 10);
            convertRoomToString(inRoom, getCurrentRoom());
            sprintf(timeTable[timeTableNumber++],"%s %s Transfer from room %s to elevator", fromTime, toTime, inRoom);
            currentPosition = 100;
        }

        void stayInElevator()
        {
            char fromTime[10], toTime[10];
            int floorBetween;
            if(currentTime%5==0)
            {
                if(elevatorQueue[getFloorNumber(currentFloor)].isBusy(currentTime))
                {
                    convertTimeToString(fromTime, currentTime);
                    convertTimeToString(toTime, currentTime = elevatorQueue[getFloorNumber(currentFloor)].endTime);
                    elevatorQueue[getFloorNumber(currentFloor)].extendBusyTime(5);
                    sprintf(timeTable[timeTableNumber++], "%s %s Waiting in elevator queue", fromTime, toTime);
                }
                else
                {
                    elevatorQueue[getFloorNumber(currentFloor)].update(currentTime, currentTime+5);
                }
            }
            else
            {
                if(elevatorQueue[getFloorNumber(currentFloor)].isBusy(addFive(currentTime)))
                {
                    convertTimeToString(fromTime, currentTime);
                    convertTimeToString(toTime, currentTime = elevatorQueue[getFloorNumber(currentFloor)].endTime);
                    elevatorQueue[getFloorNumber(currentFloor)].extendBusyTime(5);
                    sprintf(timeTable[timeTableNumber++], "%s %s Waiting in elevator queue", fromTime, toTime);
                }
                else
                {
                    convertTimeToString(fromTime, currentTime);
                    convertTimeToString(toTime, currentTime = addFive(currentTime));
                    elevatorQueue[getFloorNumber(currentFloor)].update(currentTime, currentTime+5);
                    sprintf(timeTable[timeTableNumber++], "%s %s Waiting in elevator queue", fromTime, toTime);
                }
            }
            floorBetween = getFloorNumber(targetRoom[currentTarget]) - currentFloor;
            if(floorBetween < 0)
            {
                floorBetween = -floorBetween;
            }
            convertTimeToString(fromTime, currentTime);
            convertTimeToString(toTime, currentTime += 30 * floorBetween);
            sprintf(timeTable[timeTableNumber++], "%s %s Stay in elevator", fromTime, toTime);
            currentFloor = getFloorNumber(targetRoom[currentTarget]);
            currentPosition = 100;
        }

        void exit()
        {
            char fromTime[10], toTime[10];
            convertTimeToString(fromTime, currentTime);
            convertTimeToString(toTime, currentTime += 30);
            sprintf(timeTable[timeTableNumber++],"%s %s Exit",fromTime,toTime);
            left = true;
        }

        bool wantLeave()
        {
            return targetNumber == currentTarget;
        }

        bool rightFloorNumber()
        {
            return currentFloor == getFloorNumber(targetRoom[currentTarget]);
        }

        bool rightRoomNumber()
        {
            return currentPosition == getRoomNumber(targetRoom[currentTarget]);
        }

        bool standByElevator()
        {
            return currentPosition == 100;
        }
}agent[30];

int cmp(const void *a, const void *b)
{
    return (*(Agent*)a).priority - (*(Agent*)b).priority;
}

int agentNumber;

void input()
{
    agentNumber = 0;
    while(agent[agentNumber].input())
    {
        agentNumber++;
    }
    qsort(agent, agentNumber, sizeof(*agent), cmp);
    agent[29].currentTime = 1000000000;
}

bool simulationEnd()
{
    for(int i=0;i<agentNumber;i++)
    {
        if(not agent[i].left)
        {
            return false;
        }
    }
    return true;
}

int findNearestTime()
{
    int nearestAgent = 29;
    for(int i=0;i<agentNumber;i++)
    {
        if(agent[i].left)
        {
            continue;
        }
        if(agent[i].currentTime < agent[nearestAgent].currentTime)
        {
            nearestAgent = i;
        }
        else if(agent[i].currentTime == agent[nearestAgent].currentTime)
        {
            if(agent[i].priority < agent[nearestAgent].priority)
            {
                nearestAgent = i;
            }
        }
    }
    return nearestAgent;
}

void output()
{
    for(int i=0;i<agentNumber;i++)
    {
        if(i)
        {
            printf("\n");
        }
        agent[i].output();
    }
}

void management()
{
    while(!simulationEnd())
    {
        int agentID = findNearestTime();
        if(not agent[agentID].entered)
        {
            agent[agentID].entry();
        }
        if(agent[agentID].wantLeave())
        {
            if(agent[agentID].rightFloorNumber())
            {
                agent[agentID].exit();
            }
            else
            {
                if(agent[agentID].standByElevator())
                {
                    agent[agentID].stayInElevator();
                }
                else
                {
                    agent[agentID].transferFromRoomToElevator();
                }
            }
        }
        else
        {
            if(agent[agentID].rightFloorNumber())
            {
                if(agent[agentID].rightRoomNumber())
                {
                    agent[agentID].stayInRoom();
                }
                else
                {
                    if(agent[agentID].standByElevator())
                    {
                        agent[agentID].transferFromElevatorToRoom();
                    }
                    else
                    {
                        agent[agentID].transferFromRoomToRoom();
                    }
                }
            }
            else
            {
                if(agent[agentID].standByElevator())
                {
                    agent[agentID].stayInElevator();
                }
                else
                {
                    agent[agentID].transferFromRoomToElevator();
                }
            }
        }
    }
}

int main()
{
    input();
    management();
    output();
    return 0;
}
