#include <cstdio>
#include <cstring>

static const int MAX_VARIABLE_NUMBER = 10;

class Variable
{
    public:
        int variableNumber;

        Variable()
        {
            this->clear();
        }

        int add(const char *string)
        {
            strcpy(this->variableName[this->variableNumber], string);
            return this->variableNumber ++;
        }

        int find(const char *string)
        {
            for(int variableIndex=0;variableIndex<this->variableNumber;++variableIndex)
            {
                if(strcmp(this->variableName[variableIndex], string) == 0)
                {
                    return variableIndex;
                }
            }
            return -1;
        }

        void setValue(int index, double value)
        {
            this->variableValue[index] = value;
        }

        double getValue(int index)
        {
            return this->variableValue[index];
        }

        void sort()
        {
            char tempName[256];
            double tempValue;
            for(int variableIndex1=0;variableIndex1<this->variableNumber;++variableIndex1)
            {
                for(int variableIndex2=variableIndex1+1;variableIndex2<this->variableNumber;++variableIndex2)
                {
                    if(strcmp(this->variableName[variableIndex1], this->variableName[variableIndex2]) > 0)
                    {
                        strcpy(tempName, this->variableName[variableIndex1]);
                        strcpy(this->variableName[variableIndex1], this->variableName[variableIndex2]);
                        strcpy(this->variableName[variableIndex2], tempName);
                        tempValue = this->variableValue[variableIndex1];
                        this->variableValue[variableIndex1] = this->variableValue[variableIndex2];
                        this->variableValue[variableIndex2] = tempValue;
                    }
                }
            }
        }

        void printResult()
        {
            for(int variableIndex=0;variableIndex<this->variableNumber;++variableIndex)
            {
                printf("%.4lf\n", this->variableValue[variableIndex]);
            }
        }

        void clear()
        {
            this->variableNumber = 0;
        }

    private:
        static const int MAX_VARIABLE_LENGTH = 30;
        double variableValue[MAX_VARIABLE_NUMBER];
        char variableName[MAX_VARIABLE_NUMBER][MAX_VARIABLE_LENGTH];
};

class Command
{
    public:
        static const int OPERAND_RESULT = 0;
        static const int OPERAND_R1 = 1;
        static const int OPERAND_R2 = 2;
        static const int MAX_OPERAND_NUMBER = 3;
        static const int MAX_OPERAND_LENGTH = 30;
        bool isVariable[MAX_OPERAND_NUMBER];
        int variableMap[MAX_OPERAND_NUMBER];
        bool add;

        void readCommand(const char *string)
        {
            int length = strlen(string);
            int operandIndex = 0;
            int operandPosition = 0;
            for(int stringIndex=0;stringIndex<length;++stringIndex)
            {
                char character = string[stringIndex];
                if(character == '+')
                {
                    this->add = true;
                    this->operand[operandIndex][operandPosition] = 0;
                    operandPosition = 0;
                    ++ operandIndex;
                }
                else if(character == '-')
                {
                    this->add = false;
                    this->operand[operandIndex][operandPosition] = 0;
                    operandPosition = 0;
                    ++ operandIndex;
                }
                else if(character == ':')
                {
                    this->operand[operandIndex][operandPosition] = 0;
                    operandPosition = 0;
                    ++ stringIndex;
                    ++ operandIndex;
                }
                else if(character != ' ' && character != '\t')
                {
                    if(character >= 'A' && character <= 'Z')
                    {
                        character = character - 'A' + 'a';
                    }
                    this->operand[operandIndex][operandPosition++] = character;
                }
            }
            this->operand[operandIndex][operandPosition] = 0;
        }

        void printCommand()
        {
            printf("%s := %s %c %s\n", operand[OPERAND_RESULT], operand[OPERAND_R1], add?'+':'-', operand[OPERAND_R2]);
        }

        void printCommandDelt()
        {
            printf("%c ", this->add?'+':'-');
            for(int operandIndex=0;operandIndex<MAX_OPERAND_NUMBER;++operandIndex)
            {
                if(this->isVariable[operandIndex])
                {
                    printf("V");
                }
                printf("%d ", this->variableMap[operandIndex]);
            }
            printf("\n");
        }

