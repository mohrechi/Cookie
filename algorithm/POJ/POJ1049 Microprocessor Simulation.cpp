#include <stdio.h>

int getDecimalFromHex(char hex)
{
    if(hex >= '0' && hex <= '9')
    {
        return hex - '0';
    }
    return hex - 'A' + 10;
}

int getDecimalFromDoubleHex(char hex1, char hex2)
{
    return getDecimalFromHex(hex1) * 16 + getDecimalFromHex(hex2);
}

char getHexFromDecimal(int decimal)
{
    if(decimal >= 0 && decimal <= 9)
    {
        return decimal + '0';
    }
    return decimal + 'A' - 10;
}

int main(int argc, char* argv[])
{
    char memory[300];
    char accumulatorA, accumulatorB;
    while(scanf("%s",memory),*memory != '8')
    {
        int instructionPointer = 0;
        bool runFlag = true;
        while(runFlag)
        {
            switch(memory[instructionPointer])
            {
                case '0':
                    accumulatorA = getDecimalFromHex(memory[getDecimalFromDoubleHex(memory[instructionPointer + 1], memory[instructionPointer + 2])]);
                    instructionPointer += 3;
                    break;
                case '1':
                    memory[getDecimalFromDoubleHex(memory[instructionPointer + 1], memory[instructionPointer + 2])] = getHexFromDecimal(accumulatorA);
                    instructionPointer += 3;
                    break;
                case '2':
                    accumulatorA ^= accumulatorB;
                    accumulatorB ^= accumulatorA;
                    accumulatorA ^= accumulatorB;
                    ++ instructionPointer;
                    break;
                case '3':
                    accumulatorB += accumulatorA;
                    accumulatorA = accumulatorB % 16;
                    accumulatorB = accumulatorB / 16;
                    ++ instructionPointer;
                    break;
                case '4':
                    accumulatorA = (accumulatorA + 1) % 16;
                    ++ instructionPointer;
                    break;
                case '5':
                    accumulatorA = (accumulatorA + 15) % 16;
                    ++ instructionPointer;
                    break;
                case '6':
                    if(accumulatorA == 0)
                    {
                        instructionPointer = getDecimalFromDoubleHex(memory[instructionPointer + 1], memory[instructionPointer + 2]);
                    }
                    else
                    {
                        instructionPointer += 3;
                    }
                    break;
                case '7':
                    instructionPointer = getDecimalFromDoubleHex(memory[instructionPointer + 1], memory[instructionPointer + 2]);
                    break;
                case '8':
                    runFlag = false;
                    break;
            }
        }
        printf("%s\n",memory);
    }
    return 0;
}
