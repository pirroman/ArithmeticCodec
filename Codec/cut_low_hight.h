#ifndef CUT_LOW_HIGHT
#define CUT_LOW_HIGHT

typedef unsigned int uint;
typedef unsigned double udouble;

struct cut_struct {
    udouble low;
    udouble hight;
};

typedef struct cut_struct cut;

class symbol_and_probability
{
private:
    cut(){}
    char symbol;
    udouble probability;

public:
    cut(char s, udouble p)
    {
        symbol      = s;
        probability = p;
    }

    char getSymbol() const
    {
        return symbol;
    }

    udouble getProbability() const
    {
        return probability;
    }

    bool operator<(const cut &right_value) const
    {
        return this->probability > right_value.probability;
    }
};

#endif // CUT_LOW_HIGHT