        void dealWithVariableTable(Variable &variable)
        {
            for(int operandIndex=0;operandIndex<MAX_OPERAND_NUMBER;++operandIndex)
            {
                if(this->operand[operandIndex][0] >= '0' && this->operand[operandIndex][0] <= '9')
                {
                    this->isVariable[operandIndex] = false;
                    int length = strlen(this->operand[operandIndex]);
                    this->variableMap[operandIndex] = 0;
                    for(int operandPosition=0;operandPosition<length;++operandPosition)
                    {
                        this->variableMap[operandIndex] = this->variableMap[operandIndex] * 10 + this->operand[operandIndex][operandPosition] - '0';
                    }
                }
                else
                {
                    this->isVariable[operandIndex] = true;
                    int temp = variable.find(this->operand[operandIndex]);
                    if(temp == -1)
                    {
                        this->variableMap[operandIndex] = variable.add(this->operand[operandIndex]);
                    }
                    else
                    {
                        this->variableMap[operandIndex] = temp;
                    }
                }
            }
        }

    private:
        char operand[MAX_OPERAND_NUMBER][MAX_OPERAND_LENGTH];
};

class Program
{
    public:
        static const int MAX_COMMAND_NUMBER = 25;
        Command command[MAX_COMMAND_NUMBER];
        int commandNumber;

        Program()
        {
            this->clearProgram();
        }

        void readProgram()
        {
            char buffer[256];
            while(gets(buffer))
            {
                if(strlen(buffer) == 0)
                {
                    continue;
                }
                if(strcmp(buffer, "END") == 0)
                {
                    break;
                }
                this->command[this->commandNumber++].readCommand(buffer);
            }
        }

        void printProgram()
        {
            printf("START\n");
            for(int commandIndex=0;commandIndex<this->commandNumber;++commandIndex)
            {
                this->command[commandIndex].printCommand();
            }
            printf("END\n");
        }

        void printProgramDelt()
        {
            printf("START\n");
            for(int commandIndex=0;commandIndex<this->commandNumber;++commandIndex)
            {
                this->command[commandIndex].printCommandDelt();
            }
            printf("END\n");
        }

        void dealWithVariableTable(Variable &variable)
        {
            for(int commandIndex=0;commandIndex<this->commandNumber;++commandIndex)
            {
                this->command[commandIndex].dealWithVariableTable(variable);
            }
        }

        void clearProgram()
        {
            this->commandNumber = 0;
        }
};

class Processor
{
    public:
        static const int MAX_PROGRAM_NUMBER = 2;
        static const int MAX_STATUS_NUMBER = 105;
        struct Status
        {
            double possibility;
            double expectation[MAX_VARIABLE_NUMBER];
            double register1[MAX_PROGRAM_NUMBER], register2[MAX_PROGRAM_NUMBER];
        }status[MAX_STATUS_NUMBER][MAX_STATUS_NUMBER];

        void read()
        {
            for(int programIndex=0;programIndex<MAX_PROGRAM_NUMBER;++programIndex)
            {
                this->program[programIndex].readProgram();
                this->program[programIndex].dealWithVariableTable(variable);
            }
        }

        void merge(Status &status1, Status &status2, Status &status3, int step)
        {
            double possibility1,possibility2;
            switch(step)
            {
                case 0:
                    possibility1 = status2.possibility * 0.5;
                    possibility2 = status3.possibility * 0.5;
                    break;
                case 1:
                    possibility1 = status2.possibility * 0.5;
                    possibility2 = status3.possibility;
                    break;
                case 2:
                    possibility1 = status2.possibility;
                    possibility2 = status3.possibility * 0.5;
                    break;
                case 3:
                    possibility1 = status2.possibility;
                    possibility2 = status3.possibility;
                    break;
            }
            status1.possibility = possibility1 + possibility2;
            for(int variableIndex=0;variableIndex<10;++variableIndex)
            {
                status1.expectation[variableIndex] = (status2.expectation[variableIndex]*possibility1+status3.expectation[variableIndex]*possibility2)/status1.possibility;
            }
            status1.register1[0] = (status2.register1[0] * possibility1 + status3.register1[0] * possibility2) / status1.possibility;
            status1.register1[1] = (status2.register1[1] * possibility1 + status3.register1[1] * possibility2) / status1.possibility;
            status1.register2[0] = (status2.register2[0] * possibility1 + status3.register2[0] * possibility2) / status1.possibility;
            status1.register2[1] = (status2.register2[1] * possibility1 + status3.register2[1] * possibility2) / status1.possibility;
        }

