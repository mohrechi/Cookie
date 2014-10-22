#include <cstdio>
#include <cstring>

//#define DEBUG

#ifdef DEBUG
    #define BigInteger_Test
#endif
inline int min(int x, int y)
{
    return x<y?x:y;
}

inline int max(int x, int y)
{
    return x>y?x:y;
}

class BigInteger
{
    public:
        enum Relation
        {
            GREATER, EQUAL, LESS
        };

        BigInteger()
        {
            this->positive = true;
            this->storageTop = 1;
            this->storage[0] = 0;
        }

        BigInteger(int number)
        {
            this->transferFromInteger((long long)number);
        }

        BigInteger(long number)
        {
            this->transferFromInteger((long long)number);
        }

        BigInteger(long long number)
        {
            this->transferFromInteger(number);
        }

        #ifdef BigInteger_Test
        BigInteger(const char *str)
        {
            int length;
            if(*str == '+')
            {
                this->positive = true;
                length = strlen(str) - 1;
            }
            else if(*str == '-')
            {
                this->positive = false;
                length = strlen(str) - 1;
            }
            else
            {
                this->positive = true;
                length = strlen(str);
            }
            this->storageTop = 1;
            this->storage[0] = 0;
            for(int i=0;i<length;++i)
            {
                this->multiply10();
                *this = this->add(BigInteger((int)(str[i] - '0')));
            }
        }
        void multiply10()
        {
            int carry = 0;
            for(int i=0;i<this->storageTop;++i)
            {
                this->storage[i] = this->storage[i] * 10 + carry;
                if(this->storage[i] >= NUMBERPERSTORAGE)
                {
                    carry = this->storage[i] / NUMBERPERSTORAGE;
                    this->storage[i] %= NUMBERPERSTORAGE;
                }
                else
                {
                    carry = 0;
                }
            }
            if(carry)
            {
                this->storage[this->storageTop] = carry;
                this->storageTop++;
            }
        }
        #endif

        void transferFromInteger(long long number)
        {
            if(number >= 0)
            {
                this->positive = true;
            }
            else
            {
                this->positive = false;
                number = - number;
            }
            this->storageTop = 0;
            for(int i=0;i<MAXSTORAGE;++i)
            {
                this->storage[i] = number % NUMBERPERSTORAGE;
                this->storageTop ++;
                number /= NUMBERPERSTORAGE;
                if(number == 0)
                {
                    break;
                }
            }
        }

        const Relation compare(const BigInteger &number) const
        {
            if(this->positive > number.positive)
            {
                return GREATER;
            }
            else if(this->positive < number.positive)
            {
                return LESS;
            }
            if(this->positive)
            {
                if(this->storageTop > number.storageTop)
                {
                    return GREATER;
                }
                else if(this->storageTop < number.storageTop)
                {
                    return LESS;
                }
                for(int i=this->storageTop-1;i>=0;--i)
                {
                    if(this->storage[i] > number.storage[i])
                    {
                        return GREATER;
                    }
                    else if(this->storage[i] < number.storage[i])
                    {
                        return LESS;
                    }
                }
            }
            else
            {
                if(this->storageTop < number.storageTop)
                {
                    return GREATER;
                }
                else if(this->storageTop > number.storageTop)
                {
                    return LESS;
                }
                for(int i=this->storageTop-1;i>=0;--i)
                {
                    if(this->storage[i] < number.storage[i])
                    {
                        return GREATER;
                    }
                    else if(this->storage[i] > number.storage[i])
                    {
                        return LESS;
                    }
                }
            }
            return EQUAL;
        }

        const Relation compareWithoutSign(const BigInteger &number) const
        {
            if(this->storageTop > number.storageTop)
            {
                return GREATER;
            }
            else if(this->storageTop < number.storageTop)
            {
                return LESS;
            }
            for(int i=this->storageTop-1;i>=0;--i)
            {
                if(this->storage[i] > number.storage[i])
                {
                    return GREATER;
                }
                else if(this->storage[i] < number.storage[i])
                {
                    return LESS;
                }
            }
        }

        const BigInteger copy() const
        {
            BigInteger *result = new BigInteger();
            result->positive = this->positive;
            result->storageTop = this->storageTop;
            for(int i=0;i<this->storageTop;++i)
            {
                result->storage[i] = this->storage[i];
            }
            return *result;
        }

        const BigInteger contrary() const
        {
            BigInteger *result = new BigInteger();
            result->positive = !this->positive;
            result->storageTop = this->storageTop;
            for(int i=0;i<this->storageTop;++i)
            {
                result->storage[i] = this->storage[i];
            }
            return *result;
        }

