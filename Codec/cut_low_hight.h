#ifndef CUT_LOW_HIGHT
#define CUT_LOW_HIGHT

typedef unsigned int uint;
typedef double udouble;

struct cut_struct {
    udouble low;
    udouble hight;

    bool isOwn_cut(udouble code)
    {
        return (code >= low && code <= hight);
    }
};

typedef struct cut_struct cut;

class symbol_and_probability
{
private:
    symbol_and_probability(){}
    char symbol;
    udouble probability;

public:
    symbol_and_probability(char s, udouble p)
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

    bool operator<(const symbol_and_probability &right_value) const
    {
        return (this->getProbability() > right_value.getProbability());
    }
};

#endif // CUT_LOW_HIGHT