        void calculate(Status &statusOrigin, Status &statusTarget, int programIndex, int commandExtendIndex)
        {
            commandExtendIndex --;
            statusTarget = statusOrigin;
            Command command = this->program[programIndex].command[commandExtendIndex/4];
            int assmblyCommand = commandExtendIndex % 4;
            switch(assmblyCommand)
            {
                case 0:
                    if(command.isVariable[Command::OPERAND_R1])
                    {
                        statusTarget.register1[programIndex] = statusOrigin.expectation[command.variableMap[Command::OPERAND_R1]];
                    }
                    else
                    {
                        statusTarget.register1[programIndex] = command.variableMap[Command::OPERAND_R1];
                    }
                    break;
                case 1:
                    if(command.isVariable[Command::OPERAND_R2])
                    {
                        statusTarget.register2[programIndex] = statusOrigin.expectation[command.variableMap[Command::OPERAND_R2]];
                    }
                    else
                    {
                        statusTarget.register2[programIndex] = command.variableMap[Command::OPERAND_R2];
                    }
                    break;
                case 2:
                    if(command.add)
                    {
                        statusTarget.register1[programIndex] += statusTarget.register2[programIndex];
                    }
                    else
                    {
                        statusTarget.register1[programIndex] -= statusTarget.register2[programIndex];
                    }
                    break;
                case 3:
                    statusTarget.expectation[command.variableMap[Command::OPERAND_RESULT]] = statusTarget.register1[programIndex];
                    break;
            }
        }

        void calculate()
        {
            for(int programIndex=0;programIndex<MAX_PROGRAM_NUMBER;++programIndex)
            {
                this->program[programIndex].dealWithVariableTable(variable);
            }
            memset(status, 0, sizeof(status));
            status[0][0].possibility = 1.0;
            for(int commandExtendIndex=1;commandExtendIndex<=4*program[0].commandNumber;++commandExtendIndex)
            {
                calculate(status[commandExtendIndex-1][0], status[commandExtendIndex][0], 0, commandExtendIndex);
                status[commandExtendIndex][0].possibility = status[commandExtendIndex-1][0].possibility * 0.5;
            }
            for(int commandExtendIndex=1;commandExtendIndex<=4*program[1].commandNumber;++commandExtendIndex)
            {
                calculate(status[0][commandExtendIndex-1], status[0][commandExtendIndex], 1, commandExtendIndex);
                status[0][commandExtendIndex].possibility = status[0][commandExtendIndex-1].possibility * 0.5;
            }
            for(int commandExtendIndex2=1;commandExtendIndex2<=4*program[1].commandNumber;++commandExtendIndex2)
            {
                for(int commandExtendIndex1=1;commandExtendIndex1<=4*program[0].commandNumber;++commandExtendIndex1)
                {
                    Status s1,s2;
                    calculate(status[commandExtendIndex1-1][commandExtendIndex2], s1, 0, commandExtendIndex1);
                    calculate(status[commandExtendIndex1][commandExtendIndex2-1], s2, 1, commandExtendIndex2);
                    if(commandExtendIndex1 < 4 * program[0].commandNumber && commandExtendIndex2 < 4 * program[1].commandNumber)
                    {
                        merge(status[commandExtendIndex1][commandExtendIndex2], s1, s2, 0);
                    }
                    else if(commandExtendIndex2 < 4 * program[1].commandNumber)
                    {
                        merge(status[commandExtendIndex1][commandExtendIndex2], s1, s2, 1);
                    }
                    else if(commandExtendIndex1 < 4 * program[0].commandNumber)
                    {
                        merge(status[commandExtendIndex1][commandExtendIndex2], s1, s2, 2);
                    }
                    else
                    {
                        merge(status[commandExtendIndex1][commandExtendIndex2], s1, s2, 3);
                    }
                }
            }
        }

        void printResult()
        {
            for(int variableIndex=0;variableIndex<variable.variableNumber;++variableIndex)
            {
                this->variable.setValue(variableIndex, status[4 * program[0].commandNumber][4 * program[1].commandNumber].expectation[variableIndex]);
            }
            this->variable.sort();
            this->variable.printResult();
        }

        void printProcessor()
        {
            for(int programIndex=0;programIndex<MAX_PROGRAM_NUMBER;++programIndex)
            {
                program[programIndex].printProgram();
            }
        }

        void printProcessorDelt()
        {
            for(int programIndex=0;programIndex<MAX_PROGRAM_NUMBER;++programIndex)
            {
                program[programIndex].printProgramDelt();
            }
        }

    private:
        Program program[MAX_PROGRAM_NUMBER];
        Variable variable;
};

int main(int argc, char *argv[])
{
    int caseNumber;
    scanf("%d", &caseNumber);
    for(int caseIndex=0;caseIndex<caseNumber;++caseIndex)
    {
        if(caseIndex)
        {
            printf("\n");
        }
        Processor processor;
        processor.read();
        processor.calculate();
        processor.printResult();
    }
    return 0;
}