        const BigInteger add(const BigInteger &number) const
        {
            if(this->positive != number.positive)
            {
                return this->substract(number.contrary());
            }
            BigInteger *result = new BigInteger();
            result->positive = this->positive;
            result->storageTop = max(this->storageTop, number.storageTop);
            int carry = 0;
            for(int i=0;i<result->storageTop;++i)
            {
                result->storage[i] = this->getStorageByIndex(i) + number.getStorageByIndex(i) + carry;
                if(result->storage[i] >= NUMBERPERSTORAGE)
                {
                    result->storage[i] -= NUMBERPERSTORAGE;
                    carry = 1;
                }
                else
                {
                    carry = 0;
                }
            }
            if(carry)
            {
                result->storage[result->storageTop] = 1;
                result->storageTop ++;
            }
            return *result;
        }

        const BigInteger substract(const BigInteger &number) const
        {
            if(this->positive != number.positive)
            {
                return this->add(number.contrary());
            }
            if(this->compareWithoutSign(number) == LESS)
            {
                return number.substract(this->copy()).contrary();
            }
            BigInteger *result = new BigInteger();
            result->positive = this->positive;
            result->storageTop = max(this->storageTop, number.storageTop);
            int borrow = 0;
            for(int i=0;i<result->storageTop;++i)
            {
                result->storage[i] = this->getStorageByIndex(i) - number.getStorageByIndex(i) - borrow;
                if(result->storage[i] < 0)
                {
                    result->storage[i] += NUMBERPERSTORAGE;
                    borrow = 1;
                }
                else
                {
                    borrow = 0;
                }
            }
            while(result->storage[result->storageTop] == 0 && result->storageTop > 1)
            {
                result->storageTop --;
            }
            return *result;
        }

        void printNumberWithZero(int number) const
        {
            int temp = number;
            int count = 0;
            while(temp>0)
            {
                count ++;
                temp /= 10;
            }
            count = BITSPERSTORAGE - count;
            for(int i=0;i<count;++i)
            {
                printf("0");
            }
            printf("%d",number);
        }

        void print() const
        {
            if(this->storageTop != 0 || this->storage[0] != 0)
            {
                if(! this->positive)
                {
                    printf("-");
                }
                printf("%d",this->storage[this->storageTop - 1]);
                for(int i=this->storageTop-2;i>=0;--i)
                {
                    printNumberWithZero(this->storage[i]);
                }
            }
            else
            {
                printf("0");
            }
        }

        void printLine() const
        {
            this->print();
            printf("\n");
        }

        #ifdef BigInteger_Test
        void printDetail() const
        {
            printf("BigInteger Detail: ");
            if(this->positive)
            {
                printf("+");
            }
            else
            {
                printf("-");
            }
            printf(" %d ", this->storageTop);
            for(int i=0;i<this->storageTop;++i)
            {
                printf("%d ",this->storage[i]);
            }
            printf("\n");
        }
        #endif

        friend bool operator > (const BigInteger &a, const BigInteger &b)
        {
            return a.compare(b) == GREATER;
        }
        friend bool operator >= (const BigInteger &a, const BigInteger &b)
        {
            Relation r = a.compare(b);
            return r == GREATER || r == EQUAL;
        }
        friend bool operator == (const BigInteger &a, const BigInteger &b)
        {
            return a.compare(b) == EQUAL;
        }
        friend bool operator <= (const BigInteger &a, const BigInteger &b)
        {
            Relation r = a.compare(b);
            return r == LESS || r == EQUAL;
        }
        friend bool operator < (const BigInteger &a, const BigInteger &b)
        {
            return a.compare(b) == LESS;
        }
        friend const BigInteger operator + (const BigInteger &a, const BigInteger &b)
        {
            return a.add(b);
        }
        friend const BigInteger operator - (const BigInteger &a, const BigInteger &b)
        {
            return a.substract(b);
        }
    private:
        static const int MAXSTORAGE = 125;
        static const int NUMBERPERSTORAGE = 10000;
        static const int BITSPERSTORAGE = 4;
        int storage[MAXSTORAGE];
        int storageTop;
        bool positive;

        int getStorageByIndex(int index) const
        {
            if(index >= this->storageTop || index >= MAXSTORAGE)
            {
                return 0;
            }
            return this->storage[index];
        }
};

static const int MAXRING = 1005;

int main(int argc, char* argv[])
{
    int ringNumber, temp;
    bool ring[MAXRING];
    BigInteger prevF(0);
    BigInteger prevG(0);
    BigInteger currF(0);
    BigInteger currG(0);
    BigInteger pow2(0);
    while(~scanf("%d",&ringNumber))
    {
        for(int i=1;i<=ringNumber;++i)
        {
            scanf("%d",&ring[i]);
        }
        prevF.transferFromInteger(0);
        prevG.transferFromInteger(0);
        pow2.transferFromInteger(1);
        for(int i=1;i<=ringNumber;++i)
        {
            if(ring[i])
            {
                currF = prevG + pow2;
                currG = prevF;
            }
            else
            {
                currF = prevF;
                currG = prevG + pow2;
            }
            prevF = currF;
            prevG = currG;
            pow2 = pow2 + pow2;
        }
        currF.printLine();
    }
    return 0;
}
